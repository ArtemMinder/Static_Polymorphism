#include "Reader.h"

Reader::Reader(const std::string& filename, ILogger* logger) : logger_(logger) 
{
    file_.open(filename, std::ios::binary);
    if (file_.is_open()) 
    {
        logger_->log("File opened for reading: " + filename);
    }
    else 
    {
        logger_->log("Failed to open file: " + filename);
    }
}

std::string Reader::read_next() 
{
    char buffer[1024];
    file_.read(buffer, sizeof(buffer));
    std::string data(buffer, file_.gcount());
    logger_->log("Read data chunk: " + std::to_string(data.size()) + " bytes");
    return data;
}

bool Reader::has_next()
{
    return file_ && !file_.eof();
}
