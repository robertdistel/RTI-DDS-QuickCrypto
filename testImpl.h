

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from testImpl.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef testImpl_1147917629_h
#define testImpl_1147917629_h

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_c_h
#include "ndds/ndds_c.h"
#endif
#else
#include "ndds_standalone_type.h"
#endif

extern const char *MyType_cTYPENAME;

typedef struct MyType_c {

    DDS_Long   ctr ;
    struct    DDS_OctetSeq  nonce ;
    struct    DDS_OctetSeq  wrapped_key ;
    struct    DDS_OctetSeq  data ;

    MyType_c() {}

} MyType_c ;
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

NDDSUSERDllExport DDS_TypeCode* MyType_c_get_typecode(void); /* Type code */

DDS_SEQUENCE(MyType_cSeq, MyType_c);

NDDSUSERDllExport
RTIBool MyType_c_initialize(
    MyType_c* self);

NDDSUSERDllExport
RTIBool MyType_c_initialize_ex(
    MyType_c* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool MyType_c_initialize_w_params(
    MyType_c* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
void MyType_c_finalize(
    MyType_c* self);

NDDSUSERDllExport
void MyType_c_finalize_ex(
    MyType_c* self,RTIBool deletePointers);

NDDSUSERDllExport
void MyType_c_finalize_w_params(
    MyType_c* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void MyType_c_finalize_optional_members(
    MyType_c* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool MyType_c_copy(
    MyType_c* dst,
    const MyType_c* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* testImpl */

