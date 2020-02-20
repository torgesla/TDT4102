#include "Blackjack.h"
#include "CardDeck.h"
CardDeck::CardDeck() // Constructor
{
    for (int suit_index = 0; suit_index < 4; suit_index++)
    {
        for (int rank_index = 0; rank_index < 13; rank_index++)
        {
            Suit suit = static_cast<Suit>(suit_index);
            Rank rank = static_cast<Rank>(rank_index);
            cards.push_back(Card(suit, rank));
        }
    }
}

void CardDeck::swap(int index1, int index2)
{
    std::swap(cards[index1], cards[index2]);
}

void CardDeck::print()
{
    for (int i = 0; i < cards.size(); i++)
    {
        cout << cards[i].toString() << endl;
    }
}

void CardDeck::printShort()
{
    for (int i = 0; i < cards.size(); i++)
    {
        cout << cards[i].toStringShort() << endl;
    }
}

void CardDeck::shuffle()
{
    int numberOfswaps = 10000;
    for (int i = 0; i < numberOfswaps; i++)
    {
        int index1 = rand() % cards.size();
        int index2 = rand() % cards.size();
        swap(index1, index2); // Randomize order of cards
    }
}

Card CardDeck::drawCard()
{
    Card last_element = cards[cards.size() - 1];
    cards.pop_back();
    return last_element;
}
void CardDeck::initGame(Player &player, Player &dealer)
{
    shuffle();
    player.getCard(drawCard());
    Card visibleCard = drawCard();
    cout << "The dealer received " << visibleCard.toString() << endl;
    dealer.getCard(visibleCard);
    player.getCard(drawCard());
    dealer.getCard(drawCard());
}