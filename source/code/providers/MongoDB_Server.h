/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _MongoDB_Server_h
#define _MongoDB_Server_h

#include <MI.h>

/*
**==============================================================================
**
** MongoDB_Server [MongoDB_Server]
**
** Keys:
**    Hostname
**
**==============================================================================
*/

typedef struct _MongoDB_Server
{
    MI_Instance __instance;
    /* MongoDB_Server properties */
    /*KEY*/ MI_ConstStringField Hostname;
    MI_ConstBooleanField IsMaster;
    MI_ConstStringField ServerVersion;
}
MongoDB_Server;

typedef struct _MongoDB_Server_Ref
{
    MongoDB_Server* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
MongoDB_Server_Ref;

typedef struct _MongoDB_Server_ConstRef
{
    MI_CONST MongoDB_Server* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
MongoDB_Server_ConstRef;

typedef struct _MongoDB_Server_Array
{
    struct _MongoDB_Server** data;
    MI_Uint32 size;
}
MongoDB_Server_Array;

typedef struct _MongoDB_Server_ConstArray
{
    struct _MongoDB_Server MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
MongoDB_Server_ConstArray;

typedef struct _MongoDB_Server_ArrayRef
{
    MongoDB_Server_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
MongoDB_Server_ArrayRef;

typedef struct _MongoDB_Server_ConstArrayRef
{
    MongoDB_Server_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
MongoDB_Server_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl MongoDB_Server_rtti;

MI_INLINE MI_Result MI_CALL MongoDB_Server_Construct(
    MongoDB_Server* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &MongoDB_Server_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Clone(
    const MongoDB_Server* self,
    MongoDB_Server** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL MongoDB_Server_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &MongoDB_Server_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Destruct(MongoDB_Server* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Delete(MongoDB_Server* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Post(
    const MongoDB_Server* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Set_Hostname(
    MongoDB_Server* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_SetPtr_Hostname(
    MongoDB_Server* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Clear_Hostname(
    MongoDB_Server* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Set_IsMaster(
    MongoDB_Server* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->IsMaster)->value = x;
    ((MI_BooleanField*)&self->IsMaster)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Clear_IsMaster(
    MongoDB_Server* self)
{
    memset((void*)&self->IsMaster, 0, sizeof(self->IsMaster));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Set_ServerVersion(
    MongoDB_Server* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_SetPtr_ServerVersion(
    MongoDB_Server* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Clear_ServerVersion(
    MongoDB_Server* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

/*
**==============================================================================
**
** MongoDB_Server provider function prototypes
**
**==============================================================================
*/

/* The developer may optionally define this structure */
typedef struct _MongoDB_Server_Self MongoDB_Server_Self;

MI_EXTERN_C void MI_CALL MongoDB_Server_Load(
    MongoDB_Server_Self** self,
    MI_Module_Self* selfModule,
    MI_Context* context);

MI_EXTERN_C void MI_CALL MongoDB_Server_Unload(
    MongoDB_Server_Self* self,
    MI_Context* context);

MI_EXTERN_C void MI_CALL MongoDB_Server_EnumerateInstances(
    MongoDB_Server_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_PropertySet* propertySet,
    MI_Boolean keysOnly,
    const MI_Filter* filter);

MI_EXTERN_C void MI_CALL MongoDB_Server_GetInstance(
    MongoDB_Server_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MongoDB_Server* instanceName,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL MongoDB_Server_CreateInstance(
    MongoDB_Server_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MongoDB_Server* newInstance);

MI_EXTERN_C void MI_CALL MongoDB_Server_ModifyInstance(
    MongoDB_Server_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MongoDB_Server* modifiedInstance,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL MongoDB_Server_DeleteInstance(
    MongoDB_Server_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MongoDB_Server* instanceName);


/*
**==============================================================================
**
** MongoDB_Server_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class MongoDB_Server_Class : public Instance
{
public:
    
    typedef MongoDB_Server Self;
    
    MongoDB_Server_Class() :
        Instance(&MongoDB_Server_rtti)
    {
    }
    
    MongoDB_Server_Class(
        const MongoDB_Server* instanceName,
        bool keysOnly) :
        Instance(
            &MongoDB_Server_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    MongoDB_Server_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    MongoDB_Server_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    MongoDB_Server_Class& operator=(
        const MongoDB_Server_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    MongoDB_Server_Class(
        const MongoDB_Server_Class& x) :
        Instance(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &MongoDB_Server_rtti;
    }

    //
    // MongoDB_Server_Class.Hostname
    //
    
    const Field<String>& Hostname() const
    {
        const size_t n = offsetof(Self, Hostname);
        return GetField<String>(n);
    }
    
    void Hostname(const Field<String>& x)
    {
        const size_t n = offsetof(Self, Hostname);
        GetField<String>(n) = x;
    }
    
    const String& Hostname_value() const
    {
        const size_t n = offsetof(Self, Hostname);
        return GetField<String>(n).value;
    }
    
    void Hostname_value(const String& x)
    {
        const size_t n = offsetof(Self, Hostname);
        GetField<String>(n).Set(x);
    }
    
    bool Hostname_exists() const
    {
        const size_t n = offsetof(Self, Hostname);
        return GetField<String>(n).exists ? true : false;
    }
    
    void Hostname_clear()
    {
        const size_t n = offsetof(Self, Hostname);
        GetField<String>(n).Clear();
    }

    //
    // MongoDB_Server_Class.IsMaster
    //
    
    const Field<Boolean>& IsMaster() const
    {
        const size_t n = offsetof(Self, IsMaster);
        return GetField<Boolean>(n);
    }
    
    void IsMaster(const Field<Boolean>& x)
    {
        const size_t n = offsetof(Self, IsMaster);
        GetField<Boolean>(n) = x;
    }
    
    const Boolean& IsMaster_value() const
    {
        const size_t n = offsetof(Self, IsMaster);
        return GetField<Boolean>(n).value;
    }
    
    void IsMaster_value(const Boolean& x)
    {
        const size_t n = offsetof(Self, IsMaster);
        GetField<Boolean>(n).Set(x);
    }
    
    bool IsMaster_exists() const
    {
        const size_t n = offsetof(Self, IsMaster);
        return GetField<Boolean>(n).exists ? true : false;
    }
    
    void IsMaster_clear()
    {
        const size_t n = offsetof(Self, IsMaster);
        GetField<Boolean>(n).Clear();
    }

    //
    // MongoDB_Server_Class.ServerVersion
    //
    
    const Field<String>& ServerVersion() const
    {
        const size_t n = offsetof(Self, ServerVersion);
        return GetField<String>(n);
    }
    
    void ServerVersion(const Field<String>& x)
    {
        const size_t n = offsetof(Self, ServerVersion);
        GetField<String>(n) = x;
    }
    
    const String& ServerVersion_value() const
    {
        const size_t n = offsetof(Self, ServerVersion);
        return GetField<String>(n).value;
    }
    
    void ServerVersion_value(const String& x)
    {
        const size_t n = offsetof(Self, ServerVersion);
        GetField<String>(n).Set(x);
    }
    
    bool ServerVersion_exists() const
    {
        const size_t n = offsetof(Self, ServerVersion);
        return GetField<String>(n).exists ? true : false;
    }
    
    void ServerVersion_clear()
    {
        const size_t n = offsetof(Self, ServerVersion);
        GetField<String>(n).Clear();
    }
};

typedef Array<MongoDB_Server_Class> MongoDB_Server_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _MongoDB_Server_h */
