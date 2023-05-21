#include "assignTask.h"


AssignTask::AssignTask(std::string name, uint time, std::unique_ptr<Task> task) : Task(name, time, "Assign Task")
{
    setTask(std::move(task));
}

std::unique_ptr<Task> AssignTask::getTask()
{
    return std::move(task);
}

void AssignTask::setTask(std::unique_ptr<Task> task)
{
    if (task == nullptr)
    {
        throw std::invalid_argument("Task cannot be null");
    }
    this->task = std::move(task);
}

void AssignTask::print(std::ostream &out) const
{
    Task::print(out);
    out << "Task: " << *task << std::endl;
}

void AssignTask::read(std::istream &in)
{
    Task::read(in);
    in >> *task;
}

std::ostream& operator<<(std::ostream &out, const AssignTask &assignTask)
{
    assignTask.print(out);
    return out;
}

std::istream& operator>>(std::istream &in, AssignTask &assignTask)
{
    assignTask.read(in);
    return in;
}

