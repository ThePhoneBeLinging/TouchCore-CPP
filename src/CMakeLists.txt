cmake_minimum_required(VERSION 3.25)
project(TouchCore-CPP)


add_library(TouchCore-CPP
        EventListener.cpp
        EventController.cpp
        AbsEventController.cpp
        )


target_include_directories(TouchCore-CPP PUBLIC include)
target_link_libraries(TouchCore-CPP PRIVATE Utility)