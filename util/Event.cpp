#include "Event.h"

using namespace Util;

Event::Event()
{
}

Event::~Event()
{
}

// interface

void Event::pulse() const
{
    _event.notify_one();
}

void Event::set() const
{
    _event.notify_all();
}

void Event::wait() const
{
    ScopedLock lock(_lock);

    _event.wait(lock);
}

bool Event::wait(size_t timeout) const
{
    ScopedLock lock(_lock);

    std::cv_status res = _event.wait_for(lock, 
        std::chrono::milliseconds(timeout));

    return (res == std::cv_status::no_timeout);
}