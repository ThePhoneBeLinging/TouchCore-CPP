//
// Created by eal on 30/01/25.
//

#ifndef ABSEVENTCONTROLLER_H
#define ABSEVENTCONTROLLER_H
#include <utility>
#include <vector>
#include <linux/input.h>


class AbsEventController
{
public:
    AbsEventController();
    void handleEvent(const input_event& event);
private:
    std::vector<std::pair<int,int>*> fingerPositions_;
    int activeSlot_;
};



#endif //ABSEVENTCONTROLLER_H
