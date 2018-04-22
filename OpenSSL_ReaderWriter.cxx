/*
 * OpenSSL_ReaderWriter.cpp
 *
 *  Created on: 4 Sep. 2017
 *      Author: robert
 */

#include "OpenSSL_ReaderWriter.h"
#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <openssl/rand.h>
#include <iostream>
#include <cstring>
#include <assert.h>
#include <iostream>

#include <dds/pub/ddspub.hpp>
#include <rti/util/util.hpp> // for sleep()

#include "test.hpp"

#include "test.hpp"





void	Crypto::InitPSK(void)
{
	//normally you would read a PEM file here - but quick and dirty FTW
	psk=std::vector<uint8_t>(32,0x12);
}

void	Crypto::InitSessionKey(void)
{
   std::cout << "InitSessionKey" << std::endl;
	//initialise with a random session key
	sessionKey = std::vector<uint8_t>(32);
	RAND_pseudo_bytes(sessionKey.data(), sessionKey.size());
}

void Crypto::ResetSessionKey(void) 
{
  std::cout << "ResetSessionKey" << std::endl;
	sessionKey.clear();
}


void Crypto::SetWrappedSessionKey(MyType& frame)
{
  std::cout << "SetWrappedSessionKey" << std::endl;
  	assert(sessionKey.size()==32);
	evp_cipher_ctx_st * ctx = EVP_CIPHER_CTX_new ();
	int rc = EVP_EncryptInit_ex (ctx, EVP_aes_256_cbc (), NULL, psk.data(), frame.nonce().data());
	if (rc != 1)
	{
		std::cerr << ("EVP_EncryptInit_ex failed") << std::endl;
		exit (-1);
	}

	rc = EVP_CIPHER_CTX_set_padding (ctx, 1);
	if (rc != 1)
	{
		std::cerr << ("EVP_CIPHER_CTX_set_padding failed") << std::endl;
		exit (-1);
	}

	// Cipher text expands upto BLOCK_SIZE
	int out_len1 = (int) 1024 ;
	//set aside 1024 bytes
	frame.wrapped_key().resize(1024);

	rc = EVP_EncryptUpdate (ctx, frame.wrapped_key().data(), &out_len1,  sessionKey.data(), (int) sessionKey.size());
	if (rc != 1)
	{
		std::cerr << "EVP_EncryptUpdate failed" << std::endl;
		exit (-1);
	}

	int out_len2 = (int) 1024 - out_len1;
	rc = EVP_EncryptFinal_ex (ctx, frame.wrapped_key().data() + out_len1, &out_len2);
	if (rc != 1)
	{
		std::cerr << "EVP_EncryptFinal_ex failed" << std::endl;
		exit (-1);
	}

	// Set cipher text size now that we know it
	frame.wrapped_key().resize(out_len1 + out_len2);
	EVP_CIPHER_CTX_free (ctx);
}


void  Crypto::GetWrappedSessionKey (const MyType& frame) //decrypt a block
{
std::cout << "GetWrappedSessionKey" << std::endl;


	auto ctx = EVP_CIPHER_CTX_new ();

	int rc = EVP_DecryptInit_ex (ctx, EVP_aes_256_cbc (), NULL, psk.data(), frame.nonce().data());


	if (rc != 1)
	{
		std::cerr << "EVP_DecryptInit_ex failed" << std::endl;
		exit (-1);
	}

	rc = EVP_CIPHER_CTX_set_padding (ctx, 1);
	if (rc != 1)
	{
		std::cerr << ("EVP_CIPHER_CTX_set_padding failed") << std::endl;
		exit (-1);
	}

	// Recovered text contracts upto BLOCK_SIZE
	sessionKey.resize(1024); //set asside 1024 bytes
	int out_len1 = (int) 1024;

	rc = EVP_DecryptUpdate (ctx,  sessionKey.data(), &out_len1,  frame.wrapped_key().data(),  frame.wrapped_key().size());
	if (rc != 1)
	{
		std::cerr << "EVP_DecryptUpdate failed" << std::endl;
		exit (-1);
	}

	int out_len2 = (int) 1024 - out_len1;
	rc = EVP_DecryptFinal_ex (ctx, sessionKey.data() + out_len1, &out_len2);
	if (rc != 1)
	{
		std::cerr << "EVP_DecryptFinal_ex failed" << std::endl;
		ERR_print_errors_fp(stderr);
		exit (-1);
	}

	// Set recovered text size now that we know it
	sessionKey.resize (out_len1 + out_len2);


}


