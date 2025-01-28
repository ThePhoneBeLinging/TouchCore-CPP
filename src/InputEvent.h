//
// Created by eal on 28/01/25.
//

#ifndef INPUTEVENT_H
#define INPUTEVENT_H
#include <bits/types/struct_timeval.h>

struct input_event {
    struct timeval time;
    unsigned short type;
    unsigned short code;
    unsigned int value;
};

#endif //INPUTEVENT_H
