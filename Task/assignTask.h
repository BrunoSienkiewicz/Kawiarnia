#include "task.h"


class AssignTask : public Task
{
    private:
        std::unique_ptr<Task> task;
        void print(std::ostream &out) const override;
        void read(std::istream &in) override;

    public:
        AssignTask(std::string name, uint time, std::unique_ptr<Task> task);
        std::unique_ptr<Task> getTask();
        void setTask(std::unique_ptr<Task> task);

        friend std::ostream& operator<<(std::ostream &out, const AssignTask &assignTask);
        friend std::istream& operator>>(std::istream &in, AssignTask &assignTask);

        ~AssignTask() override;
};