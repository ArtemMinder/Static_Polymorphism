#include "Server.h"

Server::Server(int port, const std::string& destination_folder, IEncryptor* decryptor, ILogger* logger)
    : port_(port), destination_folder_(destination_folder), decryptor_(decryptor), logger_(logger) 
{
    logger_->log("Server created with port: " + std::to_string(port) + " and destination folder: " + destination_folder);
}

bool Server::WaitNextData() 
{
    // Code to wait for incoming file data would be here
    return true; // Always return true for now, as we're simulating file reception
}

void Server::ProcessData()
{
    decryptor_->decrypt(buffer_);
    logger_->log("Received file data decrypted.");
}

void Server::NotifyComplete()
{
    if (!writer_) {
        writer_ = new Writer(destination_folder_ + "/received_file.txt", logger_);
    }
    writer_->write(buffer_.get_data());
    logger_->log("File data written to disk.");
}
