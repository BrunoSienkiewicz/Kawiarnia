#pragma once
#include <iostream>
#include <string>
#include "../exceptions/minimumWageException.h"
#include "../exceptions/negativeHoursException.h"
#include "../exceptions/exceedingHoursException.h"
#include "../Task/task.h"

class Worker
{
    protected:
        std::string name;
        std::string position;
        float rate;
        float schedule[7];
        float sal;
        std::vector<std::unique_ptr<Task>> tasks;
        // Nazwy zadań, które może wykonywać pracownik
        std::vector<std::string> possibleTasks;

    public:
        Worker(std::string name, std::string position, float rate);
        Worker(std::string name, std::string position, float rate, float schedule[7]);
        virtual std::string getName() const;
        virtual std::string getPosition() const;
        virtual float getRate() const;
        virtual float getHoursInWeek() const;
        virtual float getSalary() const;
        virtual float tip(float amount);
        virtual std::vector<std::unique_ptr<Task>> getTasks() const;
        virtual std::vector<std::string> getPossibleTasks() const;
        void setName(std::string name);
        void setPosition(std::string position);
        void setRate(float rate);
        void setSchedule(float schedule[7]);
        void setTasks(std::vector<std::unique_ptr<Task>> tasks);
        void setPossibleTasks(std::vector<std::string> possibleTasks);
        void addTask(std::unique_ptr<Task> task);
        void removeTask(std::unique_ptr<Task> task);
        void removeTask(int index);
        void removeTask(std::string name);

        virtual void doTask() = 0;

        friend
        std::ostream& operator<<(std::ostream& os, const Worker& worker);
};
