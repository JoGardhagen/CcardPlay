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

    printHand(&hand);
    

    return 0;
}