// File to provide methods for authenticating with MongoDB

#include "mongo/client/dbclient.h"

#include <scxcorelib/scxcmn.h>
#include <scxcorelib/scxconfigfile.h>
#include <scxcorelib/scxexception.h>
#include <scxcorelib/scxfilepath.h>
#include <scxcorelib/scxhandle.h>
#include <scxcorelib/scxlog.h>
#include <scxcorelib/scxuser.h>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#ifndef MONGO_AUTH_H
#define MONGO_AUTH_H

/** Namespace holding function to provide authentication to MongoDB server
*/
namespace MongoAuthentication {

    class MongoAuth {
  
        public:
    
        //! Ctor
        MongoAuth();
    
        /** Get List of Ports specified in the default mongodb provider-configuration file
            \param[out]  portList  Appent list of ports specified in the conf file
        */
        void GetPortList(std::vector<unsigned int>& portList);
    
        /** Obtains the value from mongo provider conf file corresponding to the port specified
            \param[in]   port   Key in the conf file to search for host/user credentials
            \param[out]  value  Value in the form host, user, <pass> corresponding to enrty port
        */
        void GetEntry(const unsigned int& port, std::wstring & value);
    
        private:
    
        /**  Returns the default file containing authentication for MongoDB provider
             \param[out]  filename  Full file path of MongoDB Provider Authentication file
        */
        SCXCoreLib::SCXFilePath GetDefaultAuthFileName();
    
        // Used to load store and retrieve values from provider configuration file
        SCXCoreLib::SCXConfigFile m_config;

    };

    class MongoHandler {

        public:

        /** Establishes connection to MongoDB server using stored credentials host:port details
        */
        MongoHandler();
    
        /** Establishes connection to MongoDB server  using host, port parameters specified
    	    \param[in]  host          IP details of the running MongoDB server
            \param[in]  port          Port in which MongoDB server is running
        */
        MongoHandler(const std::wstring host,const unsigned int port);
    
        /** Execute command using the credentials on a particular database
    	    \param[in]  databaseName  Name of the database to run the command on
     	    \param[in]  dbCommand     Command to be executed
    	    \param[out] dbTree 	  A document as a result of command execution in JSON tree format
        */
        void ExecuteCommand(const std::string & databaseName, const mongo::BSONObj dbCommand, boost::property_tree::ptree & dbTree);
    
        /** Execute command using the credentials on a particular database
            \param[in]  databaseName  Name of the database to run the command on
            \param[in]  dbCommand     Command to be executed
            \param[out] retValue      A document as a result of command execution in BSON format
        */
        void ExecuteCommand(const std::string & databaseName, const mongo::BSONObj dbCommand, mongo::BSONObj & retValue);
   
	/** Return the Name of Server connected to in the form host:port
	    Server Name is set in CTor  
	*/
        std::string GetServerName(); 

        private:
    
        // Handle for MongoDB connection    
        mongo::DBClientConnection dbConnection;

        std::string serverName;
    };
    
}

#endif
