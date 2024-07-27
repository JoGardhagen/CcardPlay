#ifndef HAND_H
#define HAND_H

#include "deck.h"

#define NO_SUIT 4  // Om du använder enum Suit som har 0-3
#define NO_RANK 13 // Om du använder enum Rank som har 0-12

#define MAX_HAND_SIZE 52

typedef struct {
    Card cards[MAX_HAND_SIZE];
    int size;
} Hand;

void initializeHand(Hand *hand);
void drawCardToHand(Hand *hand);
void printHand(const Hand *hand);
int placeCard(Hand *hand, int index, Suit *currentSuit, int isPlayer);
void printRemainingCards(const Hand *hand);

#endif // HAND_H
