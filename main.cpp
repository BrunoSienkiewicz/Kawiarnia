#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include "Meal/meal.h"
#include "Meal/cake.h"
#include "Meal/coffee.h"
#include "Meal/tea.h"
#include "Task/task.h"
#include "Task/prepareMeal.h"
#include "menu.h"


int main()
{
    std::vector<std::unique_ptr<Meal>> meals;
    std::vector<std::unique_ptr<Task>> tasks;

    std::unique_ptr<Cake> choclateCake = std::make_unique<Cake>("Chocolate cake", CakeType::ChocolateCake);
    std::unique_ptr<Cake> cheeseCake = std::make_unique<Cake>("Cheese cake", CakeType::CheeseCake);
    std::unique_ptr<Coffee> espresso = std::make_unique<Coffee>("Espresso", CoffeeType::Espresso, Size::Small, 0, 0, 0);
    std::unique_ptr<Coffee> cappuccino = std::make_unique<Coffee>("Cappuccino", CoffeeType::Cappuccino, Size::Medium, 1, 0, 2);

    meals.push_back(std::move(choclateCake));
    meals.push_back(std::move(cheeseCake));
    meals.push_back(std::move(espresso));
    meals.push_back(std::move(cappuccino));

    std::unique_ptr<Menu> menu = std::make_unique<Menu>(meals);
    std::cout << *menu;

    std::unique_ptr<PrepareMeal<Cake>> prepareMealTask = std::make_unique<PrepareMeal<Cake>>("Prepare chocolate cake", 20, choclateCake);
    std::unique_ptr<PrepareMeal<Cake>> prepareMealTask2 = std::make_unique<PrepareMeal<Cake>>("Prepare cheese cake", 20, cheeseCake);
    std::unique_ptr<PrepareMeal<Coffee>> prepareMealTask3 = std::make_unique<PrepareMeal<Coffee>>("Prepare espresso", 20, espresso);
    std::unique_ptr<PrepareMeal<Coffee>> prepareMealTask4 = std::make_unique<PrepareMeal<Coffee>>("Prepare cappuccino", 20, cappuccino);

    std::cout << *prepareMealTask << std::endl;
    std::cout << *prepareMealTask2 << std::endl;
    std::cout << *prepareMealTask3 << std::endl;
    std::cout << *prepareMealTask4 << std::endl;

    return 0;
}