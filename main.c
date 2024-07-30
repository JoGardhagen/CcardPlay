#include <stdio.h>
#include <stdlib.h>
#include "deck.h"
#include "card.h"

// Funktion för att skriva ut spelarens hand
void printHand(CardPile *hand) {
    for (int i = 0; i < hand->size; i++) {
        printf("Card %d: ", i + 1);
        printCard(hand->cards[i]);
        printf("\n");
    }
}

// Kontrollera om det finns flera kort av samma rang i handen
int hasMultipleOfSameRank(CardPile *hand, Rank rank) {
    int count = 0;
    for (int i = 0; i < hand->size; i++) {
        if (hand->cards[i].rank == rank) {
            count++;
        }
    }
    return count > 1;
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
        printHand(&hand);

        // Visa kortet som är på bordet
        printf("\nTop card: ");
        printCard(topCard);
        printCardIllustrationASCII(topCard);
        printf("\n");

        printf("\nChoose a card to play (1-%d, or 0 to draw 3 cards): ", hand.size);
        int choice;
        scanf("%d", &choice);

        if (choice == 0) {
            drawMultipleCardsToHand(&hand, 3, &deck, &discardPile);
            continue;
        }

        if (choice < 1 || choice > hand.size) {
            printf("Invalid choice. Try again.\n");
            continue;
        }

        Card selectedCard = hand.cards[choice - 1];

        if (isPlayable(selectedCard, topCard)) {
             // Kolla om spelaren har flera kort av samma rang och vill spela dem
            if (hasMultipleOfSameRank(&hand, selectedCard.rank)) {
                playMultipleCardsOfSameRank(&hand, selectedCard.rank, &discardPile);
            }
            
            // Spela kortet
            topCard = selectedCard;
            printf("You played: ");
            printCard(selectedCard);
            printf("\n");


            // Lägg till kortet till kasseringshögen
            addCardToPile(&discardPile, selectedCard);
            removeCardFromPile(&hand, choice - 1);




            // Kolla om kortet var en 8a för att byta färg
            if (selectedCard.rank == EIGHT) {
                chooseNewSuit(&topCard);
            }
        } else {
            printf("Card is not playable.\n");
        }
    }

    printf("Congratulations! You have played all your cards.\n");

    return 0;
}
