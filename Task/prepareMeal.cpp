#include "prepareMeal.h"

template <class T>
PrepareMeal<T>::PrepareMeal(std::string name, uint time, T meal, Order& order) : Task(name, time, "Prepare Meal")
{
    setMeal(meal);
    setOrder(order);
}

template <class T>
PrepareMeal<T>::PrepareMeal(std::string name, uint time, Meal meal, Order& order) : Task(name, time, "Prepare Meal")
{
    T nMeal = dynamic_cast<T>(meal);
    setOrder(order);
    setMeal(nMeal);
}

template <class T>
T& PrepareMeal<T>::getMeal()
{
    return *this->meal;
}

template <class T>
void PrepareMeal<T>::setMeal(T meal)
{
    this->meal = std::make_unique<T>(meal);
}

template <class T>
void PrepareMeal<T>::print(std::ostream &out) const
{
    out << "Name: " << this->name << std::endl;
    out << "Time: " << this->time << std::endl;
    out << "Meal: " << std::endl;
    out << *this->meal;
}

template <class T>
void PrepareMeal<T>::read(std::istream &in)
{
    std::cout << "Name: ";
    in >> this->name;
    std::cout << "Time: ";
    in >> this->time;
    std::cout << "Meal: " << std::endl;
    in >> *this->meal;
}

template <class T>
std::ostream& operator<<(std::ostream &out, const PrepareMeal<T> &prepareMeal)
{
    prepareMeal.print(out);
    return out;
}

template <class T>
std::istream& operator>>(std::istream &in, PrepareMeal<T> &prepareMeal)
{
    prepareMeal.read(in);
    return in;
}

template <class T>
PrepareMeal<T>::~PrepareMeal()
{
    order.addMeal(*this->meal);
    std::cout << "Prepare Meal task finished" << std::endl;
}

template class PrepareMeal<Meal>;
template class PrepareMeal<Coffee>;
template class PrepareMeal<Cake>;
template class PrepareMeal<Tea>;
