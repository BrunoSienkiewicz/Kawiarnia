#include "manager.h"

Manager::Manager(std::string name, float rate) : Worker(name, "Manager", rate)
{
    float schedule[7] = {0, 0, 0, 0, 0, 0, 0};
    Worker::setSchedule(schedule);
}

Manager::Manager(std::string name, float rate, float schedule[7]) : Worker(name, "Manager", rate, schedule){}

float Manager::getSalary() const
{
    float hours = Worker::getHoursInWeek();
    float basicSalary = hours * getRate();
    if (hours > 48)
        basicSalary *= 1.2;
    return basicSalary;
}