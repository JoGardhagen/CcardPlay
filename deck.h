#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

typedef enum {
    HEARTS,
    DIAMONDS,
    CLUBS,
    SPADES,
    NUM_SUITS
} Suit;

typedef enum {
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE,
    EIGHT,
    NUM_RANKS
} Rank;

typedef struct {
    Rank rank;
    Suit suit;
} Card;

// Struktur för att hantera spelarens hand
typedef struct {
    Card *cards;
    int size;
    int capacity;
} Hand;

#define DECK_SIZE 52

extern Card deck[DECK_SIZE];
extern int deckSize;

void initializeDeck();
void shuffleDeck();
Card drawCard();
const char* rankToString(Rank rank);
const char* suitToString(Suit suit);
Card drawStartCard();  // Ny funktion för att dra startkort

// Struktur för att hantera en hand eller slänghög
typedef struct {
    Card *cards;
    int size;
    int capacity;
} CardPile;

void initializeCardPile(CardPile *pile, int initialCapacity);
void addCardToPile(CardPile *pile, Card card);
void freeCardPile(CardPile *pile);
void printCardPile(CardPile *pile);
void printCard(Card card); 

#endif
