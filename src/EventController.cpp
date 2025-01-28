//
// Created by eal on 28/01/25.
//

#include "EventController.h"

#include <iostream>

void EventController::notifyOfEvent(input_event event)
{
    std::cout << event.type << " " << event.code << " " << event.value << "\n";
}
