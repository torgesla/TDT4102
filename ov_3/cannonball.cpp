#define _USE_MATH_DEFINES

#include <cmath>
#include "std_lib_facilities.h"
#include "cannonball.h"
#include <math.h>

double acclY() { return -9.81; }
double velY(double initVelocityY, double time) { return initVelocityY + acclY() * time; }
double posX(double initPosition, double initVelocity, double time) { return initPosition + initVelocity * time; }
double posY(double initPosition, double initVelocity, double time) { return initPosition + initVelocity * time + (acclY() * pow(time, 2)) / 2; }
void printTime(double time)
{
    int h = time / 3600;
    int m = (time - h * 3600) / 60;
    int s = time - h * 3600 - m * 60;
    cout << h << ":" << m << ":" << s;
}
double flightTime(double initVelocityY) { return -2 * initVelocityY / acclY(); }

// Ber brukeren om en vinkel
double getUserInputTheta()
{
    double vinkel;
    cout << "Skriv en vinkel";
    cin >> vinkel;
    return vinkel;
}

//Ber brukeren om en absoluttfart
double getUserInputAbsVelocity()
{
    double velocity;
    cout << "Skriv en fart";
    cin >> velocity;
    return velocity;
}

// Konverterer fra grader til radianer
double degToRad(double deg) { return deg * M_PI / 180; }

// Returnerer henholdsvis farten i x-, og y-retning, gitt en vinkel
// theta og en absoluttfart absVelocity.
double getVelocityX(double theta, double absVelocity) { return sin(theta) * absVelocity; }
double getVelocityY(double theta, double absVelocity) { return cos(theta) * absVelocity; }

// Dekomponerer farten gitt av absVelocity, i x- og y-komponentene
// gitt vinkelen theta. Det første elementet i vectoren skal være
//x-komponenten, og det andre elementet skal være y-komponenten.
// "Vector" i funksjonsnavnet er vektor-begrepet i geometri
vector<double> getVelocityVector(double theta, double absVelocity)
{
    vector<double> velocity_vector;
    velocity_vector[0] = getVelocityX(theta, absVelocity);
    velocity_vector[1] = getVelocityY(theta, absVelocity);
    return velocity_vector;
}
double getDistanceTraveled(double velocityX, double velocityY) { return posX(0, velocityX, flightTime(velocityY)); }
double targetPractice(double distanceToTarget, double velocityX, double velocityY) { return distanceToTarget - getDistanceTraveled(velocityX, velocityY); }
