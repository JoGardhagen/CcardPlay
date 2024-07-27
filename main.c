#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "deck.h"
#include "hand.h"

int main(){
    srand(time(NULL));


    initializeDeck();

    Hand hand;
    initializeHand(&hand);

    for (int i = 0; i < 5; i++)
    {
        drawCardToHand(&hand);
    }

    printf("Your hand:\n");
    printHand(&hand);


    Suit currentSuit = HEARTS;

    int indexToPlace;
    printf("Enter the number of the card to place (1-%d): ",hand.size);
    scanf("%d",&indexToPlace);
    indexToPlace--;

    placeCard(&hand,indexToPlace,currentSuit);

    printf("Updated hand:\n");
    printRemainingCards(&hand);

    return 0;
}