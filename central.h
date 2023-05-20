#pragma once
#include <list>
#include <vector>
#include "workers/worker.h"
#include "workers/cleaner.h"
#include "workers/waiter.h"
#include "workers/manager.h"
#include "workers/cook.h"

class Central
{
    private:
        float income;
        std::vector<std::unique_ptr<Worker>> workers;
    public:
        void addWorker(std::string name, std::string position, float rate, float schedule[7]);
        void removeWorker(std::string name);
        int getWorkerCount() const;
        bool isEmpty() const;
        void listWorkersDetails() const;
        float totalSalary() const;
        void tip(std::string workerName, float amount);
        float getIncome() const;
        friend
        std::ostream& operator<<(std::ostream& os, const Central& central);
};