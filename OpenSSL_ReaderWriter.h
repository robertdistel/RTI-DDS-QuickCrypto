/*
 * OpenSSL_ReaderWriter.h
 *
 *  Created on: 4 Sep. 2017
 *      Author: robert
 */

#ifndef OPENSSL_READERWRITER_H_
#define OPENSSL_READERWRITER_H_

#include <string>
#include <memory>
#include <vector>
class MyType;




class Crypto
{

public:
  void MakeNewSessionKey();  		//create a session key
  void SetWrappedSessionKey(MyType& frame);			//make sure the next packet has a wrapped session key embedded - uses the same nonce - different key
  void GetWrappedSessionKey(const MyType& frame);		//unwrap the session key in the fram if it exists and set it up

  void ResetSessionKey();
  
  
  MyType  encrypt (const MyType& frame);
  MyType  decrypt (const MyType& frame);
  Crypto ();
  ~Crypto ();
 
private:
  void InitPSK();
  void InitSessionKey();

  std::vector<uint8_t> sessionKey;
  std::vector<uint8_t> psk;

};





#endif /* OPENSSL_READERWRITER_H_ */
