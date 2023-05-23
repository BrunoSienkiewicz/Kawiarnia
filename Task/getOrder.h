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
        getOrder(std::string name, uint time, uint tableId, Client client, Order order);
        uint getTableId();
        Client getClient();
        Order getTaskOrder();
        void setClient(Client client);
        void setOrder(Order order);
        void setTableId(uint tableId);

        void addMeal(Meal meal);
        void addMeal(std::string mealName, uint mealQuantity, Menu menu);
        void addMeal(uint index, uint mealQuantity, Menu menu);
        void removeMeal(uint mealId);
        void removeMeal(std::string mealName);
};