//
// Created by eal on 30/01/25.
//

#ifndef FINGER_H
#define FINGER_H



class Finger
{
public:
    Finger() = default;
    void setX(int x);
    [[nodiscard]] int getX() const;
    void setY(int y);
    [[nodiscard]] int getY() const;
private:
    int x_;
    int y_;
};



#endif //FINGER_H
