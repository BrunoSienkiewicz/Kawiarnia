#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "client.h"
#include "../Meal/meal.h"
#pragma once


class Order
{
    private:
        std::string name;
        std::unique_ptr<Client> client;
        std::vector<std::unique_ptr<Meal>> meals;

    public:
        Order(std::string name, std::unique_ptr<Client> client);
        std::string getName();
        std::unique_ptr<Client> getCustomer();
        std::vector<std::unique_ptr<Meal>> getMeals();
        void addMeal(std::unique_ptr<Meal> meal);
        void removeMeal(uint mealId);
        void removeMeal(std::unique_ptr<Meal> meal);
        void removeMeal(std::string mealName);

        float getAmount();

        friend std::ostream& operator<<(std::ostream &out, const Order& order);
        friend std::istream& operator>>(std::istream &in, Order& order);
        ~Order();
};