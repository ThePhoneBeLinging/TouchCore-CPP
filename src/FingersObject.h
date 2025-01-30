//
// Created by eal on 30/01/25.
//

#ifndef FINGERSOBJECT5_H
#define FINGERSOBJECT5_H
#include <memory>
#include <vector>

#include "Finger.h"


class FingersObject
{
public:
    explicit FingersObject(int maxActiveFingers);
    void startTouch(int fingerId, std::shared_ptr<Finger> finger);
    void stopTouch(int fingerId);
private:
    std::vector<std::shared_ptr<Finger>> fingers_;
};



#endif //FINGERSOBJECT5_H
