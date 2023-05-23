#include <iostream>
#pragma once


class Meal
{
    protected:
        std::string name;
        bool isStringValid(std::string string);

        virtual void print(std::ostream& os) const;
        virtual void read(std::istream& is);
    
    public:
        std::string getName();
        void setName(std::string name);
        virtual std::string getMealCategory();
        virtual double calculatePrice() const;

        friend
        std::ostream& operator<<(std::ostream& os, const Meal& meal);

        friend
        std::istream& operator>>(std::istream& is, Meal& meal);

        virtual ~Meal();
};