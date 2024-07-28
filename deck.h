#ifndef DECK_H
#define DECK_H

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

#define DECK_SIZE 52
#define INITIAL_HAND_SIZE 5

extern Card deck[DECK_SIZE];
extern int deckSize; // Current number of cards in the deck

void initializeDeck();
void shuffleDeck();
Card drawCard();

// Struktur och funktioner för att hantera spelarens hand
typedef struct {
    Card *cards;
    int size;
    int capacity;
} Hand;

void initializeHand(Hand *hand, int initialCapacity);
void drawCardToHand(Hand *hand);
void freeHand(Hand *hand);

const char* rankToString(Rank rank);
const char* suitToString(Suit suit);

#endif
