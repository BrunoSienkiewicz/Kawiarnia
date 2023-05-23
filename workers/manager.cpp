#include "manager.h"
#include "../Task/assignTask.h"

Manager::Manager(std::string name, float rate, std::vector<Worker> subjectWorkers) : Worker(name, "Manager", rate)
{
    float schedule[7] = {0, 0, 0, 0, 0, 0, 0};
    Worker::setSchedule(schedule);
    setSubjectWorkers(subjectWorkers);
    this->possibleTasks.push_back("Assign task");
}

Manager::Manager(std::string name, float rate, float schedule[7], std::vector<Worker> subjectWorkers) : Worker(name, "Manager", rate, schedule)
{
    setSubjectWorkers(subjectWorkers);
    this->possibleTasks.push_back("Assign task");
}

float Manager::getSalary() const
{
    float hours = Worker::getHoursInWeek();
    float basicSalary = hours * getRate();
    if (hours > 48)
        basicSalary *= 1.2;
    return basicSalary;
}

std::vector<Worker> Manager::getSubjectWorkers() const
{
    std::vector<Worker> workers;
    for (auto &worker : subjectWorkers)
        workers.push_back(*worker);
    return workers;
}

void Manager::setSubjectWorkers(std::vector<Worker> subjectWorkers)
{
    if (subjectWorkers.empty())
        throw std::invalid_argument("Subject workers cannot be empty");

    for (auto &worker : subjectWorkers)
        this->subjectWorkers.push_back(std::make_unique<Worker>(worker));
}

void Manager::taskActions(Task& task)
{
    if (task.getName() == "Assign task")
    {
    }
    else
        throw std::invalid_argument("Task not found");
}

void Manager::assignTask(Task task)
{
    for (auto &worker : subjectWorkers)
    {
        if (!worker->getIsOccupied())
        {
            auto it = std::find_if(possibleTasks.begin(), possibleTasks.end(), [&task](std::string taskCategory) { return taskCategory == task.getTaskCategory(); });
            if (it == possibleTasks.end())
                continue;
            
            worker->addTask(task);
            break;
        }
    }
}