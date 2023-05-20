#include "exceedingHoursException.h"

ExceedingHoursException::ExceedingHoursException(float wrongHours):
    std::invalid_argument("Given hours is too much: " + std::to_string(wrongHours)){}