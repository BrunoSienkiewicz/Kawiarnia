#pragma once
#include <iostream>
#include <string>
#include "../exceptions/minimumWageException.h"
#include "../exceptions/negativeHoursException.h"
#include "../exceptions/exceedingHoursException.h"
#include "../Task/task.h"
#include "helperFunctions.h"

class Worker
{
    protected:
        std::string name;
        std::string position;
        float rate;
        float schedule[7];
        float sal;
        bool isOccupied;
        std::vector<std::unique_ptr<Task>> tasks;
        // Nazwy zadań, które może wykonywać pracownik
        std::vector<std::string> possibleTasks;
        virtual void taskActions(Task& task);

    public:
        Worker(std::string name, std::string position, float rate);
        Worker(std::string name, std::string position, float rate, float schedule[7]);
        virtual std::string getName() const;
        virtual std::string getPosition() const;
        virtual float getRate() const;
        virtual float getHoursInWeek() const;
        virtual float getSalary() const;
        virtual float tip(float amount);
        virtual bool getIsOccupied() const;
        virtual std::vector<Task> getTasks() const;
        virtual std::vector<std::string> getPossibleTasks() const;
        void setName(std::string name);
        void setPosition(std::string position);
        void setRate(float rate);
        void setSchedule(float schedule[7]);
        void setIsOccupied(bool isOccupied);
        void setTasks(std::vector<Task> tasks);
        void setPossibleTasks(std::vector<std::string> possibleTasks);
        void addTask(Task task);
        void removeTask(Task task);
        void removeTask(int index);
        void removeTask(std::string name);

        virtual void doTask();

        friend
        std::ostream& operator<<(std::ostream& os, const Worker& worker);
};
