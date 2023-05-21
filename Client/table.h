#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "client.h"
#pragma once


class Table
{
    private:
        uint id;
        std::vector<std::unique_ptr<Client>> clients;

    public:
        Table(uint id);
        uint getId();
        std::vector<std::unique_ptr<Client>> getClients();
        void addClient(std::unique_ptr<Client> client);
        void removeClient(uint clientId);
        void removeClient(std::unique_ptr<Client> client);
        void removeClient(std::string clientName);
        friend std::ostream& operator<<(std::ostream &out, const Table& table);
        friend std::istream& operator>>(std::istream &in, Table& table);
        ~Table();
};