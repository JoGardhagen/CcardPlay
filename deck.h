#ifndef DECK_H
#define DECK_H

#include "card.h"

#define DECK_SIZE 52

typedef struct {
    Card *cards;
    int size;
    int capacity;
} CardPile;

extern CardPile deck;  // Ändrat från extern Card deck[DECK_SIZE]

void initializeDeck();
void shuffleDeck();
Card drawCard();

int isPlayable(Card card, Card topCard);
void initializeCardPile(CardPile *pile, int initialCapacity);
void addCardToPile(CardPile *pile, Card card);
void printCardPile(CardPile *pile);
void freeCardPile(CardPile *pile);
void drawMultipleCardsToHand(CardPile *hand, int count, CardPile *deck, CardPile *discardPile);
void reshuffleDeck(CardPile *deck, CardPile *discardPile);
void chooseNewSuit();

#endif
