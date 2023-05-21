#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "order.h"
#include "table.h"
#pragma once


class Bill
{
    private:
        std::vector<std::unique_ptr<Order>> orders;
        std::unique_ptr<Table> table;

    public:
        Bill(std::unique_ptr<Table> table);
        std::vector<std::unique_ptr<Order>> getOrders();
        std::unique_ptr<Table> getTable();
        void addOrder(std::unique_ptr<Order> order);
        void removeOrder(uint orderId);
        void removeOrder(std::unique_ptr<Order> order);
        void removeOrder(std::string orderName);

        float getAmount();

        friend std::ostream& operator<<(std::ostream &out, const Bill& bill);
        friend std::istream& operator>>(std::istream &in, Bill& bill);
        ~Bill();
};