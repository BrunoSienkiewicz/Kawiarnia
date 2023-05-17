#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "Meal/meal.h"

class Menu
{
    private:
        std::vector<std::unique_ptr<Meal>> meals;
    
    public:
        Menu(std::vector<std::unique_ptr<Meal>> meals);
        std::vector<std::unique_ptr<Meal>> getMeals();
        void setMeals(std::vector<std::unique_ptr<Meal>> meals);
        std::unique_ptr<Meal> getMeal(std::string name);
        std::unique_ptr<Meal> getMeal(uint index);
        void addMeal(std::unique_ptr<Meal> meal);
        void removeMeal(std::string name);

        ~Menu();

        friend
        std::ostream& operator<<(std::ostream& os, const Menu& menu);
};