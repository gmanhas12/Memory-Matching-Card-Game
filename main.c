
#include <stdio.h>
#include <stdlib.h> //for the use of system and srand and rand
#include "gameObjects.h"
#include "gameFunctions.h"

#define MAX_CHAR_NUMBER 16 //each input should have at most 15 characters

//a helper function that clears the screen, works for both unix and Windows,
//though behaviour might be different.
//reference: https://stackoverflow.com/questions/2347770/
//            how-do-you-clear-the-console-screen-in-c
void clear() {
  #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("printf '\33[H\33[2J'");
  #endif

  #if defined(_WIN32) || defined(_WIN64)
    system("cls");
  #endif
}



int main() {
  //set the random seed to 0, it'll generate the same sequence
  //normally it is srand(time(NULL)) so the seed is different in every run
  //using 0 makes it deterministic so it is easier to mark
  //do not change it
  srand(0);

  //variables to store user input
  char userInput1[MAX_CHAR_NUMBER];
  char userInput2[MAX_CHAR_NUMBER];
  int whereInDeck = 0; //handy for indexing which card based on user input
  int whereInDeck2 = 0;//handy for indexing which card based on user input

  //set up the players
  Player player1, player2;
  initializePlayer(&player1, "Player 1");
  initializePlayer(&player2, "Player 2");
  Player* currentPlayer = &player1; //this pointer remembers who's turn it is

  //set up the deck: initalize & shuffle
  Deck myDeck;
  initializeDeck(&myDeck, "Bicycle");
  shuffleDeck(&myDeck);

  printDeck(&myDeck, true); //print the shuffled deck, face up
  printf("\n");
  clear(); //clear the screen

  /*
  Implement this part for the game to work.
  It is essentially a do-while loop that repeatedly print the deck,
  ask for user inputs, and do some checking. Ends if someone wins.
  */
  do {
    /////////////////////
    // 1 Round
    ////////////////////
    //Step 1: print the shuffled deck, face down
    printDeck(&myDeck, false);


    //Step 2: print who's turn it is by showing the player's name
    printf("\n%s's turn.\n",currentPlayer->name);


    //Step 3.1 get first input from player,
    // keep asking until the input is valid (hint: use a do-while loop)
    // you can assume that the format is correct (a digit<space>a letter)
    do{
      printf("Pick the first card you want to turn (e.g., 0 a) the press enter: ");
      fgets(userInput1, MAX_CHAR_NUMBER, stdin);
      
    }while (!checkPlayerInput(&myDeck, currentPlayer, userInput1[0], userInput1[2]));


    //Step 3.2: get second input from player,
    // keep asking until the input is valid (hint: use a do-while loop)
    // you can assume that the format is correct (a digit<space>a letter)
    do{
      printf("Pick the second card you want to turn (e.g., 0 a) the press enter: ");
      fgets(userInput2, MAX_CHAR_NUMBER, stdin);

      
    }while (!checkPlayerInput(&myDeck, currentPlayer, userInput2[0], userInput2[2]));


    //Step 4: print the 2 cards the player picks
    whereInDeck = ((userInput1[0]-'0')*13) + (userInput1[2]-'a');
    printf("\nFirst card picked: %c" ,myDeck.cards[whereInDeck].value);
    if(myDeck.cards[whereInDeck].suit == Spades){
          printf("\u2660");
    }
    else if(myDeck.cards[whereInDeck].suit == Hearts){
      printf("\u2661");
    }
    else if(myDeck.cards[whereInDeck].suit == Clubs){
      printf("\u2663");
    }
    else{
      printf("\u2662");
    }
    printf("\n");

    whereInDeck2 = ((userInput2[0]-'0')*13) + (userInput2[2]-'a');
    printf("Second card picked: %c" ,myDeck.cards[whereInDeck2].value);
    if(myDeck.cards[whereInDeck2].suit == Spades){
          printf("\u2660");
    }
    else if(myDeck.cards[whereInDeck2].suit == Hearts){
      printf("\u2661");
    }
    else if(myDeck.cards[whereInDeck2].suit == Clubs){
      printf("\u2663");
    }
    else{
      printf("\u2662");
    }
    printf("\n");
    
    

    //Step 5: call the checkForMatch function to see if the player has picked
    // a matching pair. If so, print the corresponding message and add the cards
    // to the player's winning pile (Player.winPile).
    // Keep the current player as a match leads to an extra round.
    // Otherwise, print the corresponding message and switch player.
  
    if(checkForMatch(&myDeck, currentPlayer, userInput1[0], userInput1[2], userInput2[0], userInput2[2])){
      printf("%s has found a match! Earns an extra turn\n",currentPlayer->name);
      addCardToPlayer(currentPlayer, &myDeck.cards[whereInDeck]);
      addCardToPlayer(currentPlayer, &myDeck.cards[whereInDeck2]);
    }
    
    else{
      printf("\n%s has not found a match.\n",currentPlayer->name);
      if(currentPlayer == &player1){
        currentPlayer = &player2;
      }
      else{
        currentPlayer = &player1;
      }

    }


  } while (!checkForWinner(&myDeck));

  //Step 6: find out who won the game and announce the winner
  
  printf("\nPlayer 1 has won %d cards\n", player1.cardsWon);
  printf("Player 2 has won %d cards\n", player2.cardsWon);
  if(player1.cardsWon == player2.cardsWon){
    printf("It's a tie.");
  }
  else if (player1.cardsWon > player2.cardsWon){
    printf("Player 1 has won!");
  }
  else{
    printf("Player 2 has won!");
  }

  //Step 7: clean up player's winning piles
  clearPlayer(&player1);
  clearPlayer(&player2);

  return 0;
}
