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
        std::string taskCategory;
        bool isStringValueValid(std::string value);
        virtual void print(std::ostream &out) const;
        virtual void read(std::istream &in);
    
    public:
        Task(std::string name, uint time, std::string taskCategory);
        std::string getName();
        uint getTime();
        std::string getTaskCategory();
        void setName(std::string name);
        void setTime(uint time);

        friend std::ostream& operator<<(std::ostream &out, const Task &task);
        friend std::istream& operator>>(std::istream &in, Task &task);

        virtual ~Task();
};