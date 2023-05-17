#include "prepareMeal.h"

template <class T>
PrepareMeal<T>::PrepareMeal(std::string name, uint time, std::unique_ptr<T> meal)
{
    if (!isStringValueValid(name))
        throw std::invalid_argument("Name is not valid");
    if (time < 1)
        throw std::invalid_argument("Time is not valid");
    if (meal == nullptr)
        throw std::invalid_argument("Meal is not valid");

    this->name = name;
    this->time = time;
    this->meal = meal;
}

template <class T>
std::unique_ptr<T> PrepareMeal<T>::getMeal()
{
    return meal;
}

template <class T>
void PrepareMeal<T>::setMeal(std::unique_ptr<T> meal)
{
    this->meal = meal;
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
    std::cout << "Prepare Meal task finished" << std::endl;
}

template <class T>
std::string PrepareMeal<T>::getTaskCategory()
{
    return "Prepare Meal";
}

template class PrepareMeal<Meal>;
template class PrepareMeal<Coffee>;
template class PrepareMeal<Cake>;
template class PrepareMeal<Tea>;
