#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "deck.h"

CardPile deck;

const char *rankNames[] = {"2", "3", "4", "5", "6", "7", "9", "10", "Jack", "Queen", "King", "Ace", "8"};
const char *suitNames[] = {"Hearts", "Diamonds", "Clubs", "Spades"};


void initializeDeck() {
    deck.cards = malloc(DECK_SIZE * sizeof(Card));
    deck.size = DECK_SIZE;
    deck.capacity = DECK_SIZE;

    int index = 0;
    for (int suit = 0; suit < NUM_SUITS; suit++) {
        for (int rank = 0; rank < NUM_RANKS; rank++) {
            deck.cards[index].rank = rank;
            deck.cards[index].suit = suit;
            index++;
        }
    }
}

void shuffleDeck() {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < deck.size; i++) {
        int j = rand() % deck.size;
        Card temp = deck.cards[i];
        deck.cards[i] = deck.cards[j];
        deck.cards[j] = temp;
    }
}

Card drawCard() {
    if (deck.size > 0) {
        return deck.cards[--deck.size];
    } else {
        printf("The deck is empty!\n");
        exit(1);
    }
}

void initializeCardPile(CardPile *pile, int initialCapacity) {
    pile->cards = malloc(initialCapacity * sizeof(Card));
    pile->size = 0;
    pile->capacity = initialCapacity;
}

void addCardToPile(CardPile *pile, Card card) {
    if (pile->size >= pile->capacity) {
        pile->capacity *= 2;
        pile->cards = realloc(pile->cards, pile->capacity * sizeof(Card));
        if (pile->cards == NULL) {
            fprintf(stderr, "Memory reallocation failed!\n");
            exit(1);
        }
    }
    pile->cards[pile->size++] = card;
}
void printCard(Card card) {
    printf("%s of %s", rankToString(card.rank), suitToString(card.suit));
}

void printCardPile(CardPile *pile) {
    printf("Discard Pile:\n");
    for (int i = 0; i < pile->size; i++) {
        printf("Card %d: ", i + 1);
        printCard(pile->cards[i]);
        printf("\n");
    }
}

void freeCardPile(CardPile *pile) {
    free(pile->cards);
}

void reshuffleDeck(CardPile *deck, CardPile *discardPile) {
    for (int i = 0; i < discardPile->size; i++) {
        addCardToPile(deck, discardPile->cards[i]);
    }
    discardPile->size = 0;
    shuffleDeck();
}

void drawMultipleCardsToHand(CardPile *hand, int count, CardPile *deck, CardPile *discardPile) {
    for (int i = 0; i < count; i++) {
        if (deck->size == 0) {
            printf("Deck is empty, reshuffling discard pile into deck.\n");
            reshuffleDeck(deck, discardPile);
        }
        addCardToPile(hand, drawCard());
    }
}

const char* rankToString(Rank rank) {
    return rankNames[rank];
}

const char* suitToString(Suit suit) {
    return suitNames[suit];
}
