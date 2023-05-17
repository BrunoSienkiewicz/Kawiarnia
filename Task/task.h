#include <iostream>
#include <string>
#include <memory>
#include "../Meal/meal.h"
#pragma once

class Task
{
    protected:
        std::string name;
        uint time;
        bool isStringValueValid(std::string value);
        virtual void print(std::ostream &out) const=0;
        virtual void read(std::istream &in)=0;
    
    public:
        std::string getName();
        uint getTime();
        void setName(std::string name);
        void setTime(uint time);
        virtual std::string getTaskCategory()=0;

        friend std::ostream& operator<<(std::ostream &out, const Task &task);
        friend std::istream& operator>>(std::istream &in, Task &task);

        virtual ~Task();
};