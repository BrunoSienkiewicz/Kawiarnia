#pragma once
#include <stdexcept>

class MinimumWageException : public std::invalid_argument
{
    public:
        MinimumWageException(float wrongPrice);
};