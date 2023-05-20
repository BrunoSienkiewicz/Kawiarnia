#pragma once
#include <iostream>
#include <string>
#include "../exceptions/minimumWageException.h"
#include "../exceptions/negativeHoursException.h"
#include "../exceptions/exceedingHoursException.h"

class Worker
{
    protected:
        std::string name;
        std::string position;
        float rate;
        float schedule[7];
        float sal;
    public:
        Worker(std::string name, std::string position, float rate);
        Worker(std::string name, std::string position, float rate, float schedule[7]);
        virtual std::string getName() const;
        virtual std::string getPosition() const;
        virtual float getRate() const;
        virtual float getHoursInWeek() const;
        virtual float getSalary() const;
        virtual float tip(float amount);
        void setName(std::string name);
        void setPosition(std::string position);
        void setRate(float rate);
        void setSchedule(float schedule[7]);
        friend
        std::ostream& operator<<(std::ostream& os, const Worker& worker);
};
