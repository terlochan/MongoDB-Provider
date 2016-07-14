/**

    \brief       Initializes logging for the Mongo provider

*/
/*----------------------------------------------------------------------------*/

#include <iostream> 
#include <scxcorelib/scxlog.h>

namespace Mongo
{
    /*----------------------------------------------------------------------------*/
    /**
       Log the startup message once regardless of how many times called

       This function will be called from all provider ctors except RunAs to
       provide one initial log, regardless of how many times called.

    */

    void LogStartup(void)
    {
        static bool bLoggedInitMessage = false;
        if (!bLoggedInitMessage)
        {
            SCXCoreLib::SCXLogHandle log = SCXCoreLib::SCXLogHandleFactory::GetLogHandle(L"mongo.provider");
            SCX_LOGINFO(log, L"MongoDB Provider Module loaded");
	    std::cout<<"Logstart Up"<<std::endl;

         bLoggedInitMessage = false; 
        }
    }
}

