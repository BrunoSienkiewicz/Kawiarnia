//Szymon Makuch

#include "worker.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include "../Task/task.h"

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

bool Worker::getIsOccupied() const
{
    return isOccupied;
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

void Worker::setIsOccupied(bool nIsOccupied)
{
    isOccupied = nIsOccupied;
}

float Worker::tip(float amount)
{
    return amount;
}

void Worker::setTasks(std::vector<Task> tasks)
{
    this->tasks.clear();
    for (auto &task : tasks)
    {
        this->addTask(task);
    }
}

void Worker::addTask(Task task)
{
    std::unique_ptr<Task> ptr(new Task(task.getName(), task.getTime(), task.getTaskCategory()));
    tasks.push_back(std::move(ptr));
}

std::vector<Task> Worker::getTasks() const
{
    std::vector<Task> tasks;
    for (auto &task : this->tasks)
    {
        tasks.push_back(*task);
    }
    return tasks;
}

void Worker::removeTask(Task task)
{
    auto it = std::find(tasks.begin(), tasks.end(), task);
    if (it != tasks.end())
        tasks.erase(it);

    throw std::invalid_argument("Task not found");
}

void Worker::removeTask(int index)
{
    if (index < 0 || index >= tasks.size())
        throw std::invalid_argument("Index out of range");
    tasks.erase(tasks.begin() + index);
}

void Worker::removeTask(std::string name)
{
    for (auto it = tasks.begin(); it != tasks.end(); ++it)
    {
        if ((*it)->getName() == name)
        {
            tasks.erase(it);
            return;
        }
    }
    throw std::invalid_argument("Task not found");
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

void Worker::doTask()
{
    if (tasks.empty())
        throw std::invalid_argument("No tasks to do");
    Task& task = *tasks[0];

    auto it = std::find(possibleTasks.begin(), possibleTasks.end(), task.getTaskCategory());
    if (it == possibleTasks.end())
        throw std::invalid_argument("Worker cannot do this task");

    task.setTime(task.getTime() - 1);
    taskActions(task);

    if (task.getTime() == 0)
    {
        tasks.erase(tasks.begin());
    }
}

void Worker::taskActions(Task& task)
{
    std::cout << "Worker " << getName() << " is doing task " << task.getName() << std::endl;
}
