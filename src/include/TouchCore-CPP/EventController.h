//
// Created by eal on 28/01/25.
//

#ifndef EVENTCONTROLLER_H
#define EVENTCONTROLLER_H
#include <memory>

#include "AbsEventController.h"
#include "linux/input.h"


class EventController
{
public:
    EventController();
    void notifyOfEvent(const input_event& event);
    std::vector<std::pair<int,int>> getFingerPositions();
private:
    std::unique_ptr<AbsEventController> absEventController_;
};



#endif //EVENTCONTROLLER_H
