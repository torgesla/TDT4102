
#include "std_lib_facilities.h"
#include "Card.h"

std::map<Rank, std::string> mapOfRanks = {{two, "Two"}, {three, "Three"}, {four, "Four"}, {five, "Five"}, {six, "Six"}, {seven, "Seven"}, {eight, "Eight"}, {nine, "Nine"}, {ten, "Ten"}, {jack, "Jack"}, {queen, "Queen"}, {king, "King"}, {ace, "Ace"}};
std::map<Suit, std::string> mapOfSuits = {{clubs, "Clubs"}, {diamonds, "Diamonds"}, {hearts, "Hearts"}, {spades, "Spades"}};

Card::Card(Suit suit, Rank rank)
{
    s = suit;
    r = rank;
}
Suit Card::getSuit()
{
    return s;
}
Rank Card::getRank()
{
    return r;
}
string Card::toString()
{
    return rankToString(r) + " of " + suitToString(s);
}
string Card::toStringShort()
{
    return suitToString(s)[0] + std::to_string(r + 2); // Plus two because the value of the first element in enum is two
}

string suitToString(Suit suit)
{
    return mapOfSuits[suit];
}
string rankToString(Rank rank)
{
    return mapOfRanks[rank];
}
