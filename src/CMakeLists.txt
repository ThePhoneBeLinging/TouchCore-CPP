cmake_minimum_required(VERSION 3.25)
project(TouchScreenSupport)


add_library(TouchScreenSupport
        EventListener.cpp
        EventController.cpp
        AbsEventController.cpp
        )


target_include_directories(TouchScreenSupport PUBLIC include)
target_link_libraries(TouchScreenSupport PRIVATE Utility)