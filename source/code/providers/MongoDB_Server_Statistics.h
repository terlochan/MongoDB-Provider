/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _MongoDB_Server_Statistics_h
#define _MongoDB_Server_Statistics_h

#include <MI.h>

/*
**==============================================================================
**
** MongoDB_Server_Statistics [MongoDB_Server_Statistics]
**
** Keys:
**    HostName
**
**==============================================================================
*/

typedef struct _MongoDB_Server_Statistics
{
    MI_Instance __instance;
    /* MongoDB_Server_Statistics properties */
    /*KEY*/ MI_ConstStringField HostName;
    MI_ConstStringField ProcessName;
    MI_ConstUint64Field UpTimeinSeconds;
    MI_ConstUint32Field RegularAssert;
    MI_ConstUint32Field WarningAssert;
    MI_ConstUint32Field MessageAssert;
    MI_ConstUint32Field UserAssert;
    MI_ConstUint32Field RolloverAssert;
    MI_ConstUint32Field CurrentConnections;
}
MongoDB_Server_Statistics;

typedef struct _MongoDB_Server_Statistics_Ref
{
    MongoDB_Server_Statistics* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
MongoDB_Server_Statistics_Ref;

typedef struct _MongoDB_Server_Statistics_ConstRef
{
    MI_CONST MongoDB_Server_Statistics* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
MongoDB_Server_Statistics_ConstRef;

typedef struct _MongoDB_Server_Statistics_Array
{
    struct _MongoDB_Server_Statistics** data;
    MI_Uint32 size;
}
MongoDB_Server_Statistics_Array;

typedef struct _MongoDB_Server_Statistics_ConstArray
{
    struct _MongoDB_Server_Statistics MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
MongoDB_Server_Statistics_ConstArray;

typedef struct _MongoDB_Server_Statistics_ArrayRef
{
    MongoDB_Server_Statistics_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
MongoDB_Server_Statistics_ArrayRef;

typedef struct _MongoDB_Server_Statistics_ConstArrayRef
{
    MongoDB_Server_Statistics_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
MongoDB_Server_Statistics_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl MongoDB_Server_Statistics_rtti;

MI_INLINE MI_Result MI_CALL MongoDB_Server_Statistics_Construct(
    MongoDB_Server_Statistics* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &MongoDB_Server_Statistics_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Statistics_Clone(
    const MongoDB_Server_Statistics* self,
    MongoDB_Server_Statistics** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL MongoDB_Server_Statistics_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &MongoDB_Server_Statistics_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Statistics_Destruct(MongoDB_Server_Statistics* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Statistics_Delete(MongoDB_Server_Statistics* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Statistics_Post(
    const MongoDB_Server_Statistics* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Statistics_Set_HostName(
    MongoDB_Server_Statistics* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Statistics_SetPtr_HostName(
    MongoDB_Server_Statistics* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Statistics_Clear_HostName(
    MongoDB_Server_Statistics* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Statistics_Set_ProcessName(
    MongoDB_Server_Statistics* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Statistics_SetPtr_ProcessName(
    MongoDB_Server_Statistics* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Statistics_Clear_ProcessName(
    MongoDB_Server_Statistics* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Statistics_Set_UpTimeinSeconds(
    MongoDB_Server_Statistics* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->UpTimeinSeconds)->value = x;
    ((MI_Uint64Field*)&self->UpTimeinSeconds)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Statistics_Clear_UpTimeinSeconds(
    MongoDB_Server_Statistics* self)
{
    memset((void*)&self->UpTimeinSeconds, 0, sizeof(self->UpTimeinSeconds));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Statistics_Set_RegularAssert(
    MongoDB_Server_Statistics* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->RegularAssert)->value = x;
    ((MI_Uint32Field*)&self->RegularAssert)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Statistics_Clear_RegularAssert(
    MongoDB_Server_Statistics* self)
{
    memset((void*)&self->RegularAssert, 0, sizeof(self->RegularAssert));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Statistics_Set_WarningAssert(
    MongoDB_Server_Statistics* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->WarningAssert)->value = x;
    ((MI_Uint32Field*)&self->WarningAssert)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Statistics_Clear_WarningAssert(
    MongoDB_Server_Statistics* self)
{
    memset((void*)&self->WarningAssert, 0, sizeof(self->WarningAssert));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Statistics_Set_MessageAssert(
    MongoDB_Server_Statistics* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MessageAssert)->value = x;
    ((MI_Uint32Field*)&self->MessageAssert)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Statistics_Clear_MessageAssert(
    MongoDB_Server_Statistics* self)
{
    memset((void*)&self->MessageAssert, 0, sizeof(self->MessageAssert));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Statistics_Set_UserAssert(
    MongoDB_Server_Statistics* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->UserAssert)->value = x;
    ((MI_Uint32Field*)&self->UserAssert)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Statistics_Clear_UserAssert(
    MongoDB_Server_Statistics* self)
{
    memset((void*)&self->UserAssert, 0, sizeof(self->UserAssert));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Statistics_Set_RolloverAssert(
    MongoDB_Server_Statistics* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->RolloverAssert)->value = x;
    ((MI_Uint32Field*)&self->RolloverAssert)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Statistics_Clear_RolloverAssert(
    MongoDB_Server_Statistics* self)
{
    memset((void*)&self->RolloverAssert, 0, sizeof(self->RolloverAssert));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Statistics_Set_CurrentConnections(
    MongoDB_Server_Statistics* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->CurrentConnections)->value = x;
    ((MI_Uint32Field*)&self->CurrentConnections)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Statistics_Clear_CurrentConnections(
    MongoDB_Server_Statistics* self)
{
    memset((void*)&self->CurrentConnections, 0, sizeof(self->CurrentConnections));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** MongoDB_Server_Statistics provider function prototypes
**
**==============================================================================
*/

/* The developer may optionally define this structure */
typedef struct _MongoDB_Server_Statistics_Self MongoDB_Server_Statistics_Self;

MI_EXTERN_C void MI_CALL MongoDB_Server_Statistics_Load(
    MongoDB_Server_Statistics_Self** self,
    MI_Module_Self* selfModule,
    MI_Context* context);

MI_EXTERN_C void MI_CALL MongoDB_Server_Statistics_Unload(
    MongoDB_Server_Statistics_Self* self,
    MI_Context* context);

MI_EXTERN_C void MI_CALL MongoDB_Server_Statistics_EnumerateInstances(
    MongoDB_Server_Statistics_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_PropertySet* propertySet,
    MI_Boolean keysOnly,
    const MI_Filter* filter);

MI_EXTERN_C void MI_CALL MongoDB_Server_Statistics_GetInstance(
    MongoDB_Server_Statistics_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MongoDB_Server_Statistics* instanceName,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL MongoDB_Server_Statistics_CreateInstance(
    MongoDB_Server_Statistics_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MongoDB_Server_Statistics* newInstance);

MI_EXTERN_C void MI_CALL MongoDB_Server_Statistics_ModifyInstance(
    MongoDB_Server_Statistics_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MongoDB_Server_Statistics* modifiedInstance,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL MongoDB_Server_Statistics_DeleteInstance(
    MongoDB_Server_Statistics_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MongoDB_Server_Statistics* instanceName);


/*
**==============================================================================
**
** MongoDB_Server_Statistics_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class MongoDB_Server_Statistics_Class : public Instance
{
public:
    
    typedef MongoDB_Server_Statistics Self;
    
    MongoDB_Server_Statistics_Class() :
        Instance(&MongoDB_Server_Statistics_rtti)
    {
    }
    
    MongoDB_Server_Statistics_Class(
        const MongoDB_Server_Statistics* instanceName,
        bool keysOnly) :
        Instance(
            &MongoDB_Server_Statistics_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    MongoDB_Server_Statistics_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    MongoDB_Server_Statistics_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    MongoDB_Server_Statistics_Class& operator=(
        const MongoDB_Server_Statistics_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    MongoDB_Server_Statistics_Class(
        const MongoDB_Server_Statistics_Class& x) :
        Instance(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &MongoDB_Server_Statistics_rtti;
    }

    //
    // MongoDB_Server_Statistics_Class.HostName
    //
    
    const Field<String>& HostName() const
    {
        const size_t n = offsetof(Self, HostName);
        return GetField<String>(n);
    }
    
    void HostName(const Field<String>& x)
    {
        const size_t n = offsetof(Self, HostName);
        GetField<String>(n) = x;
    }
    
    const String& HostName_value() const
    {
        const size_t n = offsetof(Self, HostName);
        return GetField<String>(n).value;
    }
    
    void HostName_value(const String& x)
    {
        const size_t n = offsetof(Self, HostName);
        GetField<String>(n).Set(x);
    }
    
    bool HostName_exists() const
    {
        const size_t n = offsetof(Self, HostName);
        return GetField<String>(n).exists ? true : false;
    }
    
    void HostName_clear()
    {
        const size_t n = offsetof(Self, HostName);
        GetField<String>(n).Clear();
    }

    //
    // MongoDB_Server_Statistics_Class.ProcessName
    //
    
    const Field<String>& ProcessName() const
    {
        const size_t n = offsetof(Self, ProcessName);
        return GetField<String>(n);
    }
    
    void ProcessName(const Field<String>& x)
    {
        const size_t n = offsetof(Self, ProcessName);
        GetField<String>(n) = x;
    }
    
    const String& ProcessName_value() const
    {
        const size_t n = offsetof(Self, ProcessName);
        return GetField<String>(n).value;
    }
    
    void ProcessName_value(const String& x)
    {
        const size_t n = offsetof(Self, ProcessName);
        GetField<String>(n).Set(x);
    }
    
    bool ProcessName_exists() const
    {
        const size_t n = offsetof(Self, ProcessName);
        return GetField<String>(n).exists ? true : false;
    }
    
    void ProcessName_clear()
    {
        const size_t n = offsetof(Self, ProcessName);
        GetField<String>(n).Clear();
    }

    //
    // MongoDB_Server_Statistics_Class.UpTimeinSeconds
    //
    
    const Field<Uint64>& UpTimeinSeconds() const
    {
        const size_t n = offsetof(Self, UpTimeinSeconds);
        return GetField<Uint64>(n);
    }
    
    void UpTimeinSeconds(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, UpTimeinSeconds);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& UpTimeinSeconds_value() const
    {
        const size_t n = offsetof(Self, UpTimeinSeconds);
        return GetField<Uint64>(n).value;
    }
    
    void UpTimeinSeconds_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, UpTimeinSeconds);
        GetField<Uint64>(n).Set(x);
    }
    
    bool UpTimeinSeconds_exists() const
    {
        const size_t n = offsetof(Self, UpTimeinSeconds);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void UpTimeinSeconds_clear()
    {
        const size_t n = offsetof(Self, UpTimeinSeconds);
        GetField<Uint64>(n).Clear();
    }

    //
    // MongoDB_Server_Statistics_Class.RegularAssert
    //
    
    const Field<Uint32>& RegularAssert() const
    {
        const size_t n = offsetof(Self, RegularAssert);
        return GetField<Uint32>(n);
    }
    
    void RegularAssert(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, RegularAssert);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& RegularAssert_value() const
    {
        const size_t n = offsetof(Self, RegularAssert);
        return GetField<Uint32>(n).value;
    }
    
    void RegularAssert_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, RegularAssert);
        GetField<Uint32>(n).Set(x);
    }
    
    bool RegularAssert_exists() const
    {
        const size_t n = offsetof(Self, RegularAssert);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void RegularAssert_clear()
    {
        const size_t n = offsetof(Self, RegularAssert);
        GetField<Uint32>(n).Clear();
    }

    //
    // MongoDB_Server_Statistics_Class.WarningAssert
    //
    
    const Field<Uint32>& WarningAssert() const
    {
        const size_t n = offsetof(Self, WarningAssert);
        return GetField<Uint32>(n);
    }
    
    void WarningAssert(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, WarningAssert);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& WarningAssert_value() const
    {
        const size_t n = offsetof(Self, WarningAssert);
        return GetField<Uint32>(n).value;
    }
    
    void WarningAssert_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, WarningAssert);
        GetField<Uint32>(n).Set(x);
    }
    
    bool WarningAssert_exists() const
    {
        const size_t n = offsetof(Self, WarningAssert);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void WarningAssert_clear()
    {
        const size_t n = offsetof(Self, WarningAssert);
        GetField<Uint32>(n).Clear();
    }

    //
    // MongoDB_Server_Statistics_Class.MessageAssert
    //
    
    const Field<Uint32>& MessageAssert() const
    {
        const size_t n = offsetof(Self, MessageAssert);
        return GetField<Uint32>(n);
    }
    
    void MessageAssert(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, MessageAssert);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& MessageAssert_value() const
    {
        const size_t n = offsetof(Self, MessageAssert);
        return GetField<Uint32>(n).value;
    }
    
    void MessageAssert_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, MessageAssert);
        GetField<Uint32>(n).Set(x);
    }
    
    bool MessageAssert_exists() const
    {
        const size_t n = offsetof(Self, MessageAssert);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void MessageAssert_clear()
    {
        const size_t n = offsetof(Self, MessageAssert);
        GetField<Uint32>(n).Clear();
    }

    //
    // MongoDB_Server_Statistics_Class.UserAssert
    //
    
    const Field<Uint32>& UserAssert() const
    {
        const size_t n = offsetof(Self, UserAssert);
        return GetField<Uint32>(n);
    }
    
    void UserAssert(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, UserAssert);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& UserAssert_value() const
    {
        const size_t n = offsetof(Self, UserAssert);
        return GetField<Uint32>(n).value;
    }
    
    void UserAssert_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, UserAssert);
        GetField<Uint32>(n).Set(x);
    }
    
    bool UserAssert_exists() const
    {
        const size_t n = offsetof(Self, UserAssert);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void UserAssert_clear()
    {
        const size_t n = offsetof(Self, UserAssert);
        GetField<Uint32>(n).Clear();
    }

    //
    // MongoDB_Server_Statistics_Class.RolloverAssert
    //
    
    const Field<Uint32>& RolloverAssert() const
    {
        const size_t n = offsetof(Self, RolloverAssert);
        return GetField<Uint32>(n);
    }
    
    void RolloverAssert(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, RolloverAssert);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& RolloverAssert_value() const
    {
        const size_t n = offsetof(Self, RolloverAssert);
        return GetField<Uint32>(n).value;
    }
    
    void RolloverAssert_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, RolloverAssert);
        GetField<Uint32>(n).Set(x);
    }
    
    bool RolloverAssert_exists() const
    {
        const size_t n = offsetof(Self, RolloverAssert);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void RolloverAssert_clear()
    {
        const size_t n = offsetof(Self, RolloverAssert);
        GetField<Uint32>(n).Clear();
    }

    //
    // MongoDB_Server_Statistics_Class.CurrentConnections
    //
    
    const Field<Uint32>& CurrentConnections() const
    {
        const size_t n = offsetof(Self, CurrentConnections);
        return GetField<Uint32>(n);
    }
    
    void CurrentConnections(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, CurrentConnections);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& CurrentConnections_value() const
    {
        const size_t n = offsetof(Self, CurrentConnections);
        return GetField<Uint32>(n).value;
    }
    
    void CurrentConnections_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, CurrentConnections);
        GetField<Uint32>(n).Set(x);
    }
    
    bool CurrentConnections_exists() const
    {
        const size_t n = offsetof(Self, CurrentConnections);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void CurrentConnections_clear()
    {
        const size_t n = offsetof(Self, CurrentConnections);
        GetField<Uint32>(n).Clear();
    }
};

typedef Array<MongoDB_Server_Statistics_Class> MongoDB_Server_Statistics_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _MongoDB_Server_Statistics_h */
