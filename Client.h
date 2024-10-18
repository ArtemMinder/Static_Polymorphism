#pragma once
#include <vector>
#include <string>
#include "Reader.h"
#include "Buffer.h"
#include "IEncryptor.h"
#include "Synchronisation.h"
#include "Processor.h"

class Client : public Processor<Client> 
{
public:
    Client(const std::string& server_address, int port, const std::vector<std::string>& files, IEncryptor* encryptor, ILogger* logger);

    bool WaitNextData();
    void ProcessData();
    void NotifyComplete();

private:
    std::vector<std::string> files_;
    size_t current_file_index_ = 0;
    Reader* reader_ = nullptr;
    Buffer buffer_;
    IEncryptor* encryptor_;
    ILogger* logger_;
    std::string server_address_;
    int port_;
};
