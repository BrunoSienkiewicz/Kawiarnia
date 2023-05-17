#include "coffee.h"
#include <algorithm>

double Coffee::calculatePrice() const
{
    double price;
    switch(this->type)
    {
        case CoffeeType::Espresso:
            price = 5;
            break;
        case CoffeeType::Cappuccino:
            price = 6;
            break;
        case CoffeeType::Latte:
            price = 7;
            break;
        case CoffeeType::Americano:
            price = 8;
            break;
        case CoffeeType::Mocha:
            price = 9;
            break;
        default:
            throw std::invalid_argument("Invalid coffee type");
    }

    switch(this->size)
    {
        case Size::Small:
            price += 0;
            break;
        case Size::Medium:
            price += 5;
            break;
        case Size::Large:
            price += 10;
            break;
        default:
            throw std::invalid_argument("Invalid coffee size");
    }
    
    uint additions[] = {sugar, milk, cream};

    for (uint addition : additions)
    {
        if (addition > 0)
        {
            price += 2*addition;
        }
    }
    return price;
}

Coffee::Coffee(std::string name, CoffeeType type, Size size, uint sugar=0, uint milk=0, uint cream=0)
{
    if(!isStringValid(name))
    {
        throw std::invalid_argument("Invalid name");
    }

    this->type = type;
    this->size = size;
    this->sugar = sugar;
    this->milk = milk;
    this->cream = cream;
    this->name = name;
}

CoffeeType Coffee::getType()
{
    return type;
}

Size Coffee::getSize()
{
    return size;
}

uint Coffee::getSugar()
{
    return sugar;
}

uint Coffee::getMilk()
{
    return milk;
}

uint Coffee::getCream()
{
    return cream;
}

void Coffee::setType(CoffeeType type)
{
    this->type = type;
}

void Coffee::setSize(Size size)
{
    this->size = size;
}

void Coffee::setSugar(uint sugar)
{
    this->sugar = sugar;
}

void Coffee::setMilk(uint milk)
{
    this->milk = milk;
}

void Coffee::setCream(uint cream)
{
    this->cream = cream;
}

CoffeeType Coffee::getCoffeeType(std::string type) const
{
    std::transform(type.begin(), type.end(), type.begin(), ::tolower);

    if (type == "espresso")
    {
        return CoffeeType::Espresso;
    }
    else if (type == "cappuccino")
    {
        return CoffeeType::Cappuccino;
    }
    else if (type == "latte")
    {
        return CoffeeType::Latte;
    }
    else if (type == "americano")
    {
        return CoffeeType::Americano;
    }
    else if (type == "mocha")
    {
        return CoffeeType::Mocha;
    }
    else
    {
        throw std::invalid_argument("Invalid coffee type");
    }
}

std::string Coffee::getStringType(CoffeeType type) const
{
    switch(type)
    {
        case CoffeeType::Espresso:
            return "Espresso";
        case CoffeeType::Cappuccino:
            return "Cappuccino";
        case CoffeeType::Latte:
            return "Latte";
        case CoffeeType::Americano:
            return "Americano";
        case CoffeeType::Mocha:
            return "Mocha";
        default:
            throw std::invalid_argument("Invalid coffee type");
    }
}

void Coffee::print(std::ostream &os) const
{
    os << "Name: " << name << std::endl;
    os << "Type: " << getStringType(type) << std::endl;
    os << "Size: " << convertSizeToString(size) << std::endl;
    os << "Sugar: " << sugar << std::endl;
    os << "Milk: " << milk << std::endl;
    os << "Cream: " << cream << std::endl;
    os << "Price: " << this->calculatePrice() << std::endl;
}

void Coffee::read(std::istream &is)
{
    std::string name;
    std::string type;
    std::string size;
    uint sugar;
    uint milk;
    uint cream;

    std::cout << "Name: ";
    is >> name;
    std::cout << "Type: ";
    is >> type;
    std::cout << "Size: ";
    is >> size;
    std::cout << "Sugar: ";
    is >> sugar;
    std::cout << "Milk: ";
    is >> milk;
    std::cout << "Cream: ";
    is >> cream;

    *this = Coffee(name, getCoffeeType(type), convertStringToSize(size), sugar, milk, cream);
}

std::ostream& operator<<(std::ostream& os, const Coffee& coffee)
{
    coffee.print(os);
    return os;
}

std::istream& operator>>(std::istream& is, Coffee& coffee)
{
    coffee.read(is);
    return is;
}

std::string Coffee::getMealCategory()
{
    return "Coffee";
}

Coffee::~Coffee()
{
}
