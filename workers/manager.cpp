#include "manager.h"
#include "../Task/assignTask.h"

Manager::Manager(std::string name, float rate, std::vector<std::unique_ptr<Worker>> subjectWorkers) : Worker(name, "Manager", rate)
{
    float schedule[7] = {0, 0, 0, 0, 0, 0, 0};
    Worker::setSchedule(schedule);
    setSubjectWorkers(std::move(subjectWorkers));
    this->possibleTasks.push_back("Assign task");
}

Manager::Manager(std::string name, float rate, float schedule[7], std::vector<std::unique_ptr<Worker>> subjectWorkers) : Worker(name, "Manager", rate, schedule)
{
    setSubjectWorkers(std::move(subjectWorkers));
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

std::vector<std::unique_ptr<Worker>> Manager::getSubjectWorkers() const
{
    return subjectWorkers;
}

void Manager::setSubjectWorkers(std::vector<std::unique_ptr<Worker>> subjectWorkers)
{
    if (subjectWorkers.empty())
        throw std::invalid_argument("Subject workers cannot be empty");
    this->subjectWorkers = subjectWorkers;
}

void Manager::taskActions(std::unique_ptr<Task> task)
{
    if (task->getName() == "Assign task")
    {
        auto assignTask = dynamic_cast<AssignTask*>(task.get());
        for (auto &worker : subjectWorkers)
        {
            if (!worker->getIsOccupied())
            {
                auto it = std::find_if(possibleTasks.begin(), possibleTasks.end(), [assignTask](std::string taskCategory) { return taskCategory == assignTask->getTask()->getTaskCategory(); });
                if (it == possibleTasks.end())
                    continue;
                
                std::unique_ptr<Task> task = std::move(assignTask->getTask());
                worker->addTask(std::move(task));
                break;
            }
        }

        // Co zrobić jeśli żaden pracownik nie może wykonać zadania?
        if (assignTask->getTask() != nullptr)
        {
            auto newAssignTask = std::make_unique<AssignTask>(assignTask->getName(), assignTask->getTime(), std::move(assignTask->getTask()));
            addTask(std::move(newAssignTask));
        }
    }
    else
        throw std::invalid_argument("Task not found");
}