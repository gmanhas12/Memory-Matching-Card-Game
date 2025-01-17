
#include "gameObjects.h"



char suits[14] = {'A','2','3','4','5', '6','7','8','9','T','J','Q','K'};

//a function that initializes all the fields of a Deck.
// For each suit, the values of the cards are
// ‘A’, ‘2’, ‘3’, …, ‘9’, ,'T', ‘J’, ‘Q’, ‘K’.
void initializeDeck(Deck* theDeck, char* brandName){
  theDeck->brand = brandName;
  for(int j = 0 ; j < 4; j++){
    for(int i = 0; i < 13; i++){
      theDeck->cards[i + j * 13].value = suits[i];
      if(j == 0){
        theDeck->cards[i].suit = Spades;
      }
      else if(j == 1){
        theDeck->cards[i + j * 13].suit = Hearts;
      }
      else if(j == 2){
        theDeck->cards[i + j * 13].suit = Clubs;
      }
      else{
        theDeck->cards[i + j * 13].suit = Diamonds;
      }

    }
  }
}

//a function that shuffles the deck
void shuffleDeck(Deck* theDeck){
  int j = 0;
  Card temp;
  for(int i = 0; i < 52 -1; i++){
    j = i + rand() / (RAND_MAX / (52 - i) + 1);
    temp = theDeck->cards[j];
    theDeck->cards[j] = theDeck->cards[i];
    theDeck->cards[i] = temp;
  }
  
}

//a function that prints the content of a Deck.
//accepts a second bool parameter:
//if true, print face up, if false, print face down.
//if the card is won by a player, leave it blank.
void printDeck(const Deck* theDeck, bool faceUp){
  printf("    a  b  c  d  e  f  g  h  i  j  k  l  m\n");
  for(int j = 0 ; j < 4; j++){
    printf("%d ",j);
    for(int i = 0; i < 13; i++){
      if(faceUp){
        printf(" %c",theDeck->cards[i + j * 13].value);
        if(theDeck->cards[i + j * 13].suit == Spades){
          printf("\u2660");
        }
        else if(theDeck->cards[i + j * 13].suit == Hearts){
          printf("\u2661");
        }
        else if(theDeck->cards[i + j * 13].suit == Clubs){
          printf("\u2663");
        }
        else{
          printf("\u2662");
        }
      }
      else{
        if(theDeck->cards[i + j * 13].value!= '0'){
          printf(" %c\u218C", '?');
        }
        else{
          printf("   ");
        }
        
      }
   }
    printf("\n");
  }
}


//a function that initializes all the fields of a Player.
void initializePlayer(Player* thePlayer, char* theName){
  thePlayer->name = theName;
  thePlayer->cardsWon = 0;

  Card_LList* temp = createCard_LList();
  if(temp == NULL){
    return;
  }
  thePlayer->winPile = *temp;
}

//a function clears the winning pile of the player by calling the necessary
// function on a Card_LList.
void clearPlayer(Player* thePlayer){
  clearCard_LList(&thePlayer->winPile);
  thePlayer->cardsWon = 0;
}