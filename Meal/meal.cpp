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

std::string Meal::getMealCategory()
{
    return "Meal";
}

double Meal::calculatePrice() const
{
    return 0;
}

void Meal::print(std::ostream& os) const
{
    os << "Name: " << name << std::endl;
}

void Meal::read(std::istream& is)
{
    std::cout << "Name: ";
    is >> name;
}
