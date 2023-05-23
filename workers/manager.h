#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <algorithm>
#include "worker.h"
#pragma once

class Manager : public Worker
{
    private:
        std::vector<std::unique_ptr<Worker>> subjectWorkers;
        void taskActions(Task& task) override;
    
    public:
        Manager(std::string name, float rate, std::vector<Worker> subjectWorkers);
        Manager(std::string name, float rate, float schedule[7], std::vector<Worker> subjectWorkers);
        std::vector<Worker> getSubjectWorkers() const;
        void setSubjectWorkers(std::vector<Worker> subjectWorkers);
        float getSalary() const override;
        void assignTask(Task task);
};