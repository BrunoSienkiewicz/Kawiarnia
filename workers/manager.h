#pragma once

#include <memory>
#include "worker.h"

class Manager : public Worker
{
    public:
        Manager(std::string name, float rate);
        Manager(std::string name, float rate, float schedule[7]);
        float getSalary() const override;
};