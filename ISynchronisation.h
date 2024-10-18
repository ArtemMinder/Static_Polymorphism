#pragma once

class ISynchronisation
{
public:
    virtual ~ISynchronisation() = default;

    virtual void lock() = 0;
    virtual void unlock() = 0;
    virtual void wait() = 0;
    virtual void notify() = 0;
};
