/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#include <MI.h>
#include "module.h"
#include "MongoDB_Server_Class_Provider.h"
#include "MongoDB_Server_Database_Class_Provider.h"
#include "MongoDB_Server_Statistics_Class_Provider.h"

using namespace mi;

MI_EXTERN_C void MI_CALL MongoDB_Server_Load(
    MongoDB_Server_Self** self,
    MI_Module_Self* selfModule,
    MI_Context* context)
{
    MI_Result r = MI_RESULT_OK;
    Context ctx(context, &r);
    MongoDB_Server_Class_Provider* prov = new MongoDB_Server_Class_Provider((Module*)selfModule);

    prov->Load(ctx);
    if (MI_RESULT_OK != r)
    {
        delete prov;
        MI_Context_PostResult(context, r);
        return;
    }
    *self = (MongoDB_Server_Self*)prov;
    MI_Context_PostResult(context, MI_RESULT_OK);
}

MI_EXTERN_C void MI_CALL MongoDB_Server_Unload(
    MongoDB_Server_Self* self,
    MI_Context* context)
{
    MI_Result r = MI_RESULT_OK;
    Context ctx(context, &r);
    MongoDB_Server_Class_Provider* prov = (MongoDB_Server_Class_Provider*)self;

    prov->Unload(ctx);
    delete ((MongoDB_Server_Class_Provider*)self);
    MI_Context_PostResult(context, r);
}

MI_EXTERN_C void MI_CALL MongoDB_Server_EnumerateInstances(
    MongoDB_Server_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_PropertySet* propertySet,
    MI_Boolean keysOnly,
    const MI_Filter* filter)
{
    MongoDB_Server_Class_Provider* cxxSelf =((MongoDB_Server_Class_Provider*)self);
    Context  cxxContext(context);

    cxxSelf->EnumerateInstances(
        cxxContext,
        nameSpace,
        __PropertySet(propertySet),
        __bool(keysOnly),
        filter);
}

MI_EXTERN_C void MI_CALL MongoDB_Server_GetInstance(
    MongoDB_Server_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MongoDB_Server* instanceName,
    const MI_PropertySet* propertySet)
{
    MongoDB_Server_Class_Provider* cxxSelf =((MongoDB_Server_Class_Provider*)self);
    Context  cxxContext(context);
    MongoDB_Server_Class cxxInstanceName(instanceName, true);

    cxxSelf->GetInstance(
        cxxContext,
        nameSpace,
        cxxInstanceName,
        __PropertySet(propertySet));
}

MI_EXTERN_C void MI_CALL MongoDB_Server_CreateInstance(
    MongoDB_Server_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MongoDB_Server* newInstance)
{
    MongoDB_Server_Class_Provider* cxxSelf =((MongoDB_Server_Class_Provider*)self);
    Context  cxxContext(context);
    MongoDB_Server_Class cxxNewInstance(newInstance, false);

    cxxSelf->CreateInstance(cxxContext, nameSpace, cxxNewInstance);
}

MI_EXTERN_C void MI_CALL MongoDB_Server_ModifyInstance(
    MongoDB_Server_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MongoDB_Server* modifiedInstance,
    const MI_PropertySet* propertySet)
{
    MongoDB_Server_Class_Provider* cxxSelf =((MongoDB_Server_Class_Provider*)self);
    Context  cxxContext(context);
    MongoDB_Server_Class cxxModifiedInstance(modifiedInstance, false);

    cxxSelf->ModifyInstance(
        cxxContext,
        nameSpace,
        cxxModifiedInstance,
        __PropertySet(propertySet));
}

MI_EXTERN_C void MI_CALL MongoDB_Server_DeleteInstance(
    MongoDB_Server_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MongoDB_Server* instanceName)
{
    MongoDB_Server_Class_Provider* cxxSelf =((MongoDB_Server_Class_Provider*)self);
    Context  cxxContext(context);
    MongoDB_Server_Class cxxInstanceName(instanceName, true);

    cxxSelf->DeleteInstance(cxxContext, nameSpace, cxxInstanceName);
}

MI_EXTERN_C void MI_CALL MongoDB_Server_Database_Load(
    MongoDB_Server_Database_Self** self,
    MI_Module_Self* selfModule,
    MI_Context* context)
{
    MI_Result r = MI_RESULT_OK;
    Context ctx(context, &r);
    MongoDB_Server_Database_Class_Provider* prov = new MongoDB_Server_Database_Class_Provider((Module*)selfModule);

    prov->Load(ctx);
    if (MI_RESULT_OK != r)
    {
        delete prov;
        MI_Context_PostResult(context, r);
        return;
    }
    *self = (MongoDB_Server_Database_Self*)prov;
    MI_Context_PostResult(context, MI_RESULT_OK);
}

