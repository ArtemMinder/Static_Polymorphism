#pragma once
#include <string>
#include "Writer.h"
#include "Buffer.h"
#include "IEncryptor.h"
#include "Synchronisation.h"
#include "Processor.h"

class Server : public Processor<Server> 
{
public:
    Server(int port, const std::string& destination_folder, IEncryptor* decryptor, ILogger* logger);

    bool WaitNextData();
    void ProcessData();
    void NotifyComplete();

private:
    Writer* writer_ = nullptr;
    Buffer buffer_;
    IEncryptor* decryptor_;
    ILogger* logger_;
    std::string destination_folder_;
    int port_;
};
