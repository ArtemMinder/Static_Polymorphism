#pragma once
#include "Buffer.h"

class IEncryptor
{
public:
    virtual ~IEncryptor() = default;
    virtual void encrypt(Buffer& buffer) = 0;
    virtual void decrypt(Buffer& buffer) = 0;
};
