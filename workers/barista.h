#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "../Meal/meal.h"
#include "worker.h"
#pragma once

class Barista : public Worker
{
    private:
        // indeksy z menu posiłków, które może przygotować barista
        std::vector<uint> possibleMeals;
        bool isMealinPossibleMeals(uint mealId);
        bool isMealinPossibleMeals(std::unique_ptr<Meal> meal);
        bool isMealinPossibleMeals(std::string mealName);
        void taskActions(std::unique_ptr<Task> task) override;
    
    public:
        Barista(std::string name, float rate, float schedule[7], std::vector<uint> possibleMeals);
        Barista(std::string name, float rate, std::vector<uint> possibleMeals);
        std::vector<uint> getPossibleMeals();
        void setPossibleMeals(std::vector<uint> possibleMeals);
        float getSalary() const override;
        float tip(float amount) override;
};
