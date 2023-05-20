#pragma once
#include <stdexcept>

class ExceedingHoursException : public std::invalid_argument
{
    public:
        ExceedingHoursException(float wrongHours);
};