#include "Client.h"

Client::Client(const std::string& server_address, int port, const std::vector<std::string>& files, IEncryptor* encryptor, ILogger* logger)
    : server_address_(server_address), port_(port), files_(files), encryptor_(encryptor), logger_(logger) 
{
    logger_->log("Client created with server address: " + server_address + " and port: " + std::to_string(port));
}

bool Client::WaitNextData()
{
    if (current_file_index_ >= files_.size()) 
    {
        logger_->log("No more files to process.");
        return false;
    }
    if (!reader_ || !reader_->has_next())
    {
        if (reader_) delete reader_;
        reader_ = new Reader(files_[current_file_index_++], logger_);
    }
    return reader_->has_next();
}

void Client::ProcessData() 
{
    buffer_.set_data(reader_->read_next());
    encryptor_->encrypt(buffer_);
    logger_->log("File data encrypted and ready to send.");
}

void Client::NotifyComplete() 
{
    logger_->log("Data sent to server for current chunk.");
    // Code to send buffer data to the server would be here
}
