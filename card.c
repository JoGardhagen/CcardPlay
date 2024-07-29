#include <stdio.h>
#include "card.h"


const char *rankNames[] = {"2", "3", "4", "5", "6", "7", "9", "10", "Jack", "Queen", "King", "Ace", "8"};
//const char *suitNames[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
const char *suitNames[] = {"♥", "♦", "♣", "♠"};

const char* rankToString(Rank rank) {
    return rankNames[rank];
}

const char* suitToString(Suit suit) {
    return suitNames[suit];
}

void printCard(Card card) {
    printf("%s of %s", rankToString(card.rank), suitToString(card.suit));
}