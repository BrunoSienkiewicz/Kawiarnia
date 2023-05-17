#include "task.h"
#include "../Meal/meal.h"

class serveOrder : public Task
{
    private:
        std::unique_ptr<Meal> meal;
    
    public:
        serveOrder(std::string name, uint time, std::unique_ptr<Meal> meal);
        std::unique_ptr<Meal> getMeal();
        void setMeal(std::unique_ptr<Meal> meal);
};