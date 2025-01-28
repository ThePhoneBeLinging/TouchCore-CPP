#include <iostream>

#include "EventListener.h"



int main()
{
    std::string pathToInput = "/dev/input/by-path/platform-1f00080000.i2c-event";
    auto eventController = std::make_shared<EventController>();
    auto* ic2Listener = new EventListener(pathToInput,eventController);
    while (true)
    {
    }
    delete ic2Listener;
    return 0;
}