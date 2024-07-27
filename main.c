#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "deck.h"
#include "hand.h"
#include "ai.h"

void printCurrentSuit(Suit currentSuit) {
    printf("Current suit: %s\n", suitToString(currentSuit));
}

int main() {
    srand(time(NULL)); // Seed för att generera slumpmässiga tal

    initializeDeck();
    shuffleDeck();

    Hand playerHand;
    initializeHand(&playerHand);

    Hand aiHand;
    initializeHand(&aiHand);

    // Dra 5 kort till båda spelarna som exempel
    for (int i = 0; i < 5; i++) {
        drawCardToHand(&playerHand);
        drawCardToHand(&aiHand);
    }

    Suit currentSuit = HEARTS; // Startfärg
    int playerIndexToPlace;
    
    while (playerHand.size > 0 && aiHand.size > 0) {

        printCurrentSuit(currentSuit);
        // Spela för spelaren
        printf("\nYour hand:\n");
        printHand(&playerHand);
        printf("Enter the number of the card to place (1-%d): ", playerHand.size);
        scanf("%d", &playerIndexToPlace);
        playerIndexToPlace--; // Omvandla till 0-baserat index

        int cardPlaced = placeCard(&playerHand, playerIndexToPlace, &currentSuit,1);

        // Om spelaren inte kan lägga något kort, dra tre kort
        if (!cardPlaced) {
            printf("You can't place any valid card. Drawing three cards.\n");
            for (int i = 0; i < 3; i++) {
                drawCardToHand(&playerHand);
            }
        } else {
            // Om spelaren har lagt ett ess, dra ett kort
            if (playerHand.cards[playerHand.size - 1].rank == ACE) {
                drawCardToHand(&playerHand);
            }
        }

        // AI spelar
        printf("\nAI's turn:\n");
        aiPlay(&aiHand, &currentSuit);

        // Om AI lägger ett ess, dra ett kort
        if (aiHand.cards[aiHand.size - 1].rank == ACE) {
            drawCardToHand(&playerHand);
        }

        // Avsluta om någon av spelarna inte har några kort kvar
        if (playerHand.size == 0 || aiHand.size == 0) {
            printf("Game over!\n");
            break;
        }
    }

    // Skriv ut slutresultat
    printf("\nFinal hands:\n");
    printf("Your final hand:\n");
    printHand(&playerHand);
    printf("AI's final hand:\n");
    printHand(&aiHand);

    return 0;
}
