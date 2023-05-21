#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "../Meal/meal.h"
#include "../Meal/coffee.h"
#include "../Meal/cake.h"
#include "../Meal/tea.h"
#include "../menu.h"


std::unique_ptr<Meal> inline retrieveMeal(std::unique_ptr<Menu> menu, uint mealId);

