#include "Synchronisation.h"

void Synchronisation::lock() 
{
    mtx_.lock();
}

void Synchronisation::unlock()
{
    mtx_.unlock();
}

void Synchronisation::wait() 
{
    std::unique_lock<std::mutex> lock(mtx_);
    cv_.wait(lock, [this] { return ready_; });
}

void Synchronisation::notify() 
{
    {
        std::lock_guard<std::mutex> lock(mtx_);
        ready_ = true;
    }
    cv_.notify_all();
}
