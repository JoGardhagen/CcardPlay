#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "deck.h"

Card deck[DECK_SIZE];
int deckSize = DECK_SIZE;

const char* rankToString(Rank rank) {
    const char* ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    return ranks[rank];
}

const char* suitToString(Suit suit) {
    const char* suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    return suits[suit];
}

void initializeDeck() {
    int index = 0;
    for (int suit = HEARTS; suit <= SPADES; suit++) {
        for (int rank = TWO; rank <= ACE; rank++) {
            deck[index].rank = rank;
            deck[index].suit = suit;
            index++;
        }
    }
}

void shuffleDeck() {
    srand(time(NULL));
    for (int i = 0; i < DECK_SIZE; i++) {
        int j = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

Card drawCard() {
    if (deckSize == 0) {
        fprintf(stderr, "No cards left in the deck.\n");
        exit(1);
    }
    return deck[--deckSize];
}
