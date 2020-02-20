#ifndef BLACKJACK
#define BLACKJACK

#include "std_lib_facilities.h"
#include "Card.h"
class Player
{
private:
    vector<Card> cardsOnHand;

public:
    Player();
    void getCard(Card card);
    int sumOfHand();
    void printCardsOnHand();
    bool isOut();

    bool hasLost();
    bool Player::hasBlackjack();
};
#endif
bool dealerMustStand(Player dealer);
bool playerHasWon(Player player, Player dealer);
bool someoneHasBlackjack(Player player, Player dealer);
void playGame();