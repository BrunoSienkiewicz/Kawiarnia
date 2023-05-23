#include "cook.h"

Cook::Cook(std::string name, float rate) : Worker(name, "Cook", rate)
{
    float schedule[7] = {0, 0, 0, 0, 0, 0, 0};
    Worker::setSchedule(schedule);
    this->possibleTasks.push_back("Prepare Meal");
}

Cook::Cook(std::string name, float rate, float schedule[7]) : Worker(name, "Cook", rate, schedule)
{
    this->possibleTasks.push_back("Prepare Meal");
}

float Cook::getSalary() const
{
    float salary = Worker::getSalary();
    if (salary > 1000)
        return salary * 1.1;
    return salary;
}
