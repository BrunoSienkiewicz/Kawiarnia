#include "negativeHoursException.h"

NegativeHoursException::NegativeHoursException(float wrongHours):
    std::invalid_argument("Given hours is negative: " + std::to_string(wrongHours)){}