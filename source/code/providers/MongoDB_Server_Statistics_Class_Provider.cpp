/* @migen@ */
#include <MI.h>
#include "MongoDB_Server_Statistics_Class_Provider.h"

#include "mongo/client/dbclient.h"
#include "MongoAuth.h"
#include "MongoUtils.h"

#include <scxcorelib/scxcmn.h>
#include <scxcorelib/scxnameresolver.h>
#include <scxcorelib/stringaid.h>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>

#include<algorithm>
#include<vector>


MI_BEGIN_NAMESPACE

/**  Obtain statistical data of a single server
     \param[in] mongohandle Connection handler to the database server
     \param[in] context     OMI context for posting instances to
*/
static void EnumerateServerStatistic(
    MongoAuthentication::MongoHandler & mongoHandle,
    Context & context)
{
    // Obtain Server details like Hostname, ServerLocalTime, Serverversion
    mongo::BSONObj dbCommand;
    mongo::BSONObj retValue;

    dbCommand  = BSON("serverStatus" << 1 );
    mongoHandle.ExecuteCommand("admin", dbCommand, retValue);

    // Append host:port to hostname
    std::string instanceID = mongoHandle.GetServerName();
    instanceID += ":";
    instanceID.append(retValue.getStringField("host"));

    // Populate hostname, localtime and version
    MongoDB_Server_Statistics_Class mongoServerStats;
    mongoServerStats.HostName_value( instanceID.c_str() );
    mongoServerStats.ProcessName_value(retValue.getStringField("process")); 
    mongoServerStats.UpTimeinSeconds_value((retValue.getFieldDotted("uptime")).numberLong());
    mongoServerStats.RegularAssert_value((retValue.getFieldDotted("asserts.regular")).numberLong());
    mongoServerStats.WarningAssert_value((retValue.getFieldDotted("asserts.warning")).numberLong());
    mongoServerStats.MessageAssert_value((retValue.getFieldDotted("asserts.msg")).numberLong());
    mongoServerStats.UserAssert_value((retValue.getFieldDotted("asserts.user")).numberLong());
    mongoServerStats.RolloverAssert_value((retValue.getFieldDotted("asserts.rollovers")).numberLong());
    mongoServerStats.CurrentConnections_value((retValue.getFieldDotted("connections.current")).numberLong());
  
    context.Post(mongoServerStats);

}

MongoDB_Server_Statistics_Class_Provider::MongoDB_Server_Statistics_Class_Provider(
    Module* module) :
    m_Module(module)
{
}

MongoDB_Server_Statistics_Class_Provider::~MongoDB_Server_Statistics_Class_Provider()
{
}

void MongoDB_Server_Statistics_Class_Provider::Load(
        Context& context)
{
    Mongo::LogStartup();

    context.Post(MI_RESULT_OK);
}

void MongoDB_Server_Statistics_Class_Provider::Unload(
        Context& context)
{
    context.Post(MI_RESULT_OK);
}

void MongoDB_Server_Statistics_Class_Provider::EnumerateInstances(
    Context& context,
    const String& nameSpace,
    const PropertySet& propertySet,
    bool keysOnly,
    const MI_Filter* filter)
{
    SCXCoreLib::SCXLogHandle hLog = SCXCoreLib::SCXLogHandleFactory::GetLogHandle(L"mongo.provider.serverStatistics");

    CIM_PEX_BEGIN // Error handling
    {
    // Authentication to Mongo DB
    MongoAuthentication::MongoAuth mongoAuth;

    std::vector<unsigned int> portList;
    mongoAuth.GetPortList(portList);

    // For each server (hot:port) find statistics
    for ( std::vector<unsigned int>::const_iterator it = portList.begin(); it != portList.end(); ++it ) {
        std::wstring value;
        mongoAuth.GetEntry(*it,value);

        MongoAuthentication::MongoHandler mongoHandle(value,*it);


        // Enumerate a single Server
        EnumerateServerStatistic(mongoHandle, context);
    }

    context.Post(MI_RESULT_OK);
    }
    CIM_PEX_END( L"MongoDB_Server_Statistics_Class_Provider::EnumerateInstances" , hLog );
}

void MongoDB_Server_Statistics_Class_Provider::GetInstance(
    Context& context,
    const String& nameSpace,
    const MongoDB_Server_Statistics_Class& instanceName,
    const PropertySet& propertySet)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void MongoDB_Server_Statistics_Class_Provider::CreateInstance(
    Context& context,
    const String& nameSpace,
    const MongoDB_Server_Statistics_Class& newInstance)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void MongoDB_Server_Statistics_Class_Provider::ModifyInstance(
    Context& context,
    const String& nameSpace,
    const MongoDB_Server_Statistics_Class& modifiedInstance,
    const PropertySet& propertySet)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void MongoDB_Server_Statistics_Class_Provider::DeleteInstance(
    Context& context,
    const String& nameSpace,
    const MongoDB_Server_Statistics_Class& instanceName)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}


MI_END_NAMESPACE
