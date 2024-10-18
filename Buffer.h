#pragma once
#include <string>

class Buffer 
{
public:
    void set_data(const std::string& data);
    std::string& get_data();

private:
    std::string data_;
};
