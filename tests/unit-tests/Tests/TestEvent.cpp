#include <stdafx.h>
#include <util/Event.h>
#include <ppltasks.h>

using namespace Util;
using namespace concurrency;

TEST(Event, Wait)
{
    Event event;

    EXPECT_FALSE(event.wait(0));

    event.set();

    EXPECT_FALSE(event.wait(0));

    create_task([&]()
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        event.set();
    });

    EXPECT_TRUE(event.wait(200));

    create_task([&]()
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));

        event.set();
    });

    EXPECT_FALSE(event.wait(100));
}