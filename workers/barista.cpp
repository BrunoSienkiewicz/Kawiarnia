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
    setPossibleMeals(std::move(possibleMeals));
    this->possibleTasks.push_back("Prepare meal");
}

Barista::Barista(std::string name, float rate, std::vector<uint> possibleMeals) : Worker(name, "Barista", rate)
{
    setPossibleMeals(std::move(possibleMeals));
    float schedule[7] = {0, 0, 0, 0, 0, 0, 0};
    Worker::setSchedule(schedule);
    this->possibleTasks.push_back("Prepare meal");
}

bool Barista::isMealinPossibleMeals(uint mealId)
{
    return std::find(possibleMeals.begin(), possibleMeals.end(), mealId) != possibleMeals.end();
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

void Barista::doTask()
{
    if (tasks.empty())
        throw std::invalid_argument("No tasks to do");
    std::unique_ptr<Task> task = std::move(tasks[0]);
    std::cout << "Barista " << name << " is doing " << task->getName() << std::endl;

    tasks.erase(tasks.begin());
}

Barista::~Barista()
{
    for (auto &task : tasks)
    {
        task->~Task();
    }

    tasks.clear();
}

bool Barista::isMealinPossibleMeals(std::unique_ptr<Meal> meal)
{
    return true;
}
