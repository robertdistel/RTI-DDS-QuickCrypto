

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from testImpl.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_c_h
#include "ndds/ndds_c.h"
#endif

#ifndef cdr_type_h
#include "cdr/cdr_type.h"
#endif    

#ifndef osapi_heap_h
#include "osapi/osapi_heap.h" 
#endif
#else
#include "ndds_standalone_type.h"
#endif

#include "testImpl.h"

/* ========================================================================= */
const char *MyType_cTYPENAME = "MyType";

DDS_TypeCode* MyType_c_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode MyType_c_g_tc_nonce_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE((16),NULL);
    static DDS_TypeCode MyType_c_g_tc_wrapped_key_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE((48),NULL);
    static DDS_TypeCode MyType_c_g_tc_data_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE((1024),NULL);
    static DDS_TypeCode_Member MyType_c_g_tc_members[4]=
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

    static DDS_TypeCode MyType_c_g_tc =
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
            MyType_c_g_tc_members, /* Members */
            DDS_VM_NONE  /* Ignored */         
        }}; /* Type code for MyType_c*/

    if (is_initialized) {
        return &MyType_c_g_tc;
    }

    MyType_c_g_tc_nonce_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;

    MyType_c_g_tc_wrapped_key_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;

    MyType_c_g_tc_data_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;

    MyType_c_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

    MyType_c_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)& MyType_c_g_tc_nonce_sequence;
    MyType_c_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)& MyType_c_g_tc_wrapped_key_sequence;
    MyType_c_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)& MyType_c_g_tc_data_sequence;

    is_initialized = RTI_TRUE;

    return &MyType_c_g_tc;
}

RTIBool MyType_c_initialize(
    MyType_c* sample) {
    return MyType_c_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool MyType_c_initialize_ex(
    MyType_c* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return MyType_c_initialize_w_params(
        sample,&allocParams);

}

RTIBool MyType_c_initialize_w_params(
    MyType_c* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    void* buffer = NULL;
    if (buffer) {} /* To avoid warnings */

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initLong(&sample->ctr)) {
        return RTI_FALSE;
    }

    if (allocParams->allocate_memory) {
        DDS_OctetSeq_initialize(&sample->nonce  );
        DDS_OctetSeq_set_absolute_maximum(&sample->nonce , (16));
        if (!DDS_OctetSeq_set_maximum(&sample->nonce , (16))) {
            return RTI_FALSE;
        }
    } else { 
        DDS_OctetSeq_set_length(&sample->nonce, 0);
    }
    if (allocParams->allocate_memory) {
        DDS_OctetSeq_initialize(&sample->wrapped_key  );
        DDS_OctetSeq_set_absolute_maximum(&sample->wrapped_key , (48));
        if (!DDS_OctetSeq_set_maximum(&sample->wrapped_key , (48))) {
            return RTI_FALSE;
        }
    } else { 
        DDS_OctetSeq_set_length(&sample->wrapped_key, 0);
    }
    if (allocParams->allocate_memory) {
        DDS_OctetSeq_initialize(&sample->data  );
        DDS_OctetSeq_set_absolute_maximum(&sample->data , (1024));
        if (!DDS_OctetSeq_set_maximum(&sample->data , (1024))) {
            return RTI_FALSE;
        }
    } else { 
        DDS_OctetSeq_set_length(&sample->data, 0);
    }
    return RTI_TRUE;
}

void MyType_c_finalize(
    MyType_c* sample)
{

    MyType_c_finalize_ex(sample,RTI_TRUE);
}

void MyType_c_finalize_ex(
    MyType_c* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    MyType_c_finalize_w_params(
        sample,&deallocParams);
}

void MyType_c_finalize_w_params(
    MyType_c* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

    DDS_OctetSeq_finalize(&sample->nonce);

    DDS_OctetSeq_finalize(&sample->wrapped_key);

    DDS_OctetSeq_finalize(&sample->data);

}

void MyType_c_finalize_optional_members(
    MyType_c* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool MyType_c_copy(
    MyType_c* dst,
    const MyType_c* src)
{

    if (dst == NULL || src == NULL) {
        return RTI_FALSE;
    }

    if (!RTICdrType_copyLong (
        &dst->ctr, &src->ctr)) { 
        return RTI_FALSE;
    }
    if (!DDS_OctetSeq_copy(&dst->nonce ,
    &src->nonce )) {
        return RTI_FALSE;
    }
    if (!DDS_OctetSeq_copy(&dst->wrapped_key ,
    &src->wrapped_key )) {
        return RTI_FALSE;
    }
    if (!DDS_OctetSeq_copy(&dst->data ,
    &src->data )) {
        return RTI_FALSE;
    }

    return RTI_TRUE;

}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'MyType_c' sequence class.
*/
#define T MyType_c
#define TSeq MyType_cSeq

#define T_initialize_w_params MyType_c_initialize_w_params

#define T_finalize_w_params   MyType_c_finalize_w_params
#define T_copy       MyType_c_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params

#undef T_initialize_w_params

#undef TSeq
#undef T

