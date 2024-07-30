#include <stdio.h>
#include <stdlib.h>
#include "deck.h"
#include "card.h"
#include "gameplay.h"
#include <string.h>

// Funktion för att skriva ut spelarens hand
void printHand(CardPile *hand) {
    for (int i = 0; i < hand->size; i++) {
        printf("Card %d: ", i + 1);
        printCard(hand->cards[i]);
        printf("\n");
    }
}
void getDisplayRank(Rank rank, char *displayRank) {
    const char *rankStr = rankToString(rank);
    if (strcmp(rankStr, "Jack") == 0 || strcmp(rankStr, "Queen") == 0 || strcmp(rankStr, "King") == 0 || strcmp(rankStr, "Ace") == 0) {
        displayRank[0] = rankStr[0];
        displayRank[1] = '\0';
    } else {
        strcpy(displayRank, rankStr);
    }
}

void printHandIllustrationASCII(CardPile *hand) {
    printf("Hand:\n");
    
    // Print the top line
    for (int i = 0; i < hand->size; i++) {
        //printf("Card:%d",i+1);
        printf(" _____ ");
    }
    printf("\n");

    // Print the rank and left suit
    for (int i = 0; i < hand->size; i++) {
        char displayRank[3];
        getDisplayRank(hand->cards[i].rank, displayRank);
        printf("|%-2s   |", displayRank);
    }
    printf("\n");

    // Print the suit in the middle
    for (int i = 0; i < hand->size; i++) {
        const char *suit = suitToString(hand->cards[i].suit);
        printf("|  %s  |", suit);
    }
    printf("\n");

    // Print the rank and right suit
    for (int i = 0; i < hand->size; i++) {
        char displayRank[3];
        getDisplayRank(hand->cards[i].rank, displayRank);
        printf("|___%-2s|", displayRank);
    }
    printf("\n");
    // Skriv ut kortens indexpositioner
    
    for (int i = 0; i < hand->size; i++) {
        if (i < 9) {
            printf("   %d   ", i + 1); // För att se till att ensiffriga nummer har en extra plats
        } else {
            printf("  %d   ", i + 1); // Tvåsiffriga nummer får bara en extra plats
        }
    }
    printf("\n");
}



// Huvudprogrammet
int main() {
    // Initiera och blanda kortleken
    CardPile deck = { .cards = {0}, .size = 0, .capacity = DECK_SIZE };
    initializeDeck(&deck);
    shuffleDeck(&deck);

    // Initiera spelarens hand och kasseringshögen
    CardPile hand = { .cards = {0}, .size = 0, .capacity = DECK_SIZE };
    CardPile discardPile = { .cards = {0}, .size = 0, .capacity = DECK_SIZE };

    // Dra initiala kort till spelarens hand
    for (int i = 0; i < 5; i++) {
        addCardToPile(&hand, drawCard(&deck));
    }

    // Dra ett startkort till bordet från kortleken
    addCardToPile(&discardPile, drawCard(&deck));
    Card topCard = discardPile.cards[discardPile.size - 1];

    while (hand.size > 0) {
        printf("\nYour hand:\n");
        //printHand(&hand);

        printHandIllustrationASCII(&hand);

        printf("\nTop card: ");
        printCard(topCard);
        printCardIllustrationASCII(topCard);

        printf("\nChoose a card to play (1-%d, or 0 to draw 3 cards): ", hand.size);
        int choice;
        scanf("%d", &choice);

        if (choice == 0) {
            drawMultipleCardsToHand(&hand, 3, &deck, &discardPile);
        } else if (choice > 0 && choice <= hand.size) {
            Card selectedCard = hand.cards[choice - 1];

            if (isPlayable(selectedCard, topCard)) {
                if (hasMultipleOfSameRank(&hand, selectedCard.rank)) {
                    playMultipleCardsOfSameRank(&hand, selectedCard.rank, &discardPile, selectedCard, choice, &topCard);
                } else {
                    playCard(&hand, choice, &discardPile, &topCard);
                }
            } else {
                printf("Invalid card choice.\n");
            }
        } else {
            printf("Invalid choice.\n");
        }
        
    }

    

    printf("Congratulations! You have played all your cards.\n");

    return 0;
}
