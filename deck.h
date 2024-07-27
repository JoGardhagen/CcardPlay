//deck.h
#ifndef DECK_H
#define DECK_H

#define DECK_SIZE 52

typedef enum {
    HEARTS,
    DIAMONDS,
    CLUBS,
    SPADES
} Suit;

typedef enum {
    TWO = 2,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE
} Rank;


typedef struct{
    Rank rank;
    Suit suit;
}Card;

// Extern variabel för att tillgång till kortleken
extern Card deck[DECK_SIZE];
extern int deckSize;

// Funktion för att initialisera kortleken
void initializeDeck();
Card drawCard();
void drawMultipleCards(int numberOfCards);

const char* suitToString(Suit suit);
const char* rankToString(Rank rank);

#endif