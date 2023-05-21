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
        void taskActions(std::unique_ptr<Task> task) override;
    
    public:
        Manager(std::string name, float rate, std::vector<std::unique_ptr<Worker>> subjectWorkers);
        Manager(std::string name, float rate, float schedule[7], std::vector<std::unique_ptr<Worker>> subjectWorkers);
        std::vector<std::unique_ptr<Worker>> getSubjectWorkers() const;
        void setSubjectWorkers(std::vector<std::unique_ptr<Worker>> subjectWorkers);
        float getSalary() const override;
};