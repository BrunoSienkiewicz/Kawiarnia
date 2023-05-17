#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "meal.h"
#pragma once

enum class CakeType
{
    ChocolateCake,
    CheeseCake,
    FruitCake,
    CarrotCake,
    IceCreamCake
};

class Cake : public Meal
{
    private:
        CakeType type;
        void print(std::ostream& os) const override;
        void read(std::istream& is) override;
        std::string getStringType(CakeType type) const;
        CakeType getCakeType(std::string type) const;
    
    public:
        Cake(std::string name, CakeType type);
        CakeType getType();
        std::vector<std::string> getValidTypes();
        void setType(CakeType type);
        std::string getMealCategory() override;
        double calculatePrice() const override;

        ~Cake();

        friend
        std::ostream& operator<<(std::ostream& os, const Cake& cake);

        friend
        std::istream& operator>>(std::istream& is, Cake& cake);
};