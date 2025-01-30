//
// Created by eal on 30/01/25.
//

#include "FingersObject.h"

#include <utility>

FingersObject::FingersObject(const int maxActiveFingers)
{
    fingers_.resize(maxActiveFingers);
}

void FingersObject::startTouch(const int fingerId, std::shared_ptr<Finger> finger)
{
    fingers_[fingerId] = std::move(finger);
}

void FingersObject::stopTouch(const int fingerId)
{
    fingers_[fingerId] = nullptr;
}

