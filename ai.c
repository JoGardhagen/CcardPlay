#include <stdio.h>
#include <stdlib.h>
#include "ai.h"

int findBestCardToPlay(const Hand *hand, Suit currentSuit) {
    int bestCardIndex = -1;

    // Leta efter det högsta kortet som kan spelas
    for (int i = 0; i < hand->size; i++) {
        if (hand->cards[i].suit == currentSuit || hand->cards[i].rank == ACE || hand->cards[i].rank == EIGHT) {
            if (bestCardIndex == -1 || hand->cards[i].rank > hand->cards[bestCardIndex].rank) {
                bestCardIndex = i;
            }
        }
    }
    
    return bestCardIndex;
}

void aiPlay(Hand *hand, Suit *currentSuit) {
    int cardIndex = findBestCardToPlay(hand, *currentSuit);
    
    if (cardIndex == -1) {
        printf("AI has no valid cards to play.\n");
        // AI drar tre kort om den inte kan lägga något
        for (int i = 0; i < 3; i++) {
            drawCardToHand(hand);
        }
    } else {
        Card cardToPlace = hand->cards[cardIndex];
        printf("AI places %s of %s\n", rankToString(cardToPlace.rank), suitToString(cardToPlace.suit));
        placeCard(hand, cardIndex, currentSuit,0);

        // Om AI lägger ett ess, dra ett kort
        if (cardToPlace.rank == ACE) {
            drawCardToHand(hand);
        }

        // Om AI lägger en åtta, välj en ny färg
        /*if (cardToPlace.rank == EIGHT) {
            *currentSuit = (Suit)(rand() % 4); // Välj en slumpmässig ny färg
            printf("AI chooses new suit: %s\n", suitToString(*currentSuit));
        }*/
    }
}
