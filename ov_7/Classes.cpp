#include "std_lib_facilities.h"
#include "Classes.h"
#include "Graph.h"

Animal::Animal(std::string n, int a) : name(n), age(a) {}
Cat::Cat(std::string n, int a) : Animal(n, a) {}
Dog::Dog(std::string n, int a) : Animal(n, a) {}

string Animal::toString()
{
    //return typeof(this).name() + ": " + name + "," + std::to_string(age) + "\n";
    return "Animal: " + name + "," + std::to_string(age) + "\n";
}
string Dog::toString()
{
    //return Animal::toString();
    return "Dog: " + getName() + "," + std::to_string(getAge()) + "\n";
}
string Cat::toString()
{
    //return Animal::toString();
    return "Cat: " + getName() + "," + std::to_string(getAge()) + "\n";
}
void testAnimal()
{
    Graph_lib::Vector_ref<Animal> vector_ref;
    vector_ref.push_back(new Animal("Jakob", 24));
    vector_ref.push_back(new Dog("Torgeir", 24));
    vector_ref.push_back(new Cat("Einar", 23));
    vector_ref.push_back(new Animal("Audun", 12));
    vector_ref.push_back(new Cat("Mads", 15));
    vector_ref.push_back(new Dog("Ingrid", 30));

    for (auto it = vector_ref.begin(); it != vector_ref.end(); ++it)
    {
        cout << (*it)->toString();
    }
}