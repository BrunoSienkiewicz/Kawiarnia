#include "tea.h"


Tea::Tea(std::string name, Size size, uint sugar)
{
    if (!isStringValid(name))
    {
        throw std::invalid_argument("Invalid name");
    }

    this->name = name;
    this->size = size;
    this->sugar = sugar;
    calculatePrice();
}

Size Tea::getSize()
{
    return size;
}

uint Tea::getSugar()
{
    return sugar;
}

void Tea::setSize(Size size)
{
    this->size = size;
    calculatePrice();
}

void Tea::setSugar(uint sugar)
{
    this->sugar = sugar;
    calculatePrice();
}

double Tea::calculatePrice() const
{
    double price;
    switch (size)
    {
        case Size::Small:
            price = 3;
            break;
        case Size::Medium:
            price = 4;
            break;
        case Size::Large:
            price = 5;
            break;
        default:
            throw std::invalid_argument("Invalid size");
    }

    price += sugar * 2;
    return price;
}

void Tea::print(std::ostream& os) const
{
    os << "Name: " << name << std::endl;
    os << "Size: " << convertSizeToString(size) << std::endl;
    os << "Sugar: " << sugar << std::endl;
    os << "Price: " << this->calculatePrice() << std::endl;
}

void Tea::read(std::istream& is)
{
    std::string name;
    std::string size;
    uint sugar;

    std::cout << "Name: ";
    is >> name;
    std::cout << "Size: ";
    is >> size;
    std::cout << "Sugar: ";
    is >> sugar;

    this->name = name;
    this->size = convertStringToSize(size);
    this->sugar = sugar;
    calculatePrice();
}

std::ostream& operator<<(std::ostream& os, const Tea& tea)
{
    tea.print(os);
    return os;
}

std::istream& operator>>(std::istream& is, Tea& tea)
{
    tea.read(is);
    return is;
}

std::string Tea::getMealCategory()
{
    return "Tea";
}

Tea::~Tea()
{
}
