#pragma once
#include <stdexcept>

class NegativeHoursException : public std::invalid_argument
{
    public:
        NegativeHoursException(float wrongHours);
};