#include "../catch_amalgamated.hpp"
#include "../../Meal/meal.h"
#include "../../Meal/cake.h"
#include "../../Meal/coffee.h"
#include <vector>
#include <string>
#include <memory>


TEST_CASE("Meal constructor", "[meal]")
{
    SECTION("Valid constructor")
    {
        Cake cake = Cake("Choclate cake 1", CakeType::ChocolateCake);
        CHECK(cake.getName() == "Choclate cake 1");
        CHECK(cake.getType() == CakeType::ChocolateCake);
        CHECK(cake.calculatePrice() == 5);
        CHECK(cake.getMealCategory() == "Cake");

        Coffee coffee = Coffee("Espresso 1", CoffeeType::Espresso, Size::Small, 0, 0, 0);
        CHECK(coffee.getName() == "Espresso 1");
        CHECK(coffee.getType() == CoffeeType::Espresso);
        CHECK(coffee.getSize() == Size::Small);
        CHECK(coffee.calculatePrice() == 5);
        CHECK(coffee.getMealCategory() == "Coffee");
    }

    SECTION("Invalid constructor")
    {
        CHECK_THROWS_AS(Cake("", CakeType::ChocolateCake), std::invalid_argument);
        CHECK_THROWS_AS(Coffee("", CoffeeType::Espresso, Size::Small, 0, 0, 0), std::invalid_argument);
    }

    SECTION("Calculate Price")
    {
        Cake cake = Cake("cake 1", CakeType::ChocolateCake);
        CHECK(cake.calculatePrice() == 5);
        cake.setType(CakeType::CheeseCake);
        CHECK(cake.calculatePrice() == 6);
        cake.setType(CakeType::FruitCake);
        CHECK(cake.calculatePrice() == 7);
        cake.setType(CakeType::CarrotCake);
        CHECK(cake.calculatePrice() == 8);
        cake.setType(CakeType::IceCreamCake);
        CHECK(cake.calculatePrice() == 9);

        Coffee coffee = Coffee("coffee 1", CoffeeType::Espresso, Size::Small, 0, 0, 0);
        CHECK(coffee.calculatePrice() == 5);
        coffee.setSize(Size::Medium);
        CHECK(coffee.calculatePrice() == 10);
        coffee.setSize(Size::Large);
        CHECK(coffee.calculatePrice() == 15);

        coffee.setCream(1);
        CHECK(coffee.calculatePrice() == 17);
        coffee.setSugar(2);
        CHECK(coffee.calculatePrice() == 21);
    }
}

TEST_CASE("Meal operators", "[meal]")
{
    Cake cake = Cake("Choclate cake 1", CakeType::ChocolateCake);
    Coffee coffee = Coffee("Espresso 1", CoffeeType::Espresso, Size::Small, 1, 0, 2);

    SECTION("<< operator")
    {
        std::stringstream ss;
        ss << cake;
        CHECK(ss.str() == "Cake: Choclate cake 1\nType: Chocolate\nPrice: 5\n");
        ss.str("");
        ss << coffee;
        CHECK(ss.str() == "Name: Espresso 1\nType: Espresso\nSize: small\nSugar: 1\nMilk: 0\nCream: 2\nPrice: 11\n");
    }

    SECTION(">> operator")
    {
        std::stringstream ss;
        ss << "Choclate_cake_1 Chocolate cake";
        ss >> cake;
        CHECK(cake.getName() == "Choclate_cake_1");
        CHECK(cake.getType() == CakeType::ChocolateCake);
        CHECK(cake.calculatePrice() == 5);

        ss.str("");
        ss << "Espresso_1 Espresso small 1 0 2";
        ss >> coffee;
        CHECK(coffee.getName() == "Espresso_1");
        CHECK(coffee.getType() == CoffeeType::Espresso);
        CHECK(coffee.getSize() == Size::Small);
        CHECK(coffee.calculatePrice() == 11);
    }
}
