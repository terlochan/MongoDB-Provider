/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _MongoDB_Server_Database_h
#define _MongoDB_Server_Database_h

#include <MI.h>

/*
**==============================================================================
**
** MongoDB_Server_Database [MongoDB_Server_Database]
**
** Keys:
**    DatabaseName
**
**==============================================================================
*/

typedef struct _MongoDB_Server_Database
{
    MI_Instance __instance;
    /* MongoDB_Server_Database properties */
    /*KEY*/ MI_ConstStringField DatabaseName;
    MI_ConstUint64Field NumberOfCollections;
    MI_ConstUint64Field DiskSpaceInbytes;
}
MongoDB_Server_Database;

typedef struct _MongoDB_Server_Database_Ref
{
    MongoDB_Server_Database* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
MongoDB_Server_Database_Ref;

typedef struct _MongoDB_Server_Database_ConstRef
{
    MI_CONST MongoDB_Server_Database* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
MongoDB_Server_Database_ConstRef;

typedef struct _MongoDB_Server_Database_Array
{
    struct _MongoDB_Server_Database** data;
    MI_Uint32 size;
}
MongoDB_Server_Database_Array;

typedef struct _MongoDB_Server_Database_ConstArray
{
    struct _MongoDB_Server_Database MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
MongoDB_Server_Database_ConstArray;

typedef struct _MongoDB_Server_Database_ArrayRef
{
    MongoDB_Server_Database_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
MongoDB_Server_Database_ArrayRef;

typedef struct _MongoDB_Server_Database_ConstArrayRef
{
    MongoDB_Server_Database_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
MongoDB_Server_Database_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl MongoDB_Server_Database_rtti;

MI_INLINE MI_Result MI_CALL MongoDB_Server_Database_Construct(
    MongoDB_Server_Database* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &MongoDB_Server_Database_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Database_Clone(
    const MongoDB_Server_Database* self,
    MongoDB_Server_Database** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL MongoDB_Server_Database_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &MongoDB_Server_Database_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Database_Destruct(MongoDB_Server_Database* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Database_Delete(MongoDB_Server_Database* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Database_Post(
    const MongoDB_Server_Database* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Database_Set_DatabaseName(
    MongoDB_Server_Database* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Database_SetPtr_DatabaseName(
    MongoDB_Server_Database* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Database_Clear_DatabaseName(
    MongoDB_Server_Database* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Database_Set_NumberOfCollections(
    MongoDB_Server_Database* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->NumberOfCollections)->value = x;
    ((MI_Uint64Field*)&self->NumberOfCollections)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Database_Clear_NumberOfCollections(
    MongoDB_Server_Database* self)
{
    memset((void*)&self->NumberOfCollections, 0, sizeof(self->NumberOfCollections));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Database_Set_DiskSpaceInbytes(
    MongoDB_Server_Database* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->DiskSpaceInbytes)->value = x;
    ((MI_Uint64Field*)&self->DiskSpaceInbytes)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL MongoDB_Server_Database_Clear_DiskSpaceInbytes(
    MongoDB_Server_Database* self)
{
    memset((void*)&self->DiskSpaceInbytes, 0, sizeof(self->DiskSpaceInbytes));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** MongoDB_Server_Database provider function prototypes
**
**==============================================================================
*/

/* The developer may optionally define this structure */
typedef struct _MongoDB_Server_Database_Self MongoDB_Server_Database_Self;

MI_EXTERN_C void MI_CALL MongoDB_Server_Database_Load(
    MongoDB_Server_Database_Self** self,
    MI_Module_Self* selfModule,
    MI_Context* context);

MI_EXTERN_C void MI_CALL MongoDB_Server_Database_Unload(
    MongoDB_Server_Database_Self* self,
    MI_Context* context);

MI_EXTERN_C void MI_CALL MongoDB_Server_Database_EnumerateInstances(
    MongoDB_Server_Database_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_PropertySet* propertySet,
    MI_Boolean keysOnly,
    const MI_Filter* filter);

MI_EXTERN_C void MI_CALL MongoDB_Server_Database_GetInstance(
    MongoDB_Server_Database_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MongoDB_Server_Database* instanceName,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL MongoDB_Server_Database_CreateInstance(
    MongoDB_Server_Database_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MongoDB_Server_Database* newInstance);

MI_EXTERN_C void MI_CALL MongoDB_Server_Database_ModifyInstance(
    MongoDB_Server_Database_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MongoDB_Server_Database* modifiedInstance,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL MongoDB_Server_Database_DeleteInstance(
    MongoDB_Server_Database_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MongoDB_Server_Database* instanceName);


/*
**==============================================================================
**
** MongoDB_Server_Database_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class MongoDB_Server_Database_Class : public Instance
{
public:
    
    typedef MongoDB_Server_Database Self;
    
    MongoDB_Server_Database_Class() :
        Instance(&MongoDB_Server_Database_rtti)
    {
    }
    
    MongoDB_Server_Database_Class(
        const MongoDB_Server_Database* instanceName,
        bool keysOnly) :
        Instance(
            &MongoDB_Server_Database_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    MongoDB_Server_Database_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    MongoDB_Server_Database_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    MongoDB_Server_Database_Class& operator=(
        const MongoDB_Server_Database_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    MongoDB_Server_Database_Class(
        const MongoDB_Server_Database_Class& x) :
        Instance(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &MongoDB_Server_Database_rtti;
    }

    //
    // MongoDB_Server_Database_Class.DatabaseName
    //
    
    const Field<String>& DatabaseName() const
    {
        const size_t n = offsetof(Self, DatabaseName);
        return GetField<String>(n);
    }
    
    void DatabaseName(const Field<String>& x)
    {
        const size_t n = offsetof(Self, DatabaseName);
        GetField<String>(n) = x;
    }
    
    const String& DatabaseName_value() const
    {
        const size_t n = offsetof(Self, DatabaseName);
        return GetField<String>(n).value;
    }
    
    void DatabaseName_value(const String& x)
    {
        const size_t n = offsetof(Self, DatabaseName);
        GetField<String>(n).Set(x);
    }
    
    bool DatabaseName_exists() const
    {
        const size_t n = offsetof(Self, DatabaseName);
        return GetField<String>(n).exists ? true : false;
    }
    
    void DatabaseName_clear()
    {
        const size_t n = offsetof(Self, DatabaseName);
        GetField<String>(n).Clear();
    }

    //
    // MongoDB_Server_Database_Class.NumberOfCollections
    //
    
    const Field<Uint64>& NumberOfCollections() const
    {
        const size_t n = offsetof(Self, NumberOfCollections);
        return GetField<Uint64>(n);
    }
    
    void NumberOfCollections(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, NumberOfCollections);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& NumberOfCollections_value() const
    {
        const size_t n = offsetof(Self, NumberOfCollections);
        return GetField<Uint64>(n).value;
    }
    
    void NumberOfCollections_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, NumberOfCollections);
        GetField<Uint64>(n).Set(x);
    }
    
    bool NumberOfCollections_exists() const
    {
        const size_t n = offsetof(Self, NumberOfCollections);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void NumberOfCollections_clear()
    {
        const size_t n = offsetof(Self, NumberOfCollections);
        GetField<Uint64>(n).Clear();
    }

    //
    // MongoDB_Server_Database_Class.DiskSpaceInbytes
    //
    
    const Field<Uint64>& DiskSpaceInbytes() const
    {
        const size_t n = offsetof(Self, DiskSpaceInbytes);
        return GetField<Uint64>(n);
    }
    
    void DiskSpaceInbytes(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, DiskSpaceInbytes);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& DiskSpaceInbytes_value() const
    {
        const size_t n = offsetof(Self, DiskSpaceInbytes);
        return GetField<Uint64>(n).value;
    }
    
    void DiskSpaceInbytes_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, DiskSpaceInbytes);
        GetField<Uint64>(n).Set(x);
    }
    
    bool DiskSpaceInbytes_exists() const
    {
        const size_t n = offsetof(Self, DiskSpaceInbytes);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void DiskSpaceInbytes_clear()
    {
        const size_t n = offsetof(Self, DiskSpaceInbytes);
        GetField<Uint64>(n).Clear();
    }
};

typedef Array<MongoDB_Server_Database_Class> MongoDB_Server_Database_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _MongoDB_Server_Database_h */
