#include "util/Event.h"
#include <functional>
#include <ppltasks.h>
#include <thread>
#include <chrono>
#include <iostream>

using namespace Util;
using namespace concurrency;

static void doWork(std::function<void(bool succeded)> onCompleted)
{
    create_task([=]()
    {
        std::cout << "simulate some work..." << std::endl;

        for (size_t i = 0; i < 5; i++)
        {
            std::cout << i << std::endl;

            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
        
        onCompleted(true);
    });
}

int main()
{
    Event event;

    doWork([&](bool succeded)
    {
        event.set();
    });

    bool res = event.wait(2000);

    std::cout << "completed ";

    if (res)
    {
        std::cout << "successfully." << std::endl;
    }
    else
    {
        std::cout << "with error." << std::endl;
    }
}