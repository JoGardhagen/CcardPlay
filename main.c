#include <stdio.h>
#include <stdlib.h>
#include "deck.h"

// Funktioner för att hantera kort
void printCard(Card card) {
    printf("%s of %s", rankToString(card.rank), suitToString(card.suit));
}

void printHand(Hand *hand) {
    for (int i = 0; i < hand->size; i++) {
        printf("Card %d: ", i + 1);
        printCard(hand->cards[i]);
        printf("\n");
    }
}

int isPlayable(Card card, Card topCard) {
    return card.rank == topCard.rank || card.suit == topCard.suit || card.rank == EIGHT;
}

void drawMultipleCardsToHand(Hand *hand, int count) {
    for (int i = 0; i < count; i++) {
        if (deckSize > 0) {
            drawCardToHand(hand);
        } else {
            printf("No more cards left in the deck to draw.\n");
            break;
        }
    }
}

int main() {
    // Initiera och blanda kortleken
    initializeDeck();
    shuffleDeck();

    // Dra ett kort från kortleken som det första kortet på bordet
    Card topCard = drawCard();
    printf("Initial top card: ");
    printCard(topCard);
    printf("\n");

    // Skapa och initiera spelarhanden
    Hand hand;
    initializeHand(&hand, INITIAL_HAND_SIZE);

    // Dra initiala kort till spelarhanden
    for (int i = 0; i < INITIAL_HAND_SIZE; i++) {
        drawCardToHand(&hand);
    }

    while (1) {
        printf("\nYour hand:\n");
        printHand(&hand);

        // Visa kortet som är på spel
        printf("\nTop card: ");
        printCard(topCard);
        printf("\n");

        printf("\nChoose a card to play (1-%d), or press 0 to draw 3 cards: ", hand.size);
        int choice;
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Drawing 3 new cards...\n");
            drawMultipleCardsToHand(&hand, 3);
            continue; // Gå tillbaka till början av loopen
        }

        if (choice < 1 || choice > hand.size) {
            printf("Invalid choice. Try again.\n");
            continue;
        }

        Card selectedCard = hand.cards[choice - 1];

        if (isPlayable(selectedCard, topCard) || selectedCard.rank == EIGHT) {
            // Spela kortet
            topCard = selectedCard;
            printf("You played: ");
            printCard(selectedCard);
            printf("\n");

            // Ta bort det spelade kortet från handen
            for (int i = choice - 1; i < hand.size - 1; i++) {
                hand.cards[i] = hand.cards[i + 1];
            }
            hand.size--;
        } else {
            printf("Card is not playable.\n");
        }
    }

    freeHand(&hand);
    return 0;
}
