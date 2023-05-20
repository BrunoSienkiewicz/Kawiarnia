#include "cleaner.h"

Cleaner::Cleaner(std::string name, float rate) : Worker(name, "Cleaner", rate)
{
    float schedule[7] = {0, 0, 0, 0, 0, 0, 0};
    Worker::setSchedule(schedule);
}

Cleaner::Cleaner(std::string name, float rate, float schedule[7]) : Worker(name, "Cleaner", rate, schedule){}

float Cleaner::getSalary() const
{
    float hours = Worker::getHoursInWeek();
    if (hours > 56)
        return hours * getRate() * 1.2;
    return hours * getRate();
}