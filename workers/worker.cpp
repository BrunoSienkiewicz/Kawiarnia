//Szymon Makuch

#include "worker.h"

Worker::Worker(std::string nName, std::string nPosition, float nRate)
{
    setName(nName);
    setPosition(nPosition);
    setRate(nRate);
    float array[7] = {0,0,0,0,0,0,0};
    setSchedule(array);
}

Worker::Worker(std::string nName, std::string nPosition, float nRate, float nSchedule[7])
{
    setName(nName);
    setPosition(nPosition);
    setRate(nRate);
    setSchedule(nSchedule);
}

std::string Worker::getName() const
{
    return name;
}

std::string Worker::getPosition() const
{
    return position;
}

float Worker::getRate() const
{
    return rate;
}

float Worker::getHoursInWeek() const
{
    float hours = 0;
    for (ushort i = 0; i < 7; i++)
        hours += schedule[i];
    return hours;
}

float Worker::getSalary() const
{
    return getHoursInWeek() * getRate();
}

void Worker::setName(std::string nName)
{
    if (nName.length() == 0)
        throw std::invalid_argument("Name cannot be empty");
    name = nName;
}

void Worker::setPosition(std::string nPosition)
{
    if (nPosition.length() == 0)
        throw std::invalid_argument("Position cannot be empty");
    position = nPosition;
}

void Worker::setRate(float nRate)
{
    if (nRate < 8.0)
        throw MinimumWageException(nRate);
    rate = nRate;
}

void Worker::setSchedule(float nSchedule[7])
{
    for (ushort i = 0; i < 7; i++)
        if (nSchedule[i] < 0)
            throw NegativeHoursException(nSchedule[i]);
        else if (nSchedule[i] > 24)
            throw ExceedingHoursException(nSchedule[i]);
        else
            schedule[i] = nSchedule[i];
}

float Worker::tip(float amount)
{
    return amount;
}

std::ostream& operator<<(std::ostream& os, const Worker& worker)
{
    os << "Name: " << worker.getName() << "\nPosition: " << worker.getPosition() << "\nHour rate: " << worker.getRate() << "\nSalary: " << worker.getSalary() << "\nWork schedule:\n";
    os << "Mon Tue Wed Thu Fri Sat Sun\n";
    for (int i = 0; i < 7; i++)
        os << " " << worker.schedule[i] << "  ";
    os << "\n";
    return os;
}
