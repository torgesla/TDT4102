#include "Blackjack.h"
#include "Carddeck.h"
Player::Player()
{
}
void Player::getCard(Card card)
{
    cardsOnHand.push_back(card);
}
int Player::sumOfHand()
{
    vector<int> possibleSums;
    int sum = 0;
    for (int i = 0; i < cardsOnHand.size(); i++)
    {
        int rank = cardsOnHand[i].getRank() + 2; // first element in enum is 2
        if (rank <= 10)
        { // Add card value to sum if lower than jack
            sum += rank;
        }
        else if (rank != 14)
        { //Add 10 to sum if J, Q or K
            sum += 10;
        }
        else
        {
            break; //Pass
        }
    }
}
void Player::printCardsOnHand()
{
    cout << "This is your cards: " << endl;
    for (int i = 0; i < cardsOnHand.size(); i++)
    {
        cout << cardsOnHand[i].toString() << endl;
    }
}
bool Player::isOut()
{
    return sumOfHand() > 21;
}

bool Player::hasLost()
{
    return sumOfHand() > 21;
}
bool Player::hasBlackjack()
{
    return sumOfHand() == 21;
}
bool playerHasWon(Player player, Player dealer)
{
    if (player.hasLost() || dealer.hasBlackjack()) // Du overstiger 21 ELLER dealer har blackjack
    {
        return false;
    }
    else if (dealer.hasLost() || player.hasBlackjack()) // Du får ekte blackjack uten at dealer gjør det samme
    {                                                   // ELLER Din hånd har verdi mindre enn 21, mens dealerens hånd overstiger 21
        return true;
    }
    else
    {
        return player.sumOfHand() > dealer.sumOfHand(); // Du oppnår en høyere hånd enn dealer uten å overstige 21
    }
}
bool dealerMustStand(Player dealer)
{
    return dealer.sumOfHand() >= 17;
}
bool someoneHasBlackjack(Player player, Player dealer)
{
    return player.hasBlackjack() || dealer.hasBlackjack();
}
bool endGame(Player player, Player dealer)
{
    return someoneHasBlackjack(player, dealer) || player.hasLost() || dealer.hasLost();
}

void playGame()
{

    CardDeck deck = CardDeck();
    deck.shuffle();
    Player player = Player();
    Player dealer = Player();

    bool playerIsFinished = false;

    deck.initGame(player, dealer); // Give player and dealer two cards on hand

    while (!playerIsFinished)
    {
        player.printCardsOnHand();
        cout << "Do you want to draw another card? (y/n)" << endl;
        char answer;
        cin >> answer;
        while (true)
        {
            if (answer == 'y')
            {
                player.getCard(deck.drawCard());
                cout << "You received a card" << endl;
                break;
            }
            else if (answer == 'n')
            {
                playerIsFinished == true; // Change var if player decides to end receiving cards
                break;
            }
            else
            {
                cout << "Illegal char, try again." << endl;
            }
        }
        if (!dealerMustStand(dealer))
        {
            dealer.getCard(deck.drawCard());
            cout << "Dealer draw a card" << endl;
        }
        if (endGame(player, dealer))
        {
            break;
        }
    }
    if (playerHasWon(player, dealer))
    {
        cout << "You have WON" << endl;
    }
    else
    {
        cout << "Dealer has WON" << endl;
    }
    cout << "You have sum of " << to_string(player.sumOfHand()) << endl;
    cout << "Dealer have " << to_string(player.sumOfHand()) << endl;
}