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
    std::vector<Meal> meals;
    std::vector<Task> tasks;

    Cake choclateCake = Cake("Chocolate cake", CakeType::ChocolateCake);
    Cake cheeseCake = Cake("Cheese cake", CakeType::CheeseCake);
    Coffee espresso = Coffee("Espresso", CoffeeType::Espresso, Size::Small, 0, 0, 0);
    Coffee cappuccino = Coffee("Cappuccino", CoffeeType::Cappuccino, Size::Medium, 1, 0, 2);

    meals.push_back(choclateCake);
    meals.push_back(cheeseCake);
    meals.push_back(espresso);
    meals.push_back(cappuccino);

    std::unique_ptr<Menu> menu = std::make_unique<Menu>(meals);
    std::cout << *menu;

    Meal prepareCake = retrieveMeal(*menu, 1);
    Meal prepareCoffee = retrieveMeal(*menu, 2);

    PrepareMeal<Cake> prepareMealTask1 = PrepareMeal<Cake>("Prepare cheese cake", 20, prepareCake);
    PrepareMeal<Coffee> prepareMealTask2 = PrepareMeal<Coffee>("Prepare coffee", 20, prepareCoffee);

    std::cout << prepareMealTask1 << std::endl;
    std::cout << prepareMealTask2 << std::endl;

    return 0;
}