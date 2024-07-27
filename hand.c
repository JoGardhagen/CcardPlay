#include <stdio.h>
#include "hand.h"

void initializeHand(Hand *hand){
    hand->size = 0;
}

void drawCardToHand(Hand *hand){
    if(deckSize == 0){
        printf("No Cards left in the deck to draw.\n");
        return;
    }
    hand->cards[hand->size]= drawCard();
    hand->size++;
}

void printHand(const Hand *hand){
    printf("Hand contains %d cards:\n",hand->size);
    for(int i = 0;i<hand->size;i++){
        printf("%s of %s\n",hand->cards[i].rank,hand->cards[i].suit);
    }
}