#include <stdio.h>
#include <stdlib.h>
#include "hand.h"

void initializeHand(Hand *hand) {
    hand->size = 0;
}

void drawCardToHand(Hand *hand) {
    if (deckSize == 0) {
        printf("No cards left in the deck to draw.\n");
        return;
    }
    hand->cards[hand->size] = drawCard();
    hand->size++;
}

void printHand(const Hand *hand) {
    printf("Hand contains %d cards:\n", hand->size);
    for (int i = 0; i < hand->size; i++) {
        printf("%d: %s of %s\n", i + 1, rankToString(hand->cards[i].rank), suitToString(hand->cards[i].suit));
    }
}

int placeCard(Hand *hand, int index, Suit *currentSuit,int isPlayer) {
    if (index < 0 || index >= hand->size) {
        printf("Invalid card index.\n");
        return 0;
    }

    Card cardToPlace = hand->cards[index];
    
    // Rule 1: Check if the card can be placed (must be the same suit or the same rank)
    if (cardToPlace.suit != *currentSuit && cardToPlace.rank != ACE && cardToPlace.rank != EIGHT) {
        printf("You can only place a card of the same suit, an Ace, or an Eight.\n");
        return 0;
    }

    // Print out the card being placed
    printf("Placing %s of %s\n", rankToString(cardToPlace.rank), suitToString(cardToPlace.suit));
    
    // Update current suit if an Eight is placed
    if (cardToPlace.rank == EIGHT) {
        if(isPlayer){
        int newSuit;
        printf("Choose a new suit (0: Hearts, 1: Diamonds, 2: Clubs, 3: Spades): ");
        scanf("%d", &newSuit);
        *currentSuit = (Suit)newSuit;
        printf("New suit is %s\n", suitToString(*currentSuit));
        }else{
            *currentSuit = (Suit)(rand() % 4); // AI chooses a random suit
            printf("AI chooses new suit: %s\n", suitToString(*currentSuit));
        }

    }else if(cardToPlace.rank == ACE || cardToPlace.rank == (*currentSuit != NO_SUIT ? cardToPlace.rank :NO_RANK)) {
        *currentSuit = cardToPlace.suit;
    }else {
        *currentSuit = cardToPlace.suit;
    }

    // Remove the card by moving the last card to the position being removed
    hand->cards[index] = hand->cards[hand->size - 1];
    hand->size--;

    return 1;
}

void printRemainingCards(const Hand *hand) {
    printf("Remaining cards in hand:\n");
    for (int i = 0; i < hand->size; i++) {
        printf("%d: %s of %s\n", i + 1, rankToString(hand->cards[i].rank), suitToString(hand->cards[i].suit));
    }
}
