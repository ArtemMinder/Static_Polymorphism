#pragma once
#include "IEncryptor.h"

class AesEncryptor : public IEncryptor
{
public:
    void encrypt(Buffer& buffer) override;
    void decrypt(Buffer& buffer) override;
};
