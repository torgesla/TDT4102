#ifndef OBJECTS
#define OBJECTS
#include "std_lib_facilities.h"
class Car
{
private:
    int freeSeats;

public:
    Car(int numberOfSeats);
    bool hasFreeSeats() const;
    void reserveFreeSeat();
};

class Person
{
private:
    std::string name, email;
    Car *car;

public:
    Person(string name, string email, Car *car);
    Person(string name, string email);
    string getName() const;
    string getEmail() const;
    void setEmail(string email);
    bool hasAvailableSeats() const;
    friend std::ostream &operator<<(std::ostream &os, const Person &person);
};
#endif
