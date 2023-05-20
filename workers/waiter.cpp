#include "waiter.h"

Waiter::Waiter(std::string name, float rate) : Worker(name, "Waiter", rate)
{
    float schedule[7] = {0, 0, 0, 0, 0, 0, 0};
    Worker::setSchedule(schedule);
}

Waiter::Waiter(std::string name, float rate, float schedule[7]) : Worker(name, "Waiter", rate, schedule){}

float Waiter::getSalary() const
{
    float hours = Worker::getHoursInWeek();
    float basicSalary = hours * getRate();
    if (hours > 48)
        basicSalary *= 1.2;
    return basicSalary + tips;
}

float Waiter::tip(float amount)
{
    tips += amount;
    return 0;
}