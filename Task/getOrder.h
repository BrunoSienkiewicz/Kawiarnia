#include "task.h"
#include "../menu.h"
#include "../Meal/coffee.h"
#include "../Meal/cake.h"


class getOrder : public Task
{
    private:
        std::unique_ptr<Menu> menu;
        std::unique_ptr<Meal> meal=nullptr;
        std::string mealName;
        template <class T>
        std::unique_ptr<Meal> getMealFromOrder(T meal);
    
    public:
        getOrder(std::string name, uint time, std::unique_ptr<Menu> menu, std::string mealName);
        std::unique_ptr<Menu> getMenu();
        void setMenu(std::unique_ptr<Menu> menu);
        std::string getMealName(); 
        void setMealName(std::string mealName);
        std::unique_ptr<Meal> getMeal();

        std::string getTaskCategory() override;
};