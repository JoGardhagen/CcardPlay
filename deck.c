#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "deck.h"

Card deck[DECK_SIZE];
int deckSize = DECK_SIZE;

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
    deckSize = DECK_SIZE;  // Återställ däckstorleken
}

void shuffleDeck() {
    srand(time(NULL));
    for (int i = 0; i < DECK_SIZE; i++) {
        int j = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
    deckSize = DECK_SIZE;  // Återställ däckstorleken efter blandning
}

Card drawCard() {
    if (deckSize > 0) {
        return deck[--deckSize];
    } else {
        printf("The deck is empty!\n");
        exit(1);
    }
}

Card drawStartCard() {
    Card card;
    do {
        card = drawCard();
    } while (card.rank == EIGHT || card.rank == ACE);
    return card;
}

const char* rankToString(Rank rank) {
    return rankNames[rank];
}

const char* suitToString(Suit suit) {
    return suitNames[suit];
}

void initializeCardPile(CardPile *pile, int initialCapacity) {
    pile->cards = malloc(initialCapacity * sizeof(Card));
    if (pile->cards == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    pile->size = 0;
    pile->capacity = initialCapacity;
}

void addCardToPile(CardPile *pile, Card card) {
    if (pile->size >= pile->capacity) {
        pile->capacity *= 2; // Dubbla kapaciteten
        pile->cards = realloc(pile->cards, pile->capacity * sizeof(Card));
        if (pile->cards == NULL) {
            fprintf(stderr, "Memory reallocation failed!\n");
            exit(1);
        }
    }
    pile->cards[pile->size++] = card;
}

void freeCardPile(CardPile *pile) {
    free(pile->cards);
}
