#include "std_lib_facilities.h"
class Animal
{
protected:
    std::string name;
    int age;

public:
    Animal();
    Animal(std::string name, int age);
    virtual std::string toString();
    string getName() { return name; }
    int getAge() { return age; };
};

class Cat : public Animal
{
private:
    std::string name;
    int age;

public:
    Cat();
    Cat(std::string name, int age);
    std::string toString();
};

class Dog : public Animal
{
private:
    std::string name;
    int age;

public:
    Dog();
    Dog(std::string name, int age);
    std::string toString();
};
void testAnimal();