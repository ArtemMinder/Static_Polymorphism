#include "Buffer.h"

void Buffer::set_data(const std::string& data) 
{
    data_ = data;
}

std::string& Buffer::get_data()
{
    return data_;
}
