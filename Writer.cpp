#include "Writer.h"

Writer::Writer(const std::string& filename, ILogger* logger) : logger_(logger) 
{
    file_.open(filename, std::ios::binary | std::ios::app);
    if (file_.is_open()) 
    {
        logger_->log("File opened for writing: " + filename);
    }
    else
    {
        logger_->log("Failed to open file: " + filename);
    }
}

void Writer::write(const std::string& data) 
{
    file_.write(data.c_str(), data.size());
    logger_->log("Written data chunk: " + std::to_string(data.size()) + " bytes");
}
