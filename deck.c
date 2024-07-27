//deck.c
#include <stdio.h>
#include <stdlib.h>
#include "deck.h"

static const char *ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
static const char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

// Definition av den globala variabeln
Card deck[DECK_SIZE];
int deckSize = DECK_SIZE;

void initializeDeck() {
    int index = 0;
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            deck[index].rank = ranks[i];
            deck[index].suit = suits[j];
            index++;
        }
    }
}

Card drawCard(){
    if(deckSize == 0){
        fprintf(stderr,"No cards left in the deck\n");
        exit(EXIT_FAILURE);
    }

    int index = rand() % deckSize;
    Card drawCard = deck[index];
    
    deck[index] = deck[deckSize -1];
    deck[deckSize -1] = drawCard;

    deckSize--;

    return drawCard; 
}

void drawMultipleCards(int numberOfCards){
    if (numberOfCards >deckSize){
        printf("Cannot draw %d cards. Only %d cards left int the deck.\n",numberOfCards, deckSize);
        return;
    }

    for (int i = 0; i<numberOfCards;i++){
        Card card = drawCard();
        printf("Drew %s of %s\n",card.rank , card.suit);
    }

    printf("Remaining cards in deck: %d\n",deckSize);
}




