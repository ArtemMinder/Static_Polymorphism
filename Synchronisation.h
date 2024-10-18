#pragma once
#include <mutex>
#include <condition_variable>

class Synchronisation 
{
public:
    void lock();
    void unlock();
    void wait();
    void notify();

private:
    std::mutex mtx_;
    std::condition_variable cv_;
    bool ready_ = false;
};
