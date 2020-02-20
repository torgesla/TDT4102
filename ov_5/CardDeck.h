#ifndef CARDDECK
#define CARDDECK
#include "std_lib_facilities.h"
#include "Blackjack.h"

class CardDeck
{
private:
    vector<Card> cards;

public:
    CardDeck();
    void swap(int index1, int index2);
    void print();
    void printShort();
    void shuffle();
    Card drawCard();
    void CardDeck::initGame(Player &player, Player &dealer);
};
#endif