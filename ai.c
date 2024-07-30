#include <stdio.h>
#include "card.h"
#include "card_pile.h"
#include "deck.h"
#include "gameplay.h"
#include "ai.h"

void aiPlayTurn(CardPile *hand, CardPile *discardPile, Card *topCard) {
    // Enkel AI-algoritm: spela ett kort om det är spelbart, annars dra ett kort
    int played = 0;
    for (int i = 0; i < hand->size; i++) {
        if (isPlayable(hand->cards[i], *topCard)) {
            // Spela kortet
            printf("AI plays: ");
            printCard(hand->cards[i]);
            printf("\n");
            addCardToPile(discardPile, hand->cards[i]);
            removeCardFromPile(hand, i);
            *topCard = hand->cards[i];
            played = 1;
            break;
        }
    }

    if (!played) {
        // Om inget kort kan spelas, dra ett kort
        printf("AI draws a card.\n");
        drawCard(&deck);
    }
}
