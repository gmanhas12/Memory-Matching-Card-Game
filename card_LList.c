#include "card_LList.h"

//a function that creates a new Card_LList, which is an empty linked list.
Card_LList* createCard_LList(){
  Card_LList* list=(Card_LList*)malloc(sizeof(Card_LList));
  if (list!=NULL){
    list->head=NULL;
	  list->tail=NULL;
	  return list;
  }
  return NULL;
}




//a function that removes all the nodes from the list
// by freeing them one by one. The result is an empty linked list.
void clearCard_LList(Card_LList* theList){
  Card_Node *current;
  Card_Node * temp;
    
    current = theList->head;
    while(current!= NULL)
    {
        temp = current; // store data of current node
        current = current->next;// Move to next node
        free(temp);// free data of stored node
    }
}


//a function that checks if the list is empty.
// If it is empty, return true; otherwise return false.
bool isEmptyCard_LList(Card_LList* theList){
  if(theList->head == NULL){
    return true;
  }
  return false;
}



//a function that inserts the card as a part of a node
// (the node itself doesn't store the card, but the address of the card).
// This method encapsulates the inner workings of the linked list and
// there is no need to duplicate the card.
void insertFrontCard_LList(Card_LList* theList, Card* theCard){
  Card_Node* newCard = (Card_Node*)malloc(sizeof(Card_Node));
  if (!newCard){
    return;
  }
  newCard->card = theCard;
  newCard->next= NULL;
  
  
  if(isEmptyCard_LList(theList)){
    theList->head = newCard;
    theList->tail = newCard;
  }
  else{
    newCard->next = theList->head;
    theList->head = newCard;
  }
 
}


//a function that inserts the card as a part of a node
// (the node itself doesn't store the card, but the address of the card).
// This method encapsulates the inner workings of the linked list and
// there is no need to duplicate the card.
void insertEndCard_LList(Card_LList* theList, Card* theCard){
  Card_Node* newCard = (Card_Node*)malloc(sizeof(Card_Node));
  if (!newCard){
    return;
  }
    newCard->card = theCard;
  	newCard->next= NULL;
  
  
  if(isEmptyCard_LList(theList)){
    theList->head = newCard;
    theList->tail = newCard;
  }
  else{
    theList->tail->next = newCard;
    theList->tail = newCard;
  }
 
}



//a function that returns the address of the card stored in the node.
// This method encapsulates the inner workings of the linked list and
// there is no need to duplicate the card.
// Freeing of the node memory is done here.
Card* removeFrontCard_LList(Card_LList* theList){
  if(isEmptyCard_LList(theList)){
    return NULL;
  }
  Card_Node* temp = theList->head;
  theList->head = theList->head->next;
  Card* tempCard = temp->card;
  free(temp);
  return  tempCard;
  
}
  
//a function that returns the address of the card stored in the node.
// This method encapsulates the inner workings of the linked list and
// there is no need to duplicate the card.
// Freeing of the node memory is done here.
Card* removeEndCard_LList(Card_LList* theList){
  if(isEmptyCard_LList(theList)){
    return NULL;
  }
  Card* temp = theList->tail->card;
  Card_Node* current = theList->head;
  
  while (current != theList->tail)
  {
    current = current->next;
  }
  free(theList->tail);
  theList->tail = current;
  return  temp;
}



