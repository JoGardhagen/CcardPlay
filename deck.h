#ifndef DECK_H
#define DECK_H

typedef enum {
    HEARTS,
    DIAMONDS,
    CLUBS,
    SPADES
} Suit;

typedef enum {
    TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
    JACK, QUEEN, KING, ACE
} Rank;

typedef struct {
    Rank rank;
    Suit suit;
} Card;

#define DECK_SIZE 52

extern Card deck[DECK_SIZE];
extern int deckSize;

void initializeDeck();
void shuffleDeck();
Card drawCard();
const char* rankToString(Rank rank);
const char* suitToString(Suit suit);

#endif // DECK_H