MI_EXTERN_C void MI_CALL MongoDB_Server_Database_Unload(
    MongoDB_Server_Database_Self* self,
    MI_Context* context)
{
    MI_Result r = MI_RESULT_OK;
    Context ctx(context, &r);
    MongoDB_Server_Database_Class_Provider* prov = (MongoDB_Server_Database_Class_Provider*)self;

    prov->Unload(ctx);
    delete ((MongoDB_Server_Database_Class_Provider*)self);
    MI_Context_PostResult(context, r);
}

MI_EXTERN_C void MI_CALL MongoDB_Server_Database_EnumerateInstances(
    MongoDB_Server_Database_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_PropertySet* propertySet,
    MI_Boolean keysOnly,
    const MI_Filter* filter)
{
    MongoDB_Server_Database_Class_Provider* cxxSelf =((MongoDB_Server_Database_Class_Provider*)self);
    Context  cxxContext(context);

    cxxSelf->EnumerateInstances(
        cxxContext,
        nameSpace,
        __PropertySet(propertySet),
        __bool(keysOnly),
        filter);
}

MI_EXTERN_C void MI_CALL MongoDB_Server_Database_GetInstance(
    MongoDB_Server_Database_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MongoDB_Server_Database* instanceName,
    const MI_PropertySet* propertySet)
{
    MongoDB_Server_Database_Class_Provider* cxxSelf =((MongoDB_Server_Database_Class_Provider*)self);
    Context  cxxContext(context);
    MongoDB_Server_Database_Class cxxInstanceName(instanceName, true);

    cxxSelf->GetInstance(
        cxxContext,
        nameSpace,
        cxxInstanceName,
        __PropertySet(propertySet));
}

MI_EXTERN_C void MI_CALL MongoDB_Server_Database_CreateInstance(
    MongoDB_Server_Database_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MongoDB_Server_Database* newInstance)
{
    MongoDB_Server_Database_Class_Provider* cxxSelf =((MongoDB_Server_Database_Class_Provider*)self);
    Context  cxxContext(context);
    MongoDB_Server_Database_Class cxxNewInstance(newInstance, false);

    cxxSelf->CreateInstance(cxxContext, nameSpace, cxxNewInstance);
}

MI_EXTERN_C void MI_CALL MongoDB_Server_Database_ModifyInstance(
    MongoDB_Server_Database_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MongoDB_Server_Database* modifiedInstance,
    const MI_PropertySet* propertySet)
{
    MongoDB_Server_Database_Class_Provider* cxxSelf =((MongoDB_Server_Database_Class_Provider*)self);
    Context  cxxContext(context);
    MongoDB_Server_Database_Class cxxModifiedInstance(modifiedInstance, false);

    cxxSelf->ModifyInstance(
        cxxContext,
        nameSpace,
        cxxModifiedInstance,
        __PropertySet(propertySet));
}

MI_EXTERN_C void MI_CALL MongoDB_Server_Database_DeleteInstance(
    MongoDB_Server_Database_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MongoDB_Server_Database* instanceName)
{
    MongoDB_Server_Database_Class_Provider* cxxSelf =((MongoDB_Server_Database_Class_Provider*)self);
    Context  cxxContext(context);
    MongoDB_Server_Database_Class cxxInstanceName(instanceName, true);

    cxxSelf->DeleteInstance(cxxContext, nameSpace, cxxInstanceName);
}

MI_EXTERN_C void MI_CALL MongoDB_Server_Statistics_Load(
    MongoDB_Server_Statistics_Self** self,
    MI_Module_Self* selfModule,
    MI_Context* context)
{
    MI_Result r = MI_RESULT_OK;
    Context ctx(context, &r);
    MongoDB_Server_Statistics_Class_Provider* prov = new MongoDB_Server_Statistics_Class_Provider((Module*)selfModule);

    prov->Load(ctx);
    if (MI_RESULT_OK != r)
    {
        delete prov;
        MI_Context_PostResult(context, r);
        return;
    }
    *self = (MongoDB_Server_Statistics_Self*)prov;
    MI_Context_PostResult(context, MI_RESULT_OK);
}

