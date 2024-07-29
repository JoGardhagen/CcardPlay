#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "deck.h"
#include "card.h"

CardPile deck;
CardPile discardPile;

void initializeDeck(CardPile *deck) {
    deck->size = 0;
    deck->capacity = DECK_SIZE;
    for (int suit = 0; suit < NUM_SUITS; suit++) {
        for (int rank = 0; rank < NUM_RANKS; rank++) {
            if (rank != EIGHT) {
                deck->cards[deck->size].rank = rank;
                deck->cards[deck->size].suit = suit;
                deck->size++;
            }
        }
    }
    // Lägg till åttorna
    for (int suit = 0; suit < NUM_SUITS; suit++) {
        deck->cards[deck->size].rank = EIGHT;
        deck->cards[deck->size].suit = suit;
        deck->size++;
    }
}

void shuffleDeck(CardPile *deck) {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < deck->size; i++) {
        int j = rand() % deck->size;
        Card temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}

Card drawCard(CardPile *deck) {
    if (deck->size > 0) {
        return deck->cards[--deck->size];
    } else {
        fprintf(stderr, "The deck is empty!\n");
        exit(1);
    }
}

void addCardToPile(CardPile *pile, Card card) {
    if (pile->size < pile->capacity) {
        pile->cards[pile->size++] = card;
    } else {
        fprintf(stderr, "The pile is full!\n");
        exit(1);
    }
}

void removeCardFromPile(CardPile *pile, int index) {
    if (index < 0 || index >= pile->size) {
        fprintf(stderr, "Invalid index!\n");
        return;
    }
    for (int i = index; i < pile->size - 1; i++) {
        pile->cards[i] = pile->cards[i + 1];
    }
    pile->size--;
}

void printCardPile(CardPile *pile) {
    for (int i = 0; i < pile->size; i++) {
        printCard(pile->cards[i]);
        printf("\n");
    }
}

void drawMultipleCardsToHand(CardPile *hand, int count, CardPile *deck, CardPile *discardPile) {
    for (int i = 0; i < count; i++) {
        if (deck->size > 0) {
            addCardToPile(hand, drawCard(deck));
        } else {
            printf("No more cards left in the deck to draw. Shuffling discard pile into deck.\n");
            *deck = *discardPile; // Flytta kort från kasseringshögen till kortleken
            shuffleDeck(deck);
            discardPile->size = 0; // Töm kasseringshögen
            if (deck->size > 0) {
                addCardToPile(hand, drawCard(deck));
            } else {
                printf("No cards left to draw.\n");
                break;
            }
        }
    }
}

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
int isPlayable(Card card, Card topCard) {
    return card.rank == topCard.rank || card.suit == topCard.suit || card.rank == EIGHT;
}

void playMultipleCardsOfSameRank(CardPile *hand, Rank rank, CardPile *discardPile) {
    printf("You have multiple cards of the same rank. Do you want to play them? (y/n): ");
    char playMore;
    scanf(" %c", &playMore);

    if (playMore == 'y' || playMore == 'Y') {
        int i = 0;
        while (i < hand->size) {
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
                } else {
                    i++;
                }
            } else {
                i++;
            }
        }
    }
}
