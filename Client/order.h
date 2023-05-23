#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>
#include "client.h"
#include "../Meal/meal.h"
#pragma once


class Order
{
    private:
        std::string name;
        std::unique_ptr<Client> client;
        std::vector<std::unique_ptr<Meal>> meals;
        std::vector<std::unique_ptr<Meal>> mealsPrepared;

    public:
        Order(std::string name, Client client);
        std::string getName();
        Client getCustomer();
        std::vector<Meal> getMeals();
        void addMeal(Meal mealPrepared);
        void removeMeal(uint mealId);
        void removeMeal(Meal meal);
        void removeMeal(std::string mealName);

        float getAmount();

        friend std::ostream& operator<<(std::ostream &out, const Order& order);
        friend std::istream& operator>>(std::istream &in, Order& order);
        ~Order();
};