#pragma once
#include "Synchronisation.h"

template <typename Derived>
class Processor 
{
public:
    void run() 
    {
        Synchronisation sync;
        while (static_cast<Derived*>(this)->WaitNextData()) 
        {
            sync.lock();
            static_cast<Derived*>(this)->ProcessData();
            static_cast<Derived*>(this)->NotifyComplete();
            sync.unlock();
        }
    }
};
