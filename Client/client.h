#include <iostream>
#include <string>
#include <memory>
#include <vector>
#pragma once


class Client
{
    private:
        std::string firstName;
        std::string lastName;
        float money;

    public:
        Client(std::string firstName, std::string lastName, float money);
        std::string getFirstName();
        std::string getLastName();
        float getMoney();
        void setMoney(float money);
        friend std::ostream& operator<<(std::ostream &out, const Client& client);
        friend std::istream& operator>>(std::istream &in, Client& client);
        ~Client();
};