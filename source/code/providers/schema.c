/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#include <ctype.h>
#include <MI.h>
#include "MongoDB_Server.h"
#include "MongoDB_Server_Database.h"
#include "MongoDB_Server_Statistics.h"

/*
**==============================================================================
**
** Schema Declaration
**
**==============================================================================
*/

extern MI_SchemaDecl schemaDecl;

/*
**==============================================================================
**
** Qualifier declarations
**
**==============================================================================
*/

/*
**==============================================================================
**
** MongoDB_Server
**
**==============================================================================
*/

/* property MongoDB_Server.Hostname */
static MI_CONST MI_PropertyDecl MongoDB_Server_Hostname_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x00686508, /* code */
    MI_T("Hostname"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(MongoDB_Server, Hostname), /* offset */
    MI_T("MongoDB_Server"), /* origin */
    MI_T("MongoDB_Server"), /* propagator */
    NULL,
};

/* property MongoDB_Server.IsMaster */
static MI_CONST MI_PropertyDecl MongoDB_Server_IsMaster_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00697208, /* code */
    MI_T("IsMaster"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_BOOLEAN, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(MongoDB_Server, IsMaster), /* offset */
    MI_T("MongoDB_Server"), /* origin */
    MI_T("MongoDB_Server"), /* propagator */
    NULL,
};

/* property MongoDB_Server.ServerVersion */
static MI_CONST MI_PropertyDecl MongoDB_Server_ServerVersion_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00736E0D, /* code */
    MI_T("ServerVersion"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(MongoDB_Server, ServerVersion), /* offset */
    MI_T("MongoDB_Server"), /* origin */
    MI_T("MongoDB_Server"), /* propagator */
    NULL,
};

static MI_PropertyDecl MI_CONST* MI_CONST MongoDB_Server_props[] =
{
    &MongoDB_Server_Hostname_prop,
    &MongoDB_Server_IsMaster_prop,
    &MongoDB_Server_ServerVersion_prop,
};

static MI_CONST MI_ProviderFT MongoDB_Server_funcs =
{
  (MI_ProviderFT_Load)MongoDB_Server_Load,
  (MI_ProviderFT_Unload)MongoDB_Server_Unload,
  (MI_ProviderFT_GetInstance)MongoDB_Server_GetInstance,
  (MI_ProviderFT_EnumerateInstances)MongoDB_Server_EnumerateInstances,
  (MI_ProviderFT_CreateInstance)MongoDB_Server_CreateInstance,
  (MI_ProviderFT_ModifyInstance)MongoDB_Server_ModifyInstance,
  (MI_ProviderFT_DeleteInstance)MongoDB_Server_DeleteInstance,
  (MI_ProviderFT_AssociatorInstances)NULL,
  (MI_ProviderFT_ReferenceInstances)NULL,
  (MI_ProviderFT_EnableIndications)NULL,
  (MI_ProviderFT_DisableIndications)NULL,
  (MI_ProviderFT_Subscribe)NULL,
  (MI_ProviderFT_Unsubscribe)NULL,
  (MI_ProviderFT_Invoke)NULL,
};

static MI_CONST MI_Char* MongoDB_Server_Version_qual_value = MI_T("1.0.0");

static MI_CONST MI_Qualifier MongoDB_Server_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &MongoDB_Server_Version_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST MongoDB_Server_quals[] =
{
    &MongoDB_Server_Version_qual,
};