MI_EXTERN_C void MI_CALL MongoDB_Server_Statistics_Unload(
    MongoDB_Server_Statistics_Self* self,
    MI_Context* context)
{
    MI_Result r = MI_RESULT_OK;
    Context ctx(context, &r);
    MongoDB_Server_Statistics_Class_Provider* prov = (MongoDB_Server_Statistics_Class_Provider*)self;

    prov->Unload(ctx);
    delete ((MongoDB_Server_Statistics_Class_Provider*)self);
    MI_Context_PostResult(context, r);
}

MI_EXTERN_C void MI_CALL MongoDB_Server_Statistics_EnumerateInstances(
    MongoDB_Server_Statistics_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_PropertySet* propertySet,
    MI_Boolean keysOnly,
    const MI_Filter* filter)
{
    MongoDB_Server_Statistics_Class_Provider* cxxSelf =((MongoDB_Server_Statistics_Class_Provider*)self);
    Context  cxxContext(context);

    cxxSelf->EnumerateInstances(
        cxxContext,
        nameSpace,
        __PropertySet(propertySet),
        __bool(keysOnly),
        filter);
}

MI_EXTERN_C void MI_CALL MongoDB_Server_Statistics_GetInstance(
    MongoDB_Server_Statistics_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MongoDB_Server_Statistics* instanceName,
    const MI_PropertySet* propertySet)
{
    MongoDB_Server_Statistics_Class_Provider* cxxSelf =((MongoDB_Server_Statistics_Class_Provider*)self);
    Context  cxxContext(context);
    MongoDB_Server_Statistics_Class cxxInstanceName(instanceName, true);

    cxxSelf->GetInstance(
        cxxContext,
        nameSpace,
        cxxInstanceName,
        __PropertySet(propertySet));
}

MI_EXTERN_C void MI_CALL MongoDB_Server_Statistics_CreateInstance(
    MongoDB_Server_Statistics_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MongoDB_Server_Statistics* newInstance)
{
    MongoDB_Server_Statistics_Class_Provider* cxxSelf =((MongoDB_Server_Statistics_Class_Provider*)self);
    Context  cxxContext(context);
    MongoDB_Server_Statistics_Class cxxNewInstance(newInstance, false);

    cxxSelf->CreateInstance(cxxContext, nameSpace, cxxNewInstance);
}

MI_EXTERN_C void MI_CALL MongoDB_Server_Statistics_ModifyInstance(
    MongoDB_Server_Statistics_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MongoDB_Server_Statistics* modifiedInstance,
    const MI_PropertySet* propertySet)
{
    MongoDB_Server_Statistics_Class_Provider* cxxSelf =((MongoDB_Server_Statistics_Class_Provider*)self);
    Context  cxxContext(context);
    MongoDB_Server_Statistics_Class cxxModifiedInstance(modifiedInstance, false);

    cxxSelf->ModifyInstance(
        cxxContext,
        nameSpace,
        cxxModifiedInstance,
        __PropertySet(propertySet));
}

MI_EXTERN_C void MI_CALL MongoDB_Server_Statistics_DeleteInstance(
    MongoDB_Server_Statistics_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MongoDB_Server_Statistics* instanceName)
{
    MongoDB_Server_Statistics_Class_Provider* cxxSelf =((MongoDB_Server_Statistics_Class_Provider*)self);
    Context  cxxContext(context);
    MongoDB_Server_Statistics_Class cxxInstanceName(instanceName, true);

    cxxSelf->DeleteInstance(cxxContext, nameSpace, cxxInstanceName);
}


MI_EXTERN_C MI_SchemaDecl schemaDecl;

void MI_CALL Load(MI_Module_Self** self, struct _MI_Context* context)
{
    *self = (MI_Module_Self*)new Module;
    MI_Context_PostResult(context, MI_RESULT_OK);
}

void MI_CALL Unload(MI_Module_Self* self, struct _MI_Context* context)
{
    Module* module = (Module*)self;
    delete module;
    MI_Context_PostResult(context, MI_RESULT_OK);
}

MI_EXTERN_C MI_EXPORT MI_Module* MI_MAIN_CALL MI_Main(MI_Server* server)
{
    /* WARNING: THIS FUNCTION AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT. */
    extern MI_Server* __mi_server;
    static MI_Module module;
    __mi_server = server;
    module.flags |= MI_MODULE_FLAG_STANDARD_QUALIFIERS;
    module.flags |= MI_MODULE_FLAG_CPLUSPLUS;
    module.charSize = sizeof(MI_Char);
    module.version = MI_VERSION;
    module.generatorVersion = MI_MAKE_VERSION(1,0,8);
    module.schemaDecl = &schemaDecl;
    module.Load = Load;
    module.Unload = Unload;
    return &module;
}

