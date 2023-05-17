#include "meal.h"

bool Meal::isStringValid(std::string str)
{
    if (str.length() == 0)
    {
        return false;
    }
    
    return true;
}

std::string Meal::getName()
{
    return name;
}

void Meal::setName(std::string name)
{
    if (isStringValid(name))
    {
        this->name = name;
    }
}

std::ostream& operator<<(std::ostream& os, const Meal& meal)
{
    meal.print(os);
    return os;
}

std::istream& operator>>(std::istream& is, Meal& meal)
{
    meal.read(is);
    return is;
}

Meal::~Meal()
{
    
}
