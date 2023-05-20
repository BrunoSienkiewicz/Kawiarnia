#include "task.h"

Task::Task(std::string name, uint time, std::string taskCategory)
{
    setName(name);
    setTime(time);
    if (!isStringValueValid(taskCategory))
    {
        throw std::invalid_argument("Invalid task category");
    }
    this->taskCategory = taskCategory;
}

bool Task::isStringValueValid(std::string value)
{
    return value.length() > 0;
}

std::string Task::getName()
{
    return this->name;
}

uint Task::getTime()
{
    return this->time;
}

std::string Task::getTaskCategory()
{
    return this->taskCategory;
}

void Task::setName(std::string name)
{
    if(!isStringValueValid(name))
    {
        throw std::invalid_argument("Invalid name");
    }
    this->name = name;
}

void Task::setTime(uint time)
{
    if (time < 1)
    {
        throw std::invalid_argument("Time must be greater than 0");
    }
    this->time = time;
}

std::ostream& operator<<(std::ostream &out, const Task &task)
{
    task.print(out);
    return out;
}

std::istream& operator>>(std::istream &in, Task &task)
{
    task.read(in);
    return in;
}

Task::~Task()
{
}
