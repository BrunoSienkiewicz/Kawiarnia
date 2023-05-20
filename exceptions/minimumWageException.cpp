#include "minimumWageException.h"

MinimumWageException::MinimumWageException(float wrongPrice):
    std::invalid_argument("Given hour rate (" + std::to_string(wrongPrice) + ") is below minimum wage (" +  std::to_string(8) + ")"){}