/* @migen@ */
#include <MI.h>
#include "MongoDB_Server_Class_Provider.h"

#include "mongo/client/dbclient.h"
#include "MongoAuth.h"
#include "MongoUtils.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>

#include <scxcorelib/scxcmn.h>
#include <scxcorelib/scxnameresolver.h>
#include <scxcorelib/stringaid.h>

#include<algorithm>
#include<vector>

MI_BEGIN_NAMESPACE

/**  Obtain details of a single server
     \param[in] mongohandle Connection handler to the database server
     \param[in] context     OMI context for posting instances to
*/
static void EnumerateSingleServer(
    MongoAuthentication::MongoHandler & mongoHandle,
    Context & context)
{
    // Obtain Server details like Hostname, ServerLocalTime, Serverversion
    mongo::BSONObj dbCommand;
    mongo::BSONObj retValue;

    dbCommand  = BSON("serverStatus" << 1 );
    mongoHandle.ExecuteCommand("admin", dbCommand, retValue);

    std::string instanceID = mongoHandle.GetServerName();
    instanceID += ":";
    instanceID.append(retValue.getStringField("host"));
    // Populate hostname, localtime and version
    MongoDB_Server_Class mongoServer;
    mongoServer.Hostname_value( instanceID.c_str()); 
    mongoServer.ServerVersion_value(retValue.getStringField("version"));
  
    // Check if server is running as master 
    dbCommand = BSON("isMaster" << 1 );
    mongoHandle.ExecuteCommand("admin", dbCommand, retValue);
    
    mongoServer.IsMaster_value(retValue.getBoolField("ismaster"));

    // Post server details to OMI Server
    context.Post(mongoServer);

}

MongoDB_Server_Class_Provider::MongoDB_Server_Class_Provider(
    Module* module) :
    m_Module(module)
{
}

MongoDB_Server_Class_Provider::~MongoDB_Server_Class_Provider()
{
}

void MongoDB_Server_Class_Provider::Load(
        Context& context)
{
    Mongo::LogStartup();

    context.Post(MI_RESULT_OK);
}

void MongoDB_Server_Class_Provider::Unload(
        Context& context)
{
    context.Post(MI_RESULT_OK);
}

void MongoDB_Server_Class_Provider::EnumerateInstances(
    Context& context,
    const String& nameSpace,
    const PropertySet& propertySet,
    bool keysOnly,
    const MI_Filter* filter)
{
    SCXCoreLib::SCXLogHandle hLog = SCXCoreLib::SCXLogHandleFactory::GetLogHandle(L"mongo.provider.server");

    CIM_PEX_BEGIN //Error handling
    {
    // Authentication to Mongo DB
    MongoAuthentication::MongoAuth mongoAuth;

    std::vector<unsigned int> portList; 
    mongoAuth.GetPortList(portList);

    // For each host:port, obtaing server details 
    for ( std::vector<unsigned int>::const_iterator it = portList.begin(); it != portList.end(); ++it ) {
        std::wstring value;
        mongoAuth.GetEntry(*it,value);
	
	MongoAuthentication::MongoHandler mongoHandle(value,*it);
        
	// Enumerate a single Server
        EnumerateSingleServer(mongoHandle, context);
    }

    context.Post(MI_RESULT_OK);
    }
    CIM_PEX_END( L"MongoDB_Server_Class_Provider::EnumerateInstances" , hLog );
}

void MongoDB_Server_Class_Provider::GetInstance(
    Context& context,
    const String& nameSpace,
    const MongoDB_Server_Class& instanceName,
    const PropertySet& propertySet)
{
    // To Be Done
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void MongoDB_Server_Class_Provider::CreateInstance(
    Context& context,
    const String& nameSpace,
    const MongoDB_Server_Class& newInstance)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void MongoDB_Server_Class_Provider::ModifyInstance(
    Context& context,
    const String& nameSpace,
    const MongoDB_Server_Class& modifiedInstance,
    const PropertySet& propertySet)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void MongoDB_Server_Class_Provider::DeleteInstance(
    Context& context,
    const String& nameSpace,
    const MongoDB_Server_Class& instanceName)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}


MI_END_NAMESPACE
