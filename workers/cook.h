#pragma once

#include "worker.h"

class Cook : public Worker
{
    public:
        Cook(std::string name, float rate);
        Cook(std::string name, float rate, float schedule[7]);
        float getSalary() const override;
};