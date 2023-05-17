#include "menu.h"
#include <algorithm>

Menu::Menu(std::vector<std::unique_ptr<Meal>> meals)
{
    if (meals.size() < 1)
        throw std::invalid_argument("Meals are not valid");
    this->meals = std::move(meals);
}

std::vector<std::unique_ptr<Meal>> Menu::getMeals()
{
    return std::move(meals);
}

void Menu::setMeals(std::vector<std::unique_ptr<Meal>> meals)
{
    if (meals.size() < 1)
        throw std::invalid_argument("Meals are not valid");
    this->meals = std::move(meals);
}

std::unique_ptr<Meal> Menu::getMeal(std::string name)
{
    auto it = std::find_if(meals.begin(), meals.end(), [&name](std::unique_ptr<Meal> meal) { return meal->getName() == name; });
    if (it == meals.end())
        throw std::invalid_argument("Meal not found");
    return std::move(*it);
}

std::unique_ptr<Meal> Menu::getMeal(uint index)
{
    if (index < 0 || index >= meals.size())
        throw std::invalid_argument("Index is not valid");
    return std::move(meals[index]);
}

void Menu::addMeal(std::unique_ptr<Meal> meal)
{
    if (meal == nullptr)
        throw std::invalid_argument("Meal is not valid");
    meals.push_back(std::move(meal));
}

void Menu::removeMeal(std::string name)
{
    auto it = std::find_if(meals.begin(), meals.end(), [&name](std::unique_ptr<Meal> meal) { return meal->getName() == name; });
    if (it == meals.end())
        throw std::invalid_argument("Meal not found");
    meals.erase(it);
}

std::ostream& operator<<(std::ostream& os, const Menu& menu)
{
    int i = 0;
    for (auto& meal : menu.meals)
    {
        os << "Meal " << ++i << ":" << std::endl;
        os << meal->getName() << "\tPrice:"<< meal->calculatePrice() << std::endl;
    }
    return os;
}

Menu::~Menu() {}
