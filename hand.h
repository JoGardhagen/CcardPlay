
#ifndef HAND_H
#define HAND_H

#include "deck.h"

typedef struct{
    Card cards[DECK_SIZE];
    int size;
}Hand;

void initializeHand(Hand *hand);
void drawCardToHand(Hand *hand);
void printHand(const Hand *hand);
void placeCard(Hand *hand, int index,Suit currentSuit);
void printRemainingCards(const Hand *hand);


#endif

