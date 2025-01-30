//
// Created by eal on 28/01/25.
//

#ifndef EVENTCONTROLLER_H
#define EVENTCONTROLLER_H
#include "FingersObject.h"
#include "linux/input.h"


class EventController
{
public:
    EventController();
    void notifyOfEvent(const input_event& event);
private:
    void handleAbsEvents(const input_event& event);
    std::unique_ptr<FingersObject> fingers_;
    int activeSlot_;
};



#endif //EVENTCONTROLLER_H
