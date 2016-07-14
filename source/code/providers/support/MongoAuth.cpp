/**
     Methods for Authenticating with MongoDB Server 
*/

#include "MongoAuth.h"

#include <scxcorelib/scxcmn.h>
#include <scxcorelib/scxconfigfile.h>
#include <scxcorelib/scxexception.h>
#include <scxcorelib/scxfilepath.h>
#include <scxcorelib/scxhandle.h>
#include <scxcorelib/scxlog.h>
#include <scxcorelib/scxuser.h>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>


/**  Returns the default file containing authentication for MongoDB provider
     \param[out]  filename  Full file path of MongoDB Provider Authentication file
*/
SCXCoreLib::SCXFilePath MongoAuthentication::MongoAuth::GetDefaultAuthFileName() {
    SCXCoreLib::SCXFilePath filepath(L"/var/opt/microsoft/mongo-cimprov/auth/mongo-auth");
    return filepath;
}

//! Ctor
MongoAuthentication::MongoAuth::MongoAuth() : m_config(MongoAuthentication::MongoAuth::GetDefaultAuthFileName()) {
   m_config.LoadConfig();
}

/** Get List of Ports specified in the default mongodb provider-configuration file
    \param[out]  portList  Appent list of ports specified in the conf file
*/
void MongoAuthentication::MongoAuth::GetPortList(std::vector<unsigned int>& portList)
{
    portList.clear();

    for (std::map<std::wstring,std::wstring>::const_iterator it = m_config.begin(); it != m_config.end(); ++it)
    {
        // Skip keys that aren't port numbers - and skip the default port too
        if ( it->first == L"0" || std::string::npos != it->first.find_first_not_of(L"0123456789") )
        {
            continue;
        }

        portList.push_back( SCXCoreLib::StrToUInt(it->first) );
    }
}

/** Obtains the value from mongo provider conf file corresponding to the port specified
    \param[in]   port   Key in the conf file to search for host/user credentials
    \param[out]  value  Value in the form host, user, <pass> corresponding to enrty port
*/
void  MongoAuthentication::MongoAuth::GetEntry(const unsigned int& port,std::wstring & value) {

    m_config.GetValue( SCXCoreLib::StrFrom(port), value);

    std::vector<std::wstring> elements;
    SCXCoreLib::StrTokenize( value, elements, L",", true, true );

    //currently not considering credentials (TBD)
    value = elements[0];
}

/**  Establishes connection to MongoDB server using predefined host:port details
         \param[in]  dbConnection  Connection handler for MongoDB server
*/
MongoAuthentication::MongoHandler::MongoHandler() {

    serverName = "127.0.0.1:27017";
    dbConnection.connect ( serverName );

}


/** Establishes connection to MongoDB server  using host, port parameters specified
    \param[in]  host          IP details of the running MongoDB server
    \param[in]  port          Pot in which MongoDB server is running
*/
MongoAuthentication::MongoHandler::MongoHandler(
    const std::wstring host,
    const unsigned int port) 
{
    std::string hostname( host.begin(), host.end() );
    
    std::stringstream ss;
    ss << hostname << ":" << port;
    
    serverName = ss.str();
    dbConnection.connect ( serverName );
}

/** Execute command using the credentials on a particular database
    \param[in]  databaseName  Name of the database to run the command on
    \param[in]  dbCommand     Command to be executed
    \param[out] dbTree        A document as a result of command execution in JSON tree format
*/
void MongoAuthentication::MongoHandler::ExecuteCommand(
    const std::string & databaseName, 
    const mongo::BSONObj dbCommand, 
    boost::property_tree::ptree & dbTree) 
{
    // Execute the command on MongoDB database
    mongo::BSONObj retValue;
    dbConnection.runCommand( databaseName, dbCommand, retValue);

    // Convert the Document returned to JSON format
    std::stringstream stringVal;
    stringVal << retValue.jsonString();
    //boost::property_tree::ptree dbTree;
    boost::property_tree::read_json(stringVal, dbTree);

}

/** Execute command using the credentials on a particular database
    \param[in]  databaseName  Name of the database to run the command on
    \param[in]  dbCommand     Command to be executed
    \param[out] retValue      A document as a result of command execution in BSON format
*/
void MongoAuthentication::MongoHandler::ExecuteCommand(
    const std::string & databaseName, 
    mongo::BSONObj dbCommand, 
    mongo::BSONObj & retValue) 
{
    // Execute the command on MongoDB database
    //mongo::BSONObj retValue;
    dbConnection.runCommand( databaseName, dbCommand, retValue);
}

/** Return the Name of Server connected to in the form host:port
    Server Name is set in CTor
    \param[out] serverName Server name in the form host:name
*/
std::string MongoAuthentication::MongoHandler::GetServerName() {
    return serverName;
}
