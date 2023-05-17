#include <iostream>
#include <string>
#pragma once


enum class Size {
    Small,
    Medium,
    Large
};

std::string convertSizeToString(Size size);

Size convertStringToSize(std::string size);