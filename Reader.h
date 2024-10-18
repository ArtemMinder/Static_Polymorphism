#pragma once
#include <string>
#include <fstream>
#include "ILogger.h"

class Reader 
{
public:
    explicit Reader(const std::string& filename, ILogger* logger);
    std::string read_next();
    bool has_next();

private:
    std::ifstream file_;
    ILogger* logger_;
};
