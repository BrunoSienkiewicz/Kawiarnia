#include <iostream>
#include <string>
#include <algorithm>
#include "size.h"


std::string convertSizeToString(Size size)
{
    switch (size)
    {
        case Size::Small:
            return "small";
        case Size::Medium:
            return "medium";
        case Size::Large:
            return "large";
        default:
            return "unknown";
    }
}

Size convertStringToSize(std::string size)
{
    std::transform(size.begin(), size.end(), size.begin(), ::tolower);
    
    if (size == "small")
    {
        return Size::Small;
    }
    else if (size == "medium")
    {
        return Size::Medium;
    }
    else if (size == "large")
    {
        return Size::Large;
    }
    else
    {
        throw std::invalid_argument("Invalid size");
    }
}