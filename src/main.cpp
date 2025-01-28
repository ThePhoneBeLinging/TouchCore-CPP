#include <iostream>

#include "EventListener.h"



int main()
{
    std::string pathToInput = "/dev/input/mouse0";//"/dev/input/by-path/platform-1f00080000.i2c-event";
    auto* ic2Listener = new EventListener(pathToInput);
    while (true)
    {
    }
    return 0;
}