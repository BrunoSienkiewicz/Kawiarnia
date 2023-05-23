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
#include "Task/assignTask.h"
#include "workers/worker.h"
#include "workers/manager.h"
#include "workers/barista.h"
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

    std::unique_ptr<Meal> prepareCake = retrieveMeal(*menu, 1);
    std::unique_ptr<Meal> prepareCoffee = retrieveMeal(*menu, 2);

    std::unique_ptr<PrepareMeal<Cake>> prepareMealTask1 = std::make_unique<PrepareMeal<Cake>>("Prepare cheese cake", 20, prepareCake);
    std::unique_ptr<PrepareMeal<Coffee> prepareMealTask2 = std::make_unique<PrepareMeal<Coffee>>("Prepare coffee", 20, prepareCoffee);

    std::cout << *prepareMealTask1 << std::endl;
    std::cout << *prepareMealTask2 << std::endl;

    return 0;
}