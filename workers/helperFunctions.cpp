#include "helperFunctions.h"


std::unique_ptr<Meal> inline retrieveMeal(Menu menu, uint mealId)
{
    if (mealId > menu.getMeals().size())
        throw std::invalid_argument("Meal with given id does not exist");

    std::unique_ptr<Meal> meal = std::make_unique<Meal>(*menu.getMeals()[mealId - 1]);

    return meal;
}
