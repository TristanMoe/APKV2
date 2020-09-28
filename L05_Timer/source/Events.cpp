//
// Created by stud on 9/28/20.
//

#include <ostream>
#include <ctime>

#include "../headers/Events.hpp"

std::ostream& operator<<( std::ostream& os, const Event& ev )
{
    std::time_t creationTime = std::chrono::system_clock::to_time_t(ev.creationTime());
    os << std::ctime(&creationTime);

    return os;
}
