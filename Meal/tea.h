#include "meal.h"
#include "size.h"
#pragma once


class Tea : public Meal
{
    private:
        Size size;
        uint sugar;
        
        void print(std::ostream& os) const override;
        void read(std::istream& is) override;
    
    public:
        Tea(std::string name, Size size, uint sugar);
        Size getSize();
        uint getSugar();
        void setSize(Size size);
        void setSugar(uint sugar);
        std::string getMealCategory() override;
        double calculatePrice() const override;

        ~Tea();

        friend
        std::ostream& operator<<(std::ostream& os, const Tea& tea);

        friend
        std::istream& operator>>(std::istream& is, Tea& tea);
};