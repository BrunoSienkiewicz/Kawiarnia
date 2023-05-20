#pragma once

#include "worker.h"

class Waiter : public Worker
{
    private:
        float tips;
    public:
        Waiter(std::string name, float rate);
        Waiter(std::string name, float rate, float schedule[7]);
        float getSalary() const override;
        float tip(float amount) override;
};