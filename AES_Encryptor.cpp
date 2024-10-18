#include "AES_Encryptor.h"
#include <algorithm>

void AesEncryptor::encrypt(Buffer& buffer) 
{
    std::string& data = buffer.get_data();
    std::transform(data.begin(), data.end(), data.begin(), [](char c) { return c + 1; });
}

void AesEncryptor::decrypt(Buffer& buffer) 
{
    std::string& data = buffer.get_data();
    std::transform(data.begin(), data.end(), data.begin(), [](char c) { return c - 1; });
}
