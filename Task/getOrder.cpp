#include "getOrder.h"


getOrder::getOrder(std::string name, uint time, std::unique_ptr<Menu> menu, std::string mealName)
{
    if (!isStringValueValid(name))
        throw std::invalid_argument("Name cannot be empty");
    if (!isStringValueValid(mealName))
        throw std::invalid_argument("Meal name cannot be empty");
    if (menu == nullptr)
        throw std::invalid_argument("Menu cannot be empty");
    if (time < 1)
        throw std::invalid_argument("Time cannot be less than 1");
    
    this->name = name;
    this->time = time;
    this->menu = menu;
    this->mealName = mealName;
    if (menu->getMeal(mealName) == nullptr)
        throw std::invalid_argument("Meal not found");

    this->meal = getMealFromOrder(menu->getMeal(mealName));
}

std::unique_ptr<Menu> getOrder::getMenu()
{
    return menu;
}

void getOrder::setMenu(std::unique_ptr<Menu> menu)
{
    if (menu == nullptr)
        throw std::invalid_argument("Menu cannot be empty");
    this->menu = menu;
}

std::string getOrder::getMealName()
{
    return mealName;
}

void getOrder::setMealName(std::string mealName)
{
    if (!isStringValueValid(mealName))
        throw std::invalid_argument("Meal name cannot be empty");
    this->mealName = mealName;
}

template <>
std::unique_ptr<Meal> getOrder::getMealFromOrder(std::unique_ptr<Coffee> coffee)
{
    std::string size;
    uint sugar;
    uint milk;
    uint cream;
    std::cout << "Size: ";
    std::cin >> size;
    std::cout << "Sugar: ";
    std::cin >> sugar;
    std::cout << "Milk: ";
    std::cin >> milk;
    std::cout << "Cream: ";
    std::cin >> cream;
    coffee->setSize(convertStringToSize(size));
    coffee->setSugar(sugar);
    coffee->setMilk(milk);
    coffee->setCream(cream);
    return coffee;
}

std::string getOrder::getTaskCategory()
{
    return "Get order";
}