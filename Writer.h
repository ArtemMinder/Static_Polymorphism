#pragma once
#include <string>
#include <fstream>
#include "ILogger.h"

class Writer
{
public:
    explicit Writer(const std::string& filename, ILogger* logger);
    void write(const std::string& data);

private:
    std::ofstream file_;
    ILogger* logger_;
};
