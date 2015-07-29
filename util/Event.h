#pragma once

#include <mutex>
#include <condition_variable>

namespace Util {

class Event
{
public:
    Event();
    ~Event();

public:  // interface
    void pulse()                const;
    void set()                  const;
    void wait()                 const;
    bool wait(size_t timeout)   const;

private: // internal typedefs
    typedef std::unique_lock<std::mutex> ScopedLock;

private: // member variables
    mutable std::mutex              _lock;
    mutable std::condition_variable _event;
};

} // Util namespace