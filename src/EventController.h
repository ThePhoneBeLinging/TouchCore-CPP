//
// Created by eal on 28/01/25.
//

#ifndef EVENTCONTROLLER_H
#define EVENTCONTROLLER_H
#include "InputEvent.h"


class EventController
{
public:
    EventController() = default;
    void notifyOfEvent(input_event event);
};



#endif //EVENTCONTROLLER_H
