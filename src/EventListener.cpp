//
// Created by eal on 28/01/25.
//
#include <fcntl.h>
#include <unistd.h>
#include <poll.h>
#include <linux/input.h>
#include <cstring>
#include <cstdio>
#include <sys/time.h>
#include "TouchScreenSupport/EventListener.h"

#include <stdexcept>

EventListener::EventListener(const std::string& pathToFile, const std::shared_ptr<EventController>& eventController) : eventController_(eventController),keepRunning_(true)
{
    const int timeout_ms = -1;
    const char* input_dev = pathToFile.c_str();
    int st;
    int ret;
    struct pollfd fds[1];
    fds[0].fd = open(input_dev, O_RDONLY|O_NONBLOCK);
    if(fds[0].fd<0)
    {
        printf("error unable open for reading '%s'\n",input_dev);
        throw std::runtime_error("error unable open for reading");
    }
    const int input_size = sizeof(struct input_event);
    printf("input_size=%d\n", input_size);
    auto* input_data = new input_event();
    memset(input_data,0,input_size);
    fds[0].events = POLLIN;

    auto runFunction = [&ret,&fds,&input_data, this] () -> void
    {
        while(keepRunning_)
        {
            ret = poll(fds, 1, timeout_ms);
            if(ret>0)
            {
                if(fds[0].revents)
                {
                    ssize_t r = read(fds[0].fd,input_data,input_size);
                    if(r<0)
                    {
                        printf("error %d\n",(int)r);
                        break;
                    }
                    else
                    {
                        eventController_->notifyOfEvent(*input_data);
                        memset(input_data,0,input_size);
                    }
                }
                else
                {
                    printf("error\n");
                }
            }
            else
            {
                printf("timeout\n");
            }
        }
        delete input_data;
    };
    listenerThread_ = std::thread(runFunction);
}

EventListener::~EventListener()
{
    keepRunning_ = false;
    cv_.notify_all();
    listenerThread_.join();
}
