#include "task.h"
#include "../Client/client.h"
#include "../Client/order.h"
#include "../menu.h"


class getOrder : public Task
{
    private:
        uint tableId;
        std::unique_ptr<Client> client;
        std::unique_ptr<Order> order;

    public:
        getOrder(std::string name, uint time, uint tableId, std::unique_ptr<Client> client, std::unique_ptr<Order> order);
        uint getTableId();
        std::unique_ptr<Client> getClient();
        std::unique_ptr<Order> getTaskOrder();
        void setClient(std::unique_ptr<Client> client);
        void setOrder(std::unique_ptr<Order> order);
        void setTableId(uint tableId);

        void addMeal(std::unique_ptr<Meal> meal);
        void addMeal(std::string mealName, uint mealQuantity, std::unique_ptr<Menu> menu);
        void addMeal(uint index, uint mealQuantity, std::unique_ptr<Menu> menu);
        void removeMeal(uint mealId);
        void removeMeal(std::string mealName);
        void createOrder(std::unique_ptr<Menu> menu);
};