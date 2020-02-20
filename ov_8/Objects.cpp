#include "std_lib_facilities.h"
#include "Objects.h"

//Car
Car::Car(int numberOfSeats) : freeSeats(numberOfSeats) {}
bool Car::hasFreeSeats() const { return freeSeats > 0; }
void Car::reserveFreeSeat() { freeSeats--; }
//Person
Person::Person(string name, string email, Car *car) : name(name), email(email), car(car) {}
Person::Person(string name, string email) : Person(name, email, nullptr) {}
std::string Person::getName() const { return name; }
std::string Person::getEmail() const { return email; }
void Person::setEmail(string email) { this->email = email; }

bool Person::hasAvailableSeats() const { return car->hasFreeSeats(); }
ostream &operator<<(ostream &os, const Person &person)
{
    os << person.getName() << "\t" << person.getEmail() << "\t" << person.hasAvailableSeats() << endl;
    return os;
}