MyType  Crypto::encrypt(const MyType& ptext) //encrypt a block
{

  std::cout << "encrypt" << std::endl;
	evp_cipher_ctx_st * ctx = EVP_CIPHER_CTX_new ();
	std::vector<uint8_t> iv(16);
	RAND_pseudo_bytes(iv.data(), iv.size());
	MyType ctext;
	ctext.nonce(iv);
	ctext.ctr()=ptext.ctr();

	if(sessionKey.size()!=32)
	{
	  InitSessionKey();
	  SetWrappedSessionKey(ctext);
	}
	
	int rc = EVP_EncryptInit_ex (ctx, EVP_aes_256_cbc (), NULL, sessionKey.data(), iv.data());
	if (rc != 1)
	{
		std::cerr << ("EVP_EncryptInit_ex failed") << std::endl;
		exit (-1);
	}

	rc = EVP_CIPHER_CTX_set_padding (ctx, 1);
	if (rc != 1)
	{
		std::cerr << ("EVP_CIPHER_CTX_set_padding failed") << std::endl;
		exit (-1);
	}

	
	// Cipher text expands upto BLOCK_SIZE
	int out_len1 = (int) 1024 ;
	//set aside 1024 bytes
	ctext.data().resize(1024);

	rc = EVP_EncryptUpdate (ctx, ctext.data().data(), &out_len1,  ptext.data().data(), (int) ptext.data().size());
	if (rc != 1)
	{
		std::cerr << "EVP_EncryptUpdate failed" << std::endl;
		exit (-1);
	}

	int out_len2 = (int) 1024 - out_len1;
	rc = EVP_EncryptFinal_ex (ctx, ctext.data().data() + out_len1, &out_len2);
	if (rc != 1)
	{
		std::cerr << "EVP_EncryptFinal_ex failed" << std::endl;
		exit (-1);
	}

	// Set cipher text size now that we know it
	ctext.data().resize(out_len1 + out_len2);

	EVP_CIPHER_CTX_free (ctx);
	return ctext;
}

Crypto::Crypto ()
{

	EVP_add_cipher (EVP_aes_256_cbc ());
	InitPSK();
}

Crypto::~Crypto ()
{
}


MyType  Crypto::decrypt (const MyType& ctext) //decrypt a block
{
std::cout << "decrypt" << std::endl;
	if(ctext.wrapped_key().size()>=32) //we have a wrapped key
	{
	    GetWrappedSessionKey(ctext);   //unwrap it and set it up
	}
	
	
	auto ctx = EVP_CIPHER_CTX_new ();
	
	MyType rtext;
	rtext.ctr()=ctext.ctr();
	rtext.data().resize(1024); //set asside 1024 bytes


	if (sessionKey.size()!=32)
	{
	  std::cout << "sessionKey.size()" << sessionKey.size() << std::endl;
	  return rtext;			//we have no session key - just return without decrypting anything
	}
	
	int rc = EVP_DecryptInit_ex (ctx, EVP_aes_256_cbc (), NULL, sessionKey.data(), ctext.nonce().data());


	if (rc != 1)
	{
		std::cerr << "EVP_DecryptInit_ex failed" << std::endl;
		exit (-1);
	}

	rc = EVP_CIPHER_CTX_set_padding (ctx, 1);
	if (rc != 1)
	{
		std::cerr << ("EVP_CIPHER_CTX_set_padding failed") << std::endl;
		exit (-1);
	}

	// Recovered text contracts upto BLOCK_SIZE
	int out_len1 = (int) 1024;

	rc = EVP_DecryptUpdate (ctx,  rtext.data ().data(), &out_len1,  ctext.data ().data(),  ctext.data().size());
	if (rc != 1)
	{
		std::cerr << "EVP_DecryptUpdate failed" << std::endl;
		exit (-1);
	}

	int out_len2 = (int) 1024 - out_len1;
	rc = EVP_DecryptFinal_ex (ctx, rtext.data ().data() + out_len1, &out_len2);
	if (rc != 1)
	{
		std::cerr << "EVP_DecryptFinal_ex failed" << std::endl;
		ERR_print_errors_fp(stderr);
		exit (-1);
	}

	// Set recovered text size now that we know it
	rtext.data().resize (out_len1 + out_len2);


	return rtext;
}




