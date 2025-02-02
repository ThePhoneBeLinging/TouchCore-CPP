//
// Created by eal on 30/01/25.
//

#include "AbsEventController.h"

#include <iostream>
#include <ostream>

AbsEventController::AbsEventController() : activeSlot_(0)
{
    // Change the value to allow for a different amount of fingers at the same time.
    // eg. some screens might only handle 2 to 3.
    fingerPositions_.resize(5);
}

void AbsEventController::handleEvent(const input_event& event)
{
    std::cout << "Starting event handling with: " << activeSlot_ << std::endl;
    switch (event.code)
    {
        case ABS_X:
        {
            fingerPositions_[activeSlot_]->first = event.value;
            break;
        }
        case ABS_Y:
        {
            fingerPositions_[activeSlot_]->second = event.value;
            break;
        }
        case ABS_MT_SLOT:
        {
            activeSlot_ = event.value;
            break;
        }
        case ABS_MT_POSITION_X:
        {
            if (fingerPositions_[activeSlot_] == nullptr)
            {
                fingerPositions_[activeSlot_] = new std::pair(event.value, -1);
            }
            else
            {
                fingerPositions_[activeSlot_]->first = event.value;
            }
            break;
        }
        case ABS_MT_POSITION_Y:
        {
            if (fingerPositions_[activeSlot_] == nullptr)
            {
                fingerPositions_[activeSlot_] = new std::pair(-1, event.value);
            }
            else
            {
                fingerPositions_[activeSlot_]->second = event.value;
            }
            break;
        }
        case ABS_MT_TRACKING_ID:
        {
            if (event.value == -1)
            {
                delete fingerPositions_[activeSlot_];
            }
            break;
        }
        case ABS_MT_TOUCH_MAJOR:
        {
            // For now, I ignore this
            break;
        }
        case ABS_MT_WIDTH_MAJOR:
        {
            // For now, I ignore this
            break;
        }
        default:
        {
            std::cout << "Unknown ABS event code: " << event.code << std::endl;
            break;
        }
    }
    int activeFingers = 0;
    for (auto val : fingerPositions_)
    {
        if (val != nullptr)
        {
            activeFingers++;
        }
    }
    std::cout << "ACtive fingers: " << activeFingers << std::endl;
}
