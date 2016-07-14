/* @migen@ */
#include <MI.h>
#include "MongoDB_Server_Database_Class_Provider.h"

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

/**
   Enumerate single instance of Mongo DB database given name of the database
   \param[in] mongoHandle   Connection handler to the database
   \param[in] context       OMI context for posting instances to
   \param[in] instanceName  Instance class for Mongo DB

*/
static void EnumerateSingleDatabase(
    MongoAuthentication::MongoHandler & mongoHandle,
    Context & context,
    const MongoDB_Server_Database_Class & instanceName)
{

    // MongoDB command to be executed
    mongo::BSONObj dbCommand = BSON("dbstats" << 1 << "scale" << 1);


    // JSON tree format of the document returned by MongoDB after command execution    
    boost::property_tree::ptree dbTree;
    mongoHandle.ExecuteCommand(instanceName.DatabaseName_value().Str(), dbCommand, dbTree);

    // Append host:port to DBname
    std::string instanceID = mongoHandle.GetServerName();
    instanceID += ":";
    instanceID.append(instanceName.DatabaseName_value().Str());

    /* Populate database name, number of collections and disk space in bytes into MongoDB_Server_Database_Class

        instance of MongoDB_Server_Database
        {
            [Key] DatabaseName=<dbname>
            NumberOfCollections=<number>
            DiskSpaceInbytes=<size>
        }

    */
    MongoDB_Server_Database_Class dbInstance;
    dbInstance.DatabaseName_value( instanceID.c_str() );
    dbInstance.NumberOfCollections_value(dbTree.get<int>("collections"));
    dbInstance.DiskSpaceInbytes_value(dbTree.get<int>("dataSize"));

    // Post contents to OMI
    context.Post(dbInstance);
}

/**
    Get list of available databases using admin DB
    \param[in]   mongoHandle  Connection handler to the database
    \param[out]  dbList       List containing names of available databases
*/
void GetDatabaseList(
     MongoAuthentication::MongoHandler & mongoHandle,
     std::vector<std::string> & dbList)
{
    // Execute the command on admin database to get list of available DBs
    mongo::BSONObj dbCommand = BSON("listDatabases" << 1 );

    // JSON tree format of the document returned by MongoDB after command execution
    boost::property_tree::ptree dbTree;
    mongoHandle.ExecuteCommand("admin", dbCommand, dbTree);

    // Extract database name from the JSON Tree and push into dbList
    BOOST_FOREACH(boost::property_tree::ptree::value_type &databases, dbTree.get_child("databases"))
    {
        dbList.push_back(databases.second.get<std::string>("name"));
    }
}


MongoDB_Server_Database_Class_Provider::MongoDB_Server_Database_Class_Provider(
    Module* module) :
    m_Module(module)
{
}

MongoDB_Server_Database_Class_Provider::~MongoDB_Server_Database_Class_Provider()
{
}

void MongoDB_Server_Database_Class_Provider::Load(
        Context& context)
{
    Mongo::LogStartup();
    context.Post(MI_RESULT_OK);
}

void MongoDB_Server_Database_Class_Provider::Unload(
        Context& context)
{
    context.Post(MI_RESULT_OK);
}

void MongoDB_Server_Database_Class_Provider::EnumerateInstances(
    Context& context,
    const String& nameSpace,
    const PropertySet& propertySet,
    bool keysOnly,
    const MI_Filter* filter)
{
    SCXCoreLib::SCXLogHandle hLog = SCXCoreLib::SCXLogHandleFactory::GetLogHandle(L"mongo.provider.serverDatabase");
    CIM_PEX_BEGIN //Error handling
    {
    // Get handle to database server
    MongoAuthentication::MongoAuth mongoAuth;

    std::vector<unsigned int> portList;
    mongoAuth.GetPortList(portList);

    /* For each server host:port find the DB details */
    // Iterate through servers
    for ( std::vector<unsigned int>::const_iterator it = portList.begin(); it != portList.end(); ++it ) {
        std::wstring value;
        mongoAuth.GetEntry(*it,value);

        MongoAuthentication::MongoHandler mongoHandle(value,*it);

        // Get a list of availabe databases in the server
        std::vector<std::string> dbList;
        GetDatabaseList(mongoHandle,dbList);

        // Iterate through database within the server
        for ( std::vector<std::string>::iterator db_It = dbList.begin(); db_It != dbList.end(); ++db_It )
        {
            MongoDB_Server_Database_Class instanceName;
            instanceName.DatabaseName_value((*db_It).c_str());
            EnumerateSingleDatabase(mongoHandle, context, instanceName);
        }
    }

    context.Post(MI_RESULT_OK);
    }
    CIM_PEX_END( L"MongoDB_Server_Database_Class_Provider::EnumerateInstances" , hLog );
}

void MongoDB_Server_Database_Class_Provider::GetInstance(
    Context& context,
    const String& nameSpace,
    const MongoDB_Server_Database_Class& instanceName,
    const PropertySet& propertySet)
{
    // To Be Completed
    SCXCoreLib::SCXLogHandle hLog = SCXCoreLib::SCXLogHandleFactory::GetLogHandle(L"mongo.provider.serverDatabase");

    CIM_PEX_BEGIN //Error handling
    {
    if ( !instanceName.DatabaseName_exists() )
    {
        context.Post(MI_RESULT_INVALID_PARAMETER);
        return;
    }

    // Get handle to database server
    MongoAuthentication::MongoAuth mongoAuth;

    std::vector<unsigned int> portList;
    mongoAuth.GetPortList(portList);

    for ( std::vector<unsigned int>::const_iterator it = portList.begin(); it != portList.end(); ++it ) {
        std::wstring value;
        mongoAuth.GetEntry(*it,value);

        MongoAuthentication::MongoHandler mongoHandle(value,*it);

        // Get a list of availabe databases
        std::vector<std::string> dbList;
        GetDatabaseList(mongoHandle, dbList);

        // Find if the given instance database name is present in the list of available databases
        if ( std::find( dbList.begin(), dbList.end(), instanceName.DatabaseName_value().Str()) != dbList.end()  )
        {
            EnumerateSingleDatabase(mongoHandle, context,instanceName);
            context.Post(MI_RESULT_OK);
        }
        // Return with database not found message
        else
        {
            context.Post(MI_RESULT_NOT_FOUND);
        }
    }
    }
    CIM_PEX_END( L"MongoDB_Server_Database_Class_Provider::GetInstance" , hLog );

}

void MongoDB_Server_Database_Class_Provider::CreateInstance(
    Context& context,
    const String& nameSpace,
    const MongoDB_Server_Database_Class& newInstance)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void MongoDB_Server_Database_Class_Provider::ModifyInstance(
    Context& context,
    const String& nameSpace,
    const MongoDB_Server_Database_Class& modifiedInstance,
    const PropertySet& propertySet)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void MongoDB_Server_Database_Class_Provider::DeleteInstance(
    Context& context,
    const String& nameSpace,
    const MongoDB_Server_Database_Class& instanceName)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}


MI_END_NAMESPACE
