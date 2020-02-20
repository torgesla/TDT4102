#ifndef CARD
#define CARD

#include "std_lib_facilities.h"
enum Suit
{
    clubs,
    diamonds,
    hearts,
    spades
};
enum Rank
{
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king,
    ace
};
class Card
{
private:
    Suit s;
    Rank r;

public:
    Card(Suit suit, Rank rank);
    Suit getSuit();
    Rank getRank();
    std::string toString();
    std::string toStringShort();
};
#endif

std::string suitToString(Suit suit);
std::string rankToString(Rank rank);
/*
    Her må du svare på teorien
    I denne oppgaven har vi valgt å represenetere farge og verdi på kort som symboler. 
    Nevn to fordeler ved å bruke symboler framfor f.eks. heltall og strenger i koden.
*/
