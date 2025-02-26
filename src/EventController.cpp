//
// Created by eal on 28/01/25.
//

#include "TouchCore-CPP/EventController.h"
#include <iostream>
#include <linux/input.h>

EventController::EventController() : absEventController_(std::make_unique<AbsEventController>())
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
                absEventController_->handleEvent(event);
                break;
            }
        default:
            std::cout << "Unknown Event: " << event.type << std::endl;
        }
}

std::vector<std::pair<int, int>> EventController::getFingerPositions()
{
    return absEventController_->getFingerPositions();
}
