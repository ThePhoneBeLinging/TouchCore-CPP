//
// Created by eal on 28/01/25.
//

#include "EventController.h"
#include <iostream>
#include <linux/input.h>

void EventController::notifyOfEvent(input_event event)
{
    switch (event.type)
    {
    case EV_SYN:
        {
            break;
        }
    case EV_KEY:
        {
            break;
        }
    case EV_ABS:
        {
            break;
        }
    default:
        std::cout << "Unknown Event: " << event.type << std::endl;
    }


}

void EventController::handleAbsEvents(input_event event)
{
    if (event.code == ABS_MT_SLOT)
    {
        activeSlot_ = event.value;
    }
    std::cout << activeSlot_ << std::endl;
}