/* class MongoDB_Server */
MI_CONST MI_ClassDecl MongoDB_Server_rtti =
{
    MI_FLAG_CLASS, /* flags */
    0x006D720E, /* code */
    MI_T("MongoDB_Server"), /* name */
    MongoDB_Server_quals, /* qualifiers */
    MI_COUNT(MongoDB_Server_quals), /* numQualifiers */
    MongoDB_Server_props, /* properties */
    MI_COUNT(MongoDB_Server_props), /* numProperties */
    sizeof(MongoDB_Server), /* size */
    NULL, /* superClass */
    NULL, /* superClassDecl */
    NULL, /* methods */
    0, /* numMethods */
    &schemaDecl, /* schema */
    &MongoDB_Server_funcs, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** MongoDB_Server_Database
**
**==============================================================================
*/

/* property MongoDB_Server_Database.DatabaseName */
static MI_CONST MI_PropertyDecl MongoDB_Server_Database_DatabaseName_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x0064650C, /* code */
    MI_T("DatabaseName"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(MongoDB_Server_Database, DatabaseName), /* offset */
    MI_T("MongoDB_Server_Database"), /* origin */
    MI_T("MongoDB_Server_Database"), /* propagator */
    NULL,
};

/* property MongoDB_Server_Database.NumberOfCollections */
static MI_CONST MI_PropertyDecl MongoDB_Server_Database_NumberOfCollections_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006E7313, /* code */
    MI_T("NumberOfCollections"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(MongoDB_Server_Database, NumberOfCollections), /* offset */
    MI_T("MongoDB_Server_Database"), /* origin */
    MI_T("MongoDB_Server_Database"), /* propagator */
    NULL,
};

/* property MongoDB_Server_Database.DiskSpaceInbytes */
static MI_CONST MI_PropertyDecl MongoDB_Server_Database_DiskSpaceInbytes_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00647310, /* code */
    MI_T("DiskSpaceInbytes"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(MongoDB_Server_Database, DiskSpaceInbytes), /* offset */
    MI_T("MongoDB_Server_Database"), /* origin */
    MI_T("MongoDB_Server_Database"), /* propagator */
    NULL,
};

static MI_PropertyDecl MI_CONST* MI_CONST MongoDB_Server_Database_props[] =
{
    &MongoDB_Server_Database_DatabaseName_prop,
    &MongoDB_Server_Database_NumberOfCollections_prop,
    &MongoDB_Server_Database_DiskSpaceInbytes_prop,
};

static MI_CONST MI_ProviderFT MongoDB_Server_Database_funcs =
{
  (MI_ProviderFT_Load)MongoDB_Server_Database_Load,
  (MI_ProviderFT_Unload)MongoDB_Server_Database_Unload,
  (MI_ProviderFT_GetInstance)MongoDB_Server_Database_GetInstance,
  (MI_ProviderFT_EnumerateInstances)MongoDB_Server_Database_EnumerateInstances,
  (MI_ProviderFT_CreateInstance)MongoDB_Server_Database_CreateInstance,
  (MI_ProviderFT_ModifyInstance)MongoDB_Server_Database_ModifyInstance,
  (MI_ProviderFT_DeleteInstance)MongoDB_Server_Database_DeleteInstance,
  (MI_ProviderFT_AssociatorInstances)NULL,
  (MI_ProviderFT_ReferenceInstances)NULL,
  (MI_ProviderFT_EnableIndications)NULL,
  (MI_ProviderFT_DisableIndications)NULL,
  (MI_ProviderFT_Subscribe)NULL,
  (MI_ProviderFT_Unsubscribe)NULL,
  (MI_ProviderFT_Invoke)NULL,
};

static MI_CONST MI_Char* MongoDB_Server_Database_Version_qual_value = MI_T("1.0.0");

static MI_CONST MI_Qualifier MongoDB_Server_Database_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &MongoDB_Server_Database_Version_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST MongoDB_Server_Database_quals[] =
{
    &MongoDB_Server_Database_Version_qual,
};

/* class MongoDB_Server_Database */
MI_CONST MI_ClassDecl MongoDB_Server_Database_rtti =
{
    MI_FLAG_CLASS, /* flags */
    0x006D6517, /* code */
    MI_T("MongoDB_Server_Database"), /* name */
    MongoDB_Server_Database_quals, /* qualifiers */
    MI_COUNT(MongoDB_Server_Database_quals), /* numQualifiers */
    MongoDB_Server_Database_props, /* properties */
    MI_COUNT(MongoDB_Server_Database_props), /* numProperties */
    sizeof(MongoDB_Server_Database), /* size */
    NULL, /* superClass */
    NULL, /* superClassDecl */
    NULL, /* methods */
    0, /* numMethods */
    &schemaDecl, /* schema */
    &MongoDB_Server_Database_funcs, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** MongoDB_Server_Statistics
**
**==============================================================================
*/

/* property MongoDB_Server_Statistics.HostName */
static MI_CONST MI_PropertyDecl MongoDB_Server_Statistics_HostName_prop =
{
    MI_FLAG_PROPERTY|MI_FLAG_KEY, /* flags */
    0x00686508, /* code */
    MI_T("HostName"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(MongoDB_Server_Statistics, HostName), /* offset */
    MI_T("MongoDB_Server_Statistics"), /* origin */
    MI_T("MongoDB_Server_Statistics"), /* propagator */
    NULL,
};

/* property MongoDB_Server_Statistics.ProcessName */
static MI_CONST MI_PropertyDecl MongoDB_Server_Statistics_ProcessName_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0070650B, /* code */
    MI_T("ProcessName"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_STRING, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(MongoDB_Server_Statistics, ProcessName), /* offset */
    MI_T("MongoDB_Server_Statistics"), /* origin */
    MI_T("MongoDB_Server_Statistics"), /* propagator */
    NULL,
};

/* property MongoDB_Server_Statistics.UpTimeinSeconds */
static MI_CONST MI_PropertyDecl MongoDB_Server_Statistics_UpTimeinSeconds_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0075730F, /* code */
    MI_T("UpTimeinSeconds"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT64, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(MongoDB_Server_Statistics, UpTimeinSeconds), /* offset */
    MI_T("MongoDB_Server_Statistics"), /* origin */
    MI_T("MongoDB_Server_Statistics"), /* propagator */
    NULL,
};

/* property MongoDB_Server_Statistics.RegularAssert */
static MI_CONST MI_PropertyDecl MongoDB_Server_Statistics_RegularAssert_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0072740D, /* code */
    MI_T("RegularAssert"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(MongoDB_Server_Statistics, RegularAssert), /* offset */
    MI_T("MongoDB_Server_Statistics"), /* origin */
    MI_T("MongoDB_Server_Statistics"), /* propagator */
    NULL,
};

/* property MongoDB_Server_Statistics.WarningAssert */
static MI_CONST MI_PropertyDecl MongoDB_Server_Statistics_WarningAssert_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0077740D, /* code */
    MI_T("WarningAssert"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(MongoDB_Server_Statistics, WarningAssert), /* offset */
    MI_T("MongoDB_Server_Statistics"), /* origin */
    MI_T("MongoDB_Server_Statistics"), /* propagator */
    NULL,
};

/* property MongoDB_Server_Statistics.MessageAssert */
static MI_CONST MI_PropertyDecl MongoDB_Server_Statistics_MessageAssert_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x006D740D, /* code */
    MI_T("MessageAssert"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(MongoDB_Server_Statistics, MessageAssert), /* offset */
    MI_T("MongoDB_Server_Statistics"), /* origin */
    MI_T("MongoDB_Server_Statistics"), /* propagator */
    NULL,
};

/* property MongoDB_Server_Statistics.UserAssert */
static MI_CONST MI_PropertyDecl MongoDB_Server_Statistics_UserAssert_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0075740A, /* code */
    MI_T("UserAssert"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(MongoDB_Server_Statistics, UserAssert), /* offset */
    MI_T("MongoDB_Server_Statistics"), /* origin */
    MI_T("MongoDB_Server_Statistics"), /* propagator */
    NULL,
};

/* property MongoDB_Server_Statistics.RolloverAssert */
static MI_CONST MI_PropertyDecl MongoDB_Server_Statistics_RolloverAssert_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x0072740E, /* code */
    MI_T("RolloverAssert"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(MongoDB_Server_Statistics, RolloverAssert), /* offset */
    MI_T("MongoDB_Server_Statistics"), /* origin */
    MI_T("MongoDB_Server_Statistics"), /* propagator */
    NULL,
};

/* property MongoDB_Server_Statistics.CurrentConnections */
static MI_CONST MI_PropertyDecl MongoDB_Server_Statistics_CurrentConnections_prop =
{
    MI_FLAG_PROPERTY, /* flags */
    0x00637312, /* code */
    MI_T("CurrentConnections"), /* name */
    NULL, /* qualifiers */
    0, /* numQualifiers */
    MI_UINT32, /* type */
    NULL, /* className */
    0, /* subscript */
    offsetof(MongoDB_Server_Statistics, CurrentConnections), /* offset */
    MI_T("MongoDB_Server_Statistics"), /* origin */
    MI_T("MongoDB_Server_Statistics"), /* propagator */
    NULL,
};

static MI_PropertyDecl MI_CONST* MI_CONST MongoDB_Server_Statistics_props[] =
{
    &MongoDB_Server_Statistics_HostName_prop,
    &MongoDB_Server_Statistics_ProcessName_prop,
    &MongoDB_Server_Statistics_UpTimeinSeconds_prop,
    &MongoDB_Server_Statistics_RegularAssert_prop,
    &MongoDB_Server_Statistics_WarningAssert_prop,
    &MongoDB_Server_Statistics_MessageAssert_prop,
    &MongoDB_Server_Statistics_UserAssert_prop,
    &MongoDB_Server_Statistics_RolloverAssert_prop,
    &MongoDB_Server_Statistics_CurrentConnections_prop,
};

static MI_CONST MI_ProviderFT MongoDB_Server_Statistics_funcs =
{
  (MI_ProviderFT_Load)MongoDB_Server_Statistics_Load,
  (MI_ProviderFT_Unload)MongoDB_Server_Statistics_Unload,
  (MI_ProviderFT_GetInstance)MongoDB_Server_Statistics_GetInstance,
  (MI_ProviderFT_EnumerateInstances)MongoDB_Server_Statistics_EnumerateInstances,
  (MI_ProviderFT_CreateInstance)MongoDB_Server_Statistics_CreateInstance,
  (MI_ProviderFT_ModifyInstance)MongoDB_Server_Statistics_ModifyInstance,
  (MI_ProviderFT_DeleteInstance)MongoDB_Server_Statistics_DeleteInstance,
  (MI_ProviderFT_AssociatorInstances)NULL,
  (MI_ProviderFT_ReferenceInstances)NULL,
  (MI_ProviderFT_EnableIndications)NULL,
  (MI_ProviderFT_DisableIndications)NULL,
  (MI_ProviderFT_Subscribe)NULL,
  (MI_ProviderFT_Unsubscribe)NULL,
  (MI_ProviderFT_Invoke)NULL,
};

static MI_CONST MI_Char* MongoDB_Server_Statistics_Version_qual_value = MI_T("1.0.0");

static MI_CONST MI_Qualifier MongoDB_Server_Statistics_Version_qual =
{
    MI_T("Version"),
    MI_STRING,
    MI_FLAG_ENABLEOVERRIDE|MI_FLAG_TRANSLATABLE|MI_FLAG_RESTRICTED,
    &MongoDB_Server_Statistics_Version_qual_value
};

static MI_Qualifier MI_CONST* MI_CONST MongoDB_Server_Statistics_quals[] =
{
    &MongoDB_Server_Statistics_Version_qual,
};

/* class MongoDB_Server_Statistics */
MI_CONST MI_ClassDecl MongoDB_Server_Statistics_rtti =
{
    MI_FLAG_CLASS, /* flags */
    0x006D7319, /* code */
    MI_T("MongoDB_Server_Statistics"), /* name */
    MongoDB_Server_Statistics_quals, /* qualifiers */
    MI_COUNT(MongoDB_Server_Statistics_quals), /* numQualifiers */
    MongoDB_Server_Statistics_props, /* properties */
    MI_COUNT(MongoDB_Server_Statistics_props), /* numProperties */
    sizeof(MongoDB_Server_Statistics), /* size */
    NULL, /* superClass */
    NULL, /* superClassDecl */
    NULL, /* methods */
    0, /* numMethods */
    &schemaDecl, /* schema */
    &MongoDB_Server_Statistics_funcs, /* functions */
    NULL, /* owningClass */
};

/*
**==============================================================================
**
** __mi_server
**
**==============================================================================
*/

MI_Server* __mi_server;
/*
**==============================================================================
**
** Schema
**
**==============================================================================
*/

static MI_ClassDecl MI_CONST* MI_CONST classes[] =
{
    &MongoDB_Server_rtti,
    &MongoDB_Server_Database_rtti,
    &MongoDB_Server_Statistics_rtti,
};

MI_SchemaDecl schemaDecl =
{
    NULL, /* qualifierDecls */
    0, /* numQualifierDecls */
    classes, /* classDecls */
    MI_COUNT(classes), /* classDecls */
};

/*
**==============================================================================
**
** MI_Server Methods
**
**==============================================================================
*/

MI_Result MI_CALL MI_Server_GetVersion(
    MI_Uint32* version){
    return __mi_server->serverFT->GetVersion(version);
}

MI_Result MI_CALL MI_Server_GetSystemName(
    const MI_Char** systemName)
{
    return __mi_server->serverFT->GetSystemName(systemName);
}

