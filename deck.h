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

typedef struct {
    Card *cards;
    int size;
    int capacity;
} CardPile;

extern CardPile deck;  // Ändrat från extern Card deck[DECK_SIZE]

void initializeDeck();
void shuffleDeck();
Card drawCard();
const char* rankToString(Rank rank);
const char* suitToString(Suit suit);
int isPlayable(Card card, Card topCard);
void initializeCardPile(CardPile *pile, int initialCapacity);
void addCardToPile(CardPile *pile, Card card);
void printCardPile(CardPile *pile);
void freeCardPile(CardPile *pile);
void drawMultipleCardsToHand(CardPile *hand, int count, CardPile *deck, CardPile *discardPile);
void reshuffleDeck(CardPile *deck, CardPile *discardPile);
void printCard(Card card); 
void chooseNewSuit();

#endif
