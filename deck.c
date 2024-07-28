#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "deck.h"

Card deck[DECK_SIZE];
int deckSize = DECK_SIZE; // Initialize with full deck size

const char *rankNames[] = {"2", "3", "4", "5", "6", "7", "9", "10", "Jack", "Queen", "King", "Ace", "8"};
const char *suitNames[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

void initializeDeck() {
    int index = 0;
    for (int suit = 0; suit < NUM_SUITS; suit++) {
        for (int rank = 0; rank < NUM_RANKS; rank++) {
            deck[index].rank = rank;
            deck[index].suit = suit;
            index++;
        }
    }
    deckSize = DECK_SIZE; // Reset deck size
}

void shuffleDeck() {
    srand(time(NULL));
    for (int i = 0; i < DECK_SIZE; i++) {
        int j = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
    deckSize = DECK_SIZE; // Reset deck size after shuffling
}

Card drawCard() {
    if (deckSize <= 0) {
        printf("The deck is empty!\n");
        exit(1);
    }
    return deck[--deckSize];
}

void initializeHand(Hand *hand, int initialCapacity) {
    hand->cards = malloc(initialCapacity * sizeof(Card));
    if (hand->cards == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    hand->size = 0;
    hand->capacity = initialCapacity;
}

void drawCardToHand(Hand *hand) {
    if (deckSize == 0) {
        printf("No cards left in the deck to draw.\n");
        return;
    }
    if (hand->size >= hand->capacity) {
        hand->capacity *= 2; // Double the capacity
        hand->cards = realloc(hand->cards, hand->capacity * sizeof(Card));
        if (hand->cards == NULL) {
            fprintf(stderr, "Memory reallocation failed!\n");
            exit(1);
        }
    }
    hand->cards[hand->size++] = drawCard();
}

void freeHand(Hand *hand) {
    free(hand->cards);
}

const char* rankToString(Rank rank) {
    return rankNames[rank];
}

const char* suitToString(Suit suit) {
    return suitNames[suit];
}
