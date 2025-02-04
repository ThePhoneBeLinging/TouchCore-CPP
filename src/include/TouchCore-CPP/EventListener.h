//
// Created by eal on 28/01/25.
//

#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H
#include <condition_variable>
#include <string>
#include <thread>

#include "EventController.h"


class EventListener
{
public:
    explicit EventListener(const std::string& pathToFile, const std::shared_ptr<EventController>& eventController);
    ~EventListener();
private:
    std::shared_ptr<EventController> eventController_;
    std::atomic_bool keepRunning_;
    std::thread listenerThread_;
    std::condition_variable cv_;
};



#endif //EVENTLISTENER_H
