#ifndef DECK_H
#define DECK_H

#include "card.h"

#define DECK_SIZE 52

typedef struct {
    Card cards[DECK_SIZE];
    int size;
    int capacity;
} CardPile;

extern CardPile deck;
extern CardPile discardPile;

void initializeDeck(CardPile *deck);
void shuffleDeck(CardPile *deck);
Card drawCard(CardPile *deck);
void addCardToPile(CardPile *pile, Card card);
void printCardPile(CardPile *pile);
void drawMultipleCardsToHand(CardPile *hand, int count, CardPile *deck, CardPile *discardPile);
void chooseNewSuit(Card *card);
void removeCardFromPile(CardPile *pile, int index);
int isPlayable(Card card, Card topCard);

// Ny funktion
int hasMultipleOfSameRank(CardPile *hand, Rank rank);
void playMultipleCardsOfSameRank(CardPile *hand, Rank rank, CardPile *discardPile, Card selectedCard, int initialChoice);
//void playMultipleCardsOfSameRank(CardPile *hand, Rank rank, CardPile *discardPile);


#endif // DECK_H
