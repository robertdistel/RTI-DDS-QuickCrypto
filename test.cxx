

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from test.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#include <iosfwd>
#include <iomanip>

#include "rti/topic/cdr/Serialization.hpp"

#include "test.hpp"
#include "testPlugin.hpp"

#include <rti/util/ostream_operators.hpp>

// ---- MyType: 

MyType::MyType() :
    m_ctr_ (0)  {
}   

MyType::MyType (
    int32_t ctr,
    const std::vector<uint8_t>& nonce,
    const std::vector<uint8_t>& wrapped_key,
    const std::vector<uint8_t>& data)
    :
        m_ctr_( ctr ),
        m_nonce_( nonce ),
        m_wrapped_key_( wrapped_key ),
        m_data_( data ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
MyType::MyType(MyType&& other_) OMG_NOEXCEPT  :m_ctr_ (std::move(other_.m_ctr_))
,
m_nonce_ (std::move(other_.m_nonce_))
,
m_wrapped_key_ (std::move(other_.m_wrapped_key_))
,
m_data_ (std::move(other_.m_data_))
{
} 

MyType& MyType::operator=(MyType&&  other_) OMG_NOEXCEPT {
    MyType tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void MyType::swap(MyType& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_ctr_, other_.m_ctr_);
    swap(m_nonce_, other_.m_nonce_);
    swap(m_wrapped_key_, other_.m_wrapped_key_);
    swap(m_data_, other_.m_data_);
}  

bool MyType::operator == (const MyType& other_) const {
    if (m_ctr_ != other_.m_ctr_) {
        return false;
    }
    if (m_nonce_ != other_.m_nonce_) {
        return false;
    }
    if (m_wrapped_key_ != other_.m_wrapped_key_) {
        return false;
    }
    if (m_data_ != other_.m_data_) {
        return false;
    }
    return true;
}
bool MyType::operator != (const MyType& other_) const {
    return !this->operator ==(other_);
}

// --- Getters and Setters: -------------------------------------------------
int32_t& MyType::ctr() OMG_NOEXCEPT {
    return m_ctr_;
}

const int32_t& MyType::ctr() const OMG_NOEXCEPT {
    return m_ctr_;
}

void MyType::ctr(int32_t value) {
    m_ctr_ = value;
}

std::vector<uint8_t>& MyType::nonce() OMG_NOEXCEPT {
    return m_nonce_;
}

const std::vector<uint8_t>& MyType::nonce() const OMG_NOEXCEPT {
    return m_nonce_;
}

void MyType::nonce(const std::vector<uint8_t>& value) {
    m_nonce_ = value;
}

std::vector<uint8_t>& MyType::wrapped_key() OMG_NOEXCEPT {
    return m_wrapped_key_;
}

const std::vector<uint8_t>& MyType::wrapped_key() const OMG_NOEXCEPT {
    return m_wrapped_key_;
}

void MyType::wrapped_key(const std::vector<uint8_t>& value) {
    m_wrapped_key_ = value;
}

std::vector<uint8_t>& MyType::data() OMG_NOEXCEPT {
    return m_data_;
}

const std::vector<uint8_t>& MyType::data() const OMG_NOEXCEPT {
    return m_data_;
}

void MyType::data(const std::vector<uint8_t>& value) {
    m_data_ = value;
}

std::ostream& operator << (std::ostream& o,const MyType& sample)
{
    rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "ctr: " << sample.ctr()<<", ";
    o << "nonce: " << sample.nonce()<<", ";
    o << "wrapped_key: " << sample.wrapped_key()<<", ";
    o << "data: " << sample.data() ;
    o <<"]";
    return o;
}

// --- Type traits: -------------------------------------------------

namespace rti { 
    namespace topic {

        template<>
        struct native_type_code<MyType> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode MyType_g_tc_nonce_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE((16),NULL);
                static DDS_TypeCode MyType_g_tc_wrapped_key_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE((48),NULL);
                static DDS_TypeCode MyType_g_tc_data_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE((1024),NULL);
                static DDS_TypeCode_Member MyType_g_tc_members[4]=
                {

                    {
                        (char *)"ctr",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_KEY_MEMBER , /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"nonce",/* Member name */
                        {
                            1,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"wrapped_key",/* Member name */
                        {
                            2,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"data",/* Member name */
                        {
                            3,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode MyType_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"MyType", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        4, /* Number of members */
                        MyType_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for MyType*/

                if (is_initialized) {
                    return &MyType_g_tc;
                }

                MyType_g_tc_nonce_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;

                MyType_g_tc_wrapped_key_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;

                MyType_g_tc_data_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;

                MyType_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

                MyType_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)& MyType_g_tc_nonce_sequence;
                MyType_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)& MyType_g_tc_wrapped_key_sequence;
                MyType_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)& MyType_g_tc_data_sequence;

                is_initialized = RTI_TRUE;

                return &MyType_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<MyType>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<MyType>::get())));
        }

    }
}  

namespace dds { 
    namespace topic {
        void topic_type_support<MyType>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                MyTypePlugin_new,
                MyTypePlugin_delete);
        }

        std::vector<char>& topic_type_support<MyType>::to_cdr_buffer(
            std::vector<char>& buffer, const MyType& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = MyTypePlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = MyTypePlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<MyType>::from_cdr_buffer(MyType& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = MyTypePlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create MyType from cdr buffer");
        }

        void topic_type_support<MyType>::reset_sample(MyType& sample) 
        {
            rti::topic::reset_sample(sample.ctr());
            rti::topic::reset_sample(sample.nonce());
            rti::topic::reset_sample(sample.wrapped_key());
            rti::topic::reset_sample(sample.data());
        }

        void topic_type_support<MyType>::allocate_sample(MyType& sample, int, int) 
        {
            rti::topic::allocate_sample(sample.nonce(),  16, -1);
            rti::topic::allocate_sample(sample.wrapped_key(),  48, -1);
            rti::topic::allocate_sample(sample.data(),  1024, -1);
        }

    }
}  

