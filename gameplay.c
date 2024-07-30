#include "gameplay.h"
#include <stdio.h>

// Välj ny färg för ett kort
void chooseNewSuit(Card *card) {
    int suitChoice;
    printf("Choose a new suit (1-Hearts, 2-Diamonds, 3-Clubs, 4-Spades): ");
    scanf("%d", &suitChoice);
    if (suitChoice >= 1 && suitChoice <= 4) {
        card->suit = suitChoice - 1;
    } else {
        printf("Invalid choice, keeping the same suit.\n");
    }
}

// Kontrollera om ett kort är spelbart
int isPlayable(Card card, Card topCard) {
    return (card.rank == topCard.rank || card.suit == topCard.suit || card.rank == EIGHT);
}
void playCard(CardPile *hand, int choice, CardPile *discardPile, Card *topCard) {
    Card selectedCard = hand->cards[choice - 1];
    printf("You played: ");
    printCard(selectedCard);
    printf("\n");

    // Lägg kortet i kasthögen
    addCardToPile(discardPile, selectedCard);
    removeCardFromPile(hand, choice - 1);

    // Hantera specialkort
    if (selectedCard.rank == EIGHT) {
        chooseNewSuit(&selectedCard);  // Låt spelaren välja ny färg
    }

    *topCard = selectedCard;
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

// Spela flera kort av samma rang
void playMultipleCardsOfSameRank(CardPile *hand, Rank rank, CardPile *discardPile, Card selectedCard, int initialChoice, Card *topCard) {
    printf("You played: ");
    printCard(selectedCard);
    printf("\n");
    addCardToPile(discardPile, selectedCard);
    removeCardFromPile(hand, initialChoice - 1);

    for (int i = 0; i < hand->size; ) {
        if (hand->cards[i].rank == rank) {
            printf("Play card %d: ", i + 1);
            printCard(hand->cards[i]);
            printf("? (y/n): ");
            char play;
            scanf(" %c", &play);

            if (play == 'y' || play == 'Y') {
                Card cardToPlay = hand->cards[i];
                printf("You played: ");
                printCard(cardToPlay);
                printf("\n");
                addCardToPile(discardPile, cardToPlay);
                removeCardFromPile(hand, i);
                if (hand->size == 0) break; // Stoppa om alla kort har spelats
            } else {
                i++;
            }
        } else {
            i++;
        }
    }

    // Uppdatera topCard till det sista spelade kortet
    if (discardPile->size > 0) {
        *topCard = discardPile->cards[discardPile->size - 1];
    }
}

// Hitta index för ett kort i handen
int findCardIndex(CardPile *hand, Card card) {
    for (int i = 0; i < hand->size; i++) {
        if (hand->cards[i].rank == card.rank && hand->cards[i].suit == card.suit) {
            return i;
        }
    }
    return -1; // Kortet finns inte i handen
}
