#include <cstring>
#include "central.h"

void Central::addWorker(std::string name, std::string position, float rate, float schedule[7])
{
    std::unique_ptr<Worker> worker;
    std::string positionLower;
    for (auto& c : position)
        positionLower += tolower(c);
    
    if (positionLower == "cleaner")
    {
        worker = std::make_unique<Cleaner>(name, rate, schedule);
    }
    else if (positionLower == "cook")
    {
        worker = std::make_unique<Cook>(name, rate, schedule);
    }
    else if (positionLower == "manager")
    {
        worker = std::make_unique<Manager>(name, rate, schedule);
    }
    else if (positionLower == "waiter")
    {
        worker = std::make_unique<Waiter>(name, rate, schedule);
    }
    else
    {
        worker = std::make_unique<Worker>(name, position, rate, schedule);
    }
    workers.push_back(std::move(worker));
}

void Central::removeWorker(std::string name)
{
    for (auto it = workers.begin(); it != workers.end(); ++it)
    {
        if ((*it)->getName() == name)
        {
            workers.erase(it);
            return;
        }
    }
    throw std::invalid_argument("Worker not found");
}

int Central::getWorkerCount() const
{
    return workers.size();
}

bool Central::isEmpty() const
{
    return workers.empty();
}

std::ostream& operator<<(std::ostream& os, const Central& central)
{
    for (const auto& worker_ptr : central.workers)
    {
        os << worker_ptr->getName() + " - " + worker_ptr->getPosition() + "\n";
    }
    return os;
}

void Central::listWorkersDetails() const
{
    for (const auto& worker_ptr : workers)
    {
        std::cout << *worker_ptr << "\n";
    }
}

float Central::totalSalary() const
{
    float total = 0;
    for (const auto& worker_ptr : workers)
        total += worker_ptr->getSalary();
    return total;
}

void Central::tip(std::string workerName, float amount)
{
    for(const auto& worker_ptr : workers)
    {
        if(worker_ptr->getName() == workerName && worker_ptr->getPosition() == "Waiter")
        {
            income += worker_ptr->tip(amount);
            return;
        }
    }
    throw std::invalid_argument("Waiter not found");
}

float Central::getIncome() const
{
    return income;
}