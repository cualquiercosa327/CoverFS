#ifndef CFSHANDLER_H
#define CFSHANDLER_H

#include <future>
#include"CBlockIO.h"
#include"CNetBlockIO.h"
#include"CEncrypt.h"
#include"CCacheIO.h"
#include"CSimpleFS.h"

class CFSHandler
{
    public:
    bool mounted = false;
    
    std::shared_ptr<CAbstractBlockIO> bio;
    std::shared_ptr<CEncrypt> enc;
    std::shared_ptr<CCacheIO> cbio;
    std::shared_ptr<SimpleFilesystem> fs;
    
    std::future<bool> ConnectNET(const std::string hostname, const std::string port);
    std::future<bool> ConnectRAM();
    std::future<int> Mount(int argc, char *argv[], const char *mountpoint);
    std::future<int> Unmount();

    private:
    void Connect();
};



#endif