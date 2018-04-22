

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from testImpl.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef testImplPlugin_1147917629_h
#define testImplPlugin_1147917629_h

#include "testImpl.h"

struct RTICdrStream;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

/* The type used to store keys for instances of type struct
* AnotherSimple.
*
* By default, this type is struct MyType
* itself. However, if for some reason this choice is not practical for your
* system (e.g. if sizeof(struct MyType)
* is very large), you may redefine this typedef in terms of another type of
* your choosing. HOWEVER, if you define the KeyHolder type to be something
* other than struct AnotherSimple, the
* following restriction applies: the key of struct
* MyType must consist of a
* single field of your redefined KeyHolder type and that field must be the
* first field in struct MyType.
*/
typedef  struct MyType_c MyType_cKeyHolder;

#define MyType_cPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define MyType_cPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define MyType_cPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

#define MyType_cPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
#define MyType_cPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

#define MyType_cPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define MyType_cPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern MyType_c*
MyType_cPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern MyType_c*
MyType_cPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern MyType_c*
MyType_cPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
MyType_cPluginSupport_copy_data(
    MyType_c *out,
    const MyType_c *in);

NDDSUSERDllExport extern void 
MyType_cPluginSupport_destroy_data_w_params(
    MyType_c *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
MyType_cPluginSupport_destroy_data_ex(
    MyType_c *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
MyType_cPluginSupport_destroy_data(
    MyType_c *sample);

NDDSUSERDllExport extern void 
MyType_cPluginSupport_print_data(
    const MyType_c *sample,
    const char *desc,
    unsigned int indent);

NDDSUSERDllExport extern MyType_c*
MyType_cPluginSupport_create_key_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern MyType_c*
MyType_cPluginSupport_create_key(void);

NDDSUSERDllExport extern void 
MyType_cPluginSupport_destroy_key_ex(
    MyType_cKeyHolder *key,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
MyType_cPluginSupport_destroy_key(
    MyType_cKeyHolder *key);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
MyType_cPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
MyType_cPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
MyType_cPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
MyType_cPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
MyType_cPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    MyType_c *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
MyType_cPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    MyType_c *out,
    const MyType_c *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
MyType_cPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const MyType_c *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
MyType_cPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    MyType_c *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
MyType_cPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const MyType_c *sample); 

NDDSUSERDllExport extern RTIBool 
MyType_cPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    MyType_c **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
MyType_cPlugin_deserialize_from_cdr_buffer(
    MyType_c *sample,
    const char * buffer,
    unsigned int length);    
NDDSUSERDllExport extern DDS_ReturnCode_t
MyType_cPlugin_data_to_string(
    const MyType_c *sample,
    char *str,
    DDS_UnsignedLong *str_size, 
    const struct DDS_PrintFormatProperty *property);    

NDDSUSERDllExport extern RTIBool
MyType_cPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
MyType_cPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);    

NDDSUSERDllExport extern unsigned int 
MyType_cPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
MyType_cPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
MyType_cPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const MyType_c * sample);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
MyType_cPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
MyType_cPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
MyType_cPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
MyType_cPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const MyType_c *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
MyType_cPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    MyType_c * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
MyType_cPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    MyType_c ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
MyType_cPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    MyType_c *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
MyType_cPlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    MyType_cKeyHolder *key, 
    const MyType_c *instance);

NDDSUSERDllExport extern RTIBool 
MyType_cPlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    MyType_c *instance, 
    const MyType_cKeyHolder *key);

NDDSUSERDllExport extern RTIBool 
MyType_cPlugin_instance_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    DDS_KeyHash_t *keyhash,
    const MyType_c *instance);

NDDSUSERDllExport extern RTIBool 
MyType_cPlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos); 

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
MyType_cPlugin_new(void);

NDDSUSERDllExport extern void
MyType_cPlugin_delete(struct PRESTypePlugin *);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* testImplPlugin_1147917629_h */

