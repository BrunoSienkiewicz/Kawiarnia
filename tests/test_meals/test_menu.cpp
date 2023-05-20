#include "../catch_amalgamated.hpp"
#include "../../Meal/meal.h"
#include "../../Meal/cake.h"
#include "../../Meal/coffee.h"
#include "../../menu.h"
#include <vector>
#include <string>
#include <memory>


TEST_CASE("Menu constructor", "[menu]")
{
    SECTION("Valid constructor")
    {
        std::vector<std::shared_ptr<Meal>> meals;
        meals.push_back(std::make_shared<Cake>("Choclate cake 1", CakeType::ChocolateCake));
        meals.push_back(std::make_shared<Coffee>("Espresso 1", CoffeeType::Espresso, Size::Small, 0, 0, 0));
        Menu menu(meals);
        CHECK(menu.getMeals().size() == 2);
    }

    SECTION("Invalid constructor")
    {
        std::vector<std::shared_ptr<Meal>> meals;
        CHECK_THROWS_AS(Menu(meals), std::invalid_argument);
    }
}

TEST_CASE("Menu meal operations", "[menu]")
{
    std::vector<std::shared_ptr<Meal>> meals;
    std::shared_ptr<Cake> cake = std::make_shared<Cake>("Choclate cake 1", CakeType::ChocolateCake);
    std::shared_ptr<Coffee> coffee = std::make_shared<Coffee>("Espresso 1", CoffeeType::Espresso, Size::Small, 0, 0, 0);
    meals.push_back(cake);
    meals.push_back(coffee);
    std::shared_ptr<Menu> menu = std::make_shared<Menu>(meals);

    SECTION("Get meal by name")
    {
        std::string name = "Choclate cake 1";
        std::string name2 = "Espresso 1";
        CHECK(menu->getMeal(name)->getName() == "Choclate cake 1");
        CHECK(menu->getMeal(name2)->getName() == "Espresso 1");
        CHECK_THROWS_AS(menu->getMeal("Invalid name"), std::invalid_argument);
    }

    SECTION("Get meal by index")
    {
        CHECK(menu->getMeal(0)->getName() == "Choclate cake 1");
        CHECK(menu->getMeal(1)->getName() == "Espresso 1");
        CHECK_THROWS_AS(menu->getMeal(2), std::invalid_argument);
    }

    SECTION("Add meal")
    {
        CHECK(menu->getMeals().size() == 2);
        menu->addMeal(std::make_shared<Cake>("Choclate cake 2", CakeType::ChocolateCake));
        CHECK(menu->getMeals().size() == 3);
        CHECK(menu->getMeal("Choclate cake 2")->getName() == "Choclate cake 2");
        CHECK_THROWS_AS(menu->addMeal(nullptr), std::invalid_argument);
    }

    SECTION("Remove meal")
    {
        CHECK(menu->getMeals().size() == 2);
        menu->removeMeal("Choclate cake 1");
        CHECK(menu->getMeals().size() == 1);
        CHECK_THROWS_AS(menu->removeMeal("Invalid name"), std::invalid_argument);
    }

    SECTION("<< Operator")
    {
        std::stringstream stream;
        stream << *menu;
        CHECK(stream.str() == "Meal 1:\nChoclate cake 1\tPrice:5\nMeal 2:\nEspresso 1\tPrice:5\n");
    }
}