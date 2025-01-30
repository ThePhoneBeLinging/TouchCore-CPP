cmake_minimum_required(VERSION 3.25)
project(TouchScreenSupport)


add_executable(TouchScreenSupport main.cpp
        EventListener.cpp
        EventListener.h
        EventController.cpp
        EventController.h
        Finger.cpp
        Finger.h
        FingersObject.cpp
        FingersObject.h)