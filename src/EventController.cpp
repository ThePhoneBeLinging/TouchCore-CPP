//
// Created by eal on 28/01/25.
//

#include "EventController.h"
#include <iostream>
#include <linux/input.h>

EventController::EventController() : fingers_(std::make_unique<FingersObject>(5)), activeSlot_(0)
{

}

void EventController::notifyOfEvent(const input_event& event)
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
            handleAbsEvents(event);
            break;
        }
    default:
        std::cout << "Unknown Event: " << event.type << std::endl;
    }


}

void EventController::handleAbsEvents(const input_event& event)
{
    if (event.code == ABS_MT_SLOT)
    {
        activeSlot_ = event.value;
        std::cout << activeSlot_ << std::endl;
    }
    std::cout << event.code << std::endl;
}
