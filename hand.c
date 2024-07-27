#include <stdio.h>
#include "hand.h"

void initializeHand(Hand *hand){
    hand->size = 0;
}

void drawCardToHand(Hand *hand){
    if(deckSize == 0){
        printf("No Cards left in the deck to draw.\n");
        return;
    }
    hand->cards[hand->size]= drawCard();
    hand->size++;
}

void printHand(const Hand *hand){
    printf("Hand contains %d cards:\n",hand->size);
    for(int i = 0;i<hand->size;i++){
        //printf("%d of %d\n",hand->cards[i].rank,hand->cards[i].suit);
        //printf("%s of %s\n",hand->cards[i].rank,hand->cards[i].suit);
        printf("%d: %s of %s\n",i+1,rankToString(hand->cards[i].rank),suitToString(hand->cards[i].suit));
    }
}

void placeCard(Hand *hand,int index,Suit currentSuit){
    if(index <0 || index >= hand->size){
        printf("Invalid card index.\n");
        return;
    }

    Card cardToPlace = hand->cards[index];

    if(cardToPlace.suit != currentSuit &&cardToPlace.rank !=ACE){
        printf("You can only place a card of same suit or an ACE.\n");
        return;
    }

    //printf("Placing %d of %d\n",cardToPlace.rank, cardToPlace.suit);
    // Print out the card being placed
    printf("Placing %s of %s\n", rankToString(cardToPlace.rank), suitToString(cardToPlace.suit));
    

    //printf("Placing %s of %s\n",hand->cards[index].rank, hand->cards[index].suit);
    
    hand->cards[index] = hand->cards[hand->size -1];

    hand->size--;
}

void printRemainingCards(const Hand *hand){
    printf("Remaining cards in hand:\n");
    for(int i = 0;i < hand->size;i++){
        //printf("%d: %d of %d\n",i + 1,hand->cards[i].rank, hand->cards[i].suit);
        //printf("%d: %s of %s\n",i + 1,hand->cards[i].rank, hand->cards[i].suit);
        printf("%d: %s of %s\n", i + 1, rankToString(hand->cards[i].rank), suitToString(hand->cards[i].suit));
    }
}