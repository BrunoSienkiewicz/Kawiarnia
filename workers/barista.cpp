#include "barista.h"
#include "../Task/prepareMeal.h"
#include "../Meal/meal.h"
#include "../Meal/coffee.h"
#include "../Meal/cake.h"
#include "../Meal/tea.h"
#include <memory>
#include <algorithm>

Barista::Barista(std::string name, float rate, float schedule[7], std::vector<uint> possibleMeals) : Worker(name, "Barista", rate, schedule)
{
    setPossibleMeals(possibleMeals);
    this->possibleTasks.push_back("Prepare meal");
    this->possibleTasks.push_back("Get Order");
}

Barista::Barista(std::string name, float rate, std::vector<uint> possibleMeals) : Worker(name, "Barista", rate)
{
    setPossibleMeals(possibleMeals);
    float schedule[7] = {0, 0, 0, 0, 0, 0, 0};
    Worker::setSchedule(schedule);
    this->possibleTasks.push_back("Prepare meal");
    this->possibleTasks.push_back("Get Order");
}

bool Barista::isMealinPossibleMeals(uint mealId)
{
    return std::find(possibleMeals.begin(), possibleMeals.end(), mealId) != possibleMeals.end();
}

bool Barista::isMealinPossibleMeals(std::string mealName)
{
    return true;
}

float Barista::getSalary() const
{
    float hours = Worker::getHoursInWeek();
    float basicSalary = hours * getRate();
    if (hours > 48)
        basicSalary *= 1.2;
    return basicSalary;
}

float Barista::tip(float amount)
{
    return 0;
}

std::vector<uint> Barista::getPossibleMeals()
{
    return possibleMeals;
}

void Barista::setPossibleMeals(std::vector<uint> possibleMeals)
{
    if (possibleMeals.empty())
        throw std::invalid_argument("Possible meals cannot be empty");
    this->possibleMeals = possibleMeals;
}

void Barista::taskActions(Task& task)
{
    if (task.getTaskCategory() == "Prepare Meal")
    {
        PrepareMeal<Meal>& prepareMeal = dynamic_cast<PrepareMeal<Meal>&>(task);
        Meal& meal = prepareMeal.getMeal();

        if (!isMealinPossibleMeals(meal.getName()))
            throw std::invalid_argument("Barista cannot prepare this meal");

        if (meal.getMealCategory() == "Coffee")
        {
            Coffee& coffee = dynamic_cast<Coffee&>(meal);
            std::cout << "Preparing coffee: " << coffee.getName() << std::endl;
        }
        else if (meal.getMealCategory() == "Cake")
        {
            Cake& cake = dynamic_cast<Cake&>(meal);
            std::cout << "Preparing cake: " << cake.getName() << std::endl;
        }
        else if (meal.getMealCategory() == "Tea")
        {
            Tea& tea = dynamic_cast<Tea&>(meal);
            std::cout << "Preparing tea: " << tea.getName() << std::endl;
        }
        else
            throw std::invalid_argument("Meal not found");
    }
}

Barista::~Barista()
{
    for (auto &task : tasks)
    {
        task->~Task();
    }

    tasks.clear();
}
