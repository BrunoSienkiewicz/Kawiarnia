#include <iostream>
#pragma once


class Meal
{
    protected:
        std::string name;
        bool isStringValid(std::string string);

        virtual void print(std::ostream& os) const = 0;
        virtual void read(std::istream& is) = 0;
    
    public:
        std::string getName();
        void setName(std::string name);
        virtual std::string getMealCategory() = 0;
        virtual double calculatePrice() const = 0;

        friend
        std::ostream& operator<<(std::ostream& os, const Meal& meal);

        friend
        std::istream& operator>>(std::istream& is, Meal& meal);

        virtual ~Meal() = 0;
};