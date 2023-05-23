#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "task.h"
#include "../Meal/coffee.h"
#include "../Meal/cake.h"
#include "../Meal/tea.h"
#include "../Client/order.h"
#pragma once


template <class T>
class PrepareMeal : public Task
{
    private:
        std::unique_ptr<T> meal;
        Order& order;
        void print(std::ostream &out) const override;
        void read(std::istream &in) override;
    
    public:
        PrepareMeal(std::string name, uint time, T meal, Order& order);
        PrepareMeal(std::string name, uint time, Meal meal, Order& order);
        T& getMeal();
        Order getOrder();
        void setMeal(T meal);
        void setOrder(Order& order);

        template <class U>
        friend std::ostream& operator<<(std::ostream &out, const PrepareMeal<U>& prepareMeal);

        template <class U>
        friend std::istream& operator>>(std::istream &in, PrepareMeal<U>& prepareMeal);

        ~PrepareMeal() override;
};