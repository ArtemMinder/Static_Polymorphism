#include <iostream>
#include "Client.h"
#include "Server.h"
#include "console_logger.h"
#include "AES_Encryptor.h"

int main(int argc, char* argv[]) 
{
    ConsoleLogger logger;
    AesEncryptor encryptor;

    if (argc < 2) 
    {
        logger.log("Usage: Client_Server_Networking.exe [client/server] ...");
        return 1;
    }

    std::string mode = argv[1];

    if (mode == "client")
    {
        if (argc < 4) 
        {
            logger.log("Usage for client: Client_Server_Networking.exe client <server_address> <port> <file1> <file2> ...");
            return 1;
        }

        std::string server_address = argv[2];
        int port = std::stoi(argv[3]);
        std::vector<std::string> files;

        for (int i = 4; i < argc; ++i)
        {
            files.push_back(argv[i]);
        }

        Client client(server_address, port, files, &encryptor, &logger);
        client.run();
    }
    else if (mode == "server") 
    {
        if (argc < 3) 
        {
            logger.log("Usage for server: Client_Server_Networking.exe server <port>");
            return 1;
        }

        int port = std::stoi(argv[2]);
        Server server(port, "./received_files", &encryptor, &logger);
        server.run();
    }
    else
    {
        logger.log("Unknown mode: " + mode);
        return 1;
    }

    return 0;
}
