
#include "gameFunctions.h"


//a function that adds the card to the player's winning pile by calling
// the appropriate function from card_LList and update the cards won.
// Also marks the card as taken ('0').
void addCardToPlayer(Player* thePlayer, Card* theCard){
  insertFrontCard_LList(&thePlayer->winPile,theCard);
  thePlayer->cardsWon ++;
  theCard->value = '0';
  
 }

//a function that checks if the user choice is valid:
// if any of the choices are invalid, report that and return false.
bool checkPlayerInput(Deck* theDeck, Player* thePlayer, char row, char col){
  //checking indexes
  if (!((col>='a' && col<='m')&&(row>='0' && row<='3'))){
    printf ("Error: The card picked has an invalid index\n");
    return false;
  }

  int selection = (((row-'0')*13) + (col-'a'));
    // chck to see if already taken
  if(theDeck->cards[selection].value=='0'){
    printf("Error: This card has already been taken.\n");
    return false;
  }
 
 return true;
}



//a function that checks if there is a match:
// if the two choices are the same, report it and return false.
// if there is a match, return true; otherwise, return false.
bool checkForMatch(Deck* theDeck, Player* thePlayer,
char r1, char c1, char r2, char c2){
  int selection1= ((r1-'0')*13) + (c1-'a');
  int selection2 =((r2-'0')*13) + (c2-'a');
  
  // check if same card 
  if (selection1 == selection2){
    printf("Error: Both cards are the same\n");
    return false;
  }

  if (theDeck->cards[selection1].value==theDeck->cards[selection2].value){          
    return true; 
  }

  return false;
                 
}


//a function that checks if the game has a winner
// (all cards in the deck is taken)
bool checkForWinner(const Deck* theDeck){
  //checks to see if all cards taken
  for (int i = 0; i < NUM_OF_CARDS_IN_DECK; i++){
    if(theDeck->cards[i].value != '0'){
      return false;
    }
 }
  return true;
}


