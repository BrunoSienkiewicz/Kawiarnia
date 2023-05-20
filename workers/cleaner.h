#pragma once

#include "worker.h"

class Cleaner : public Worker
{
    public:
        Cleaner(std::string name, float rate);
        Cleaner(std::string name, float rate, float schedule[7]);
        float getSalary() const override;
};