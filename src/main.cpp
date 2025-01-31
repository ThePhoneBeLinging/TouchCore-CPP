#include <fstream>
#include <iostream>
#include <sstream>

#include "EventListener.h"

#include <vector>

#include <linux/input.h>


int main()
{
    std::string pathToInput = "/dev/input/by-path/platform-1f00080000.i2c-event";
    auto eventController = std::make_shared<EventController>();

    std::ifstream inputFile("../../testData.txt");
    std::vector<input_event> events;
    std::string line;

    if (!inputFile) {
        std::cerr << "Error: Unable to open file!" << std::endl;
        return 1;
    }


    while (std::getline(inputFile, line)) {
        std::stringstream stream(line);
        auto* event = new input_event();
        std::string innerString;
        bool first = true;
        while (std::getline(stream, innerString,' '))
        {
            if (first)
            {
                first = false;
                event->type = std::stoi(innerString);
            }
            else
            {
                event->code = std::stoi(innerString);
            }
        }
        events.push_back(*event);
        delete event;
    }

    inputFile.close();

    // Print parsed events
    for (const auto& event : events) {
        eventController->notifyOfEvent(event);
    }

    //delete ic2Listener;
    return 0;
}
