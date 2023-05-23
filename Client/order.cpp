#include "order.h"
#include "../Meal/coffee.h"
#include "../Meal/cake.h"
#include "../Meal/tea.h"


Order::Order(std::string name, Client client)
{
    if (name.empty())
        throw std::invalid_argument("Name cannot be empty");
    
    this->name = name;
    this->client = std::make_unique<Client>(client);
}

std::string Order::getName()
{
    return name;
}

Client Order::getCustomer()
{
    return *client;
}

std::vector<Meal> Order::getMeals()
{
    std::vector<Meal> meals;
    for (auto &meal : this->meals)
        meals.push_back(*meal);
    return meals;
}

void Order::addMeal(Meal mealPrepared)
{
    if(mealPrepared.getMealCategory() == "Coffee")
        meals.push_back(std::make_unique<Coffee>(dynamic_cast<Coffee&>(mealPrepared)));
    else if(mealPrepared.getMealCategory() == "Cake")
        meals.push_back(std::make_unique<Cake>(dynamic_cast<Cake&>(mealPrepared)));
    else if(mealPrepared.getMealCategory() == "Tea")
        meals.push_back(std::make_unique<Tea>(dynamic_cast<Tea&>(mealPrepared)));
    else
        throw std::invalid_argument("Meal category not found");
}

void Order::removeMeal(uint mealId)
{
    if (mealId < 0 || mealId >= meals.size())
        throw std::invalid_argument("Meal id out of range");
    meals.erase(meals.begin() + mealId);
}

void Order::removeMeal(Meal meal)
{
    auto it = std::find(meals.begin(), meals.end(), meal);
    if (it != meals.end())
        meals.erase(it);
    else
        throw std::invalid_argument("Meal not found");
}

void Order::removeMeal(std::string mealName)
{
    for (auto it = meals.begin(); it != meals.end(); ++it)
    {
        if ((*it)->getName() == mealName)
        {
            meals.erase(it);
            return;
        }
    }
    throw std::invalid_argument("Meal not found");
}

float Order::getAmount()
{
    float amount = 0;
    for (auto &meal : meals)
        amount += meal->calculatePrice();
    return amount;
}

