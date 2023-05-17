#include "cake.h"
#include <algorithm>

Cake::Cake(std::string name, CakeType type)
{
    if(!isStringValid(name))
    {
        throw std::invalid_argument("Invalid name");
    }

    this->type = type;
    this->name = name;
}

CakeType Cake::getCakeType(std::string type) const
{
    std::transform(type.begin(), type.end(), type.begin(), ::tolower);
    if (type == "chocolate")
    {
        return CakeType::ChocolateCake;
    }
    else if (type == "cheese")
    {
        return CakeType::CheeseCake;
    }
    else if (type == "fruit")
    {
        return CakeType::FruitCake;
    }
    else if (type == "carrot")
    {
        return CakeType::CarrotCake;
    }
    else if (type == "icecream")
    {
        return CakeType::IceCreamCake;
    }
    else
    {
        throw std::invalid_argument("Invalid cake type");
    }
}

std::string Cake::getStringType(CakeType type) const
{
    switch (type)
    {
        case CakeType::ChocolateCake:
            return "Chocolate";
            break;
        case CakeType::CheeseCake:
            return "Cheese";
            break;
        case CakeType::FruitCake:
            return "Fruit";
            break;
        case CakeType::CarrotCake:
            return "Carrot";
            break;
        case CakeType::IceCreamCake:
            return "IceCream";
            break;
        default:
            throw std::invalid_argument("Invalid cake type");
            break;
    }
}

CakeType Cake::getType()
{
    return type;
}

void Cake::setType(CakeType type)
{
    this->type = type;
}

double Cake::calculatePrice() const
{
    double price;
    switch (type)
    {
        case CakeType::ChocolateCake:
            price = 5;
            break;
        case CakeType::CheeseCake:
            price = 6;
            break;
        case CakeType::FruitCake:
            price = 7;
            break;
        case CakeType::CarrotCake:
            price = 8;
            break;
        case CakeType::IceCreamCake:
            price = 9;
            break;
        default:
            throw std::invalid_argument("Invalid cake type");
            break;
    }
    return price;
}

void Cake::print(std::ostream& os) const
{
    os << "Cake: " << name << std::endl;
    os << "Type: " << getStringType(type) << std::endl;
    os << "Price: " << this->calculatePrice() << std::endl;
}

void Cake::read(std::istream& is)
{
    std::string type;
    std::string name;
    std::cout << "Enter cake name: ";
    is >> name;
    setName(name);
    std::cout << "Enter cake type: ";
    is >> type;
    setType(getCakeType(type));
}

std::ostream& operator<<(std::ostream& os, const Cake& cake)
{
    cake.print(os);
    return os;
}

std::istream& operator>>(std::istream& is, Cake& cake)
{
    cake.read(is);
    return is;
}

std::string Cake::getMealCategory()
{
    return "Cake";
}

Cake::~Cake()
{
}