//deck.h
#ifndef DECK_H
#define DECK_H

#define DECK_SIZE 52

typedef struct{
    const char *rank;
    const char *suit;
}Card;

// Extern variabel för att tillgång till kortleken
extern Card deck[DECK_SIZE];
extern int deckSize;

// Funktion för att initialisera kortleken
void initializeDeck();
Card drawCard();
void drawMultipleCards(int numberOfCards);

#endif