//deck.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "deck.h"

// Definition av den globala variabeln
Card deck[DECK_SIZE];
int deckSize = DECK_SIZE;

//static const char *ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
//static const char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

void initializeDeck() {
    Suit suits[] = {HEARTS, DIAMONDS, CLUBS, SPADES};
    Rank ranks[] = {TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE};

    int index = 0;
    /*for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            deck[index].rank = ranks[i];
            deck[index].suit = suits[j];
            index++;
        }
    }*/
    for(int i = 0;i<4;i++){
        for(int j= 0;j<13;j++){
            deck[index].suit=suits[i];
            deck[index].rank=ranks[j];
            index++;
        }
    }

    //Shuffle 
    srand(time(NULL));
    for (int i = 0; i < 52; i++)
    {
        int r = i +rand()/(RAND_MAX/(52-i)+1);
        Card temp = deck[i];
        deck[i]= deck[r];
        deck[r]=temp;
    }
    deckSize =52;
    
}

Card drawCard(){
    if(deckSize == 0){
        fprintf(stderr,"No cards left in the deck\n");
        exit(1);
    }
    return deck[--deckSize];

    /*int index = rand() % deckSize;
    Card drawCard = deck[index];
    
    deck[index] = deck[deckSize -1];
    deck[deckSize -1] = drawCard;

    deckSize--;

    return drawCard; */
}


/*
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
}*/

const char* suitToString(Suit suit) {
    switch (suit) {
        case HEARTS: return "Hearts";
        case DIAMONDS: return "Diamonds";
        case CLUBS: return "Clubs";
        case SPADES: return "Spades";
        default: return "Unknown";
    }
}

const char* rankToString(Rank rank) {
    switch (rank) {
        case TWO: return "2";
        case THREE: return "3";
        case FOUR: return "4";
        case FIVE: return "5";
        case SIX: return "6";
        case SEVEN: return "7";
        case EIGHT: return "8";
        case NINE: return "9";
        case TEN: return "10";
        case JACK: return "Jack";
        case QUEEN: return "Queen";
        case KING: return "King";
        case ACE: return "Ace";
        default: return "Unknown";
    }
}


