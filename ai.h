#ifndef AI_H
#define AI_H

#include "card.h"
#include "card_pile.h"
#include "deck.h"

// Deklarationer för AI-funktioner
void aiPlayTurn(CardPile *hand, CardPile *discardPile, Card *topCard);

#endif // AI_H
