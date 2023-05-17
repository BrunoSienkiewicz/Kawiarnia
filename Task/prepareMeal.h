#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "task.h"
#include "../Meal/coffee.h"
#include "../Meal/cake.h"
#include "../Meal/tea.h"
#pragma once


template <class T>
class PrepareMeal : public Task
{
    private:
        std::unique_ptr<T> meal;
        void print(std::ostream &out) const override;
        void read(std::istream &in) override;
    
    public:
        PrepareMeal(std::string name, uint time, std::unique_ptr<T> meal);
        std::unique_ptr<T> getMeal();
        void setMeal(std::unique_ptr<T> meal);
        std::string getTaskCategory() override;

        template <class U>
        friend std::ostream& operator<<(std::ostream &out, const PrepareMeal<U>& prepareMeal);

        template <class U>
        friend std::istream& operator>>(std::istream &in, PrepareMeal<U>& prepareMeal);

        ~PrepareMeal() override;
};