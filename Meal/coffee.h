#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "meal.h"
#include "size.h"
#pragma once

enum class CoffeeType
{
    Espresso,
    Cappuccino,
    Latte,
    Americano,
    Mocha
};

class Coffee : public Meal
{
    private:
        CoffeeType type;
        Size size;
        uint sugar;
        uint milk;
        uint cream;
        CoffeeType getCoffeeType(std::string type) const;
        std::string getStringType(CoffeeType type) const;
        void print(std::ostream& os) const override;
        void read(std::istream& is) override;
    
    public:
        Coffee(std::string name, CoffeeType type, Size size, uint sugar, uint milk, uint cream);
        CoffeeType getType();
        Size getSize();
        uint getSugar();
        uint getMilk();
        uint getCream();
        void setType(CoffeeType type);
        void setSize(Size size);
        void setSugar(uint sugar);
        void setMilk(uint milk);
        void setCream(uint cream);
        std::string getMealCategory() override;
        double calculatePrice() const override;

        ~Coffee();

        friend
        std::ostream& operator<<(std::ostream& os, const Coffee& coffee);

        friend
        std::istream& operator>>(std::istream& is, Coffee& coffee);
};
