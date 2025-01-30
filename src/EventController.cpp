//
// Created by eal on 28/01/25.
//

#include "EventController.h"
#include <iostream>
#include <linux/input.h>

void EventController::notifyOfEvent(input_event event)
{
    if (event.code == ABS_MT_SLOT)
    {
        activeSlot_ = event.value;
    }
    std::cout << activeSlot_ << std::endl;
}
