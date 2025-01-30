//
// Created by eal on 28/01/25.
//

#ifndef EVENTCONTROLLER_H
#define EVENTCONTROLLER_H
#include "linux/input.h"


class EventController
{
public:
    EventController() = default;
    void notifyOfEvent(input_event event);
private:
    int activeSlot_;
};



#endif //EVENTCONTROLLER_H
