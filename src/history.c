#include "history.h"
#include "tokenizer.h"
#include <stdlib.h>
#include <stdio.h>

Item *rootM = NULL;
List *history = NULL;
/* 
   list: s_item *root
   item: int id, char *str, s_item* next 
*/
List* init_history()
{
  if( history == NULL){ //if you have never initialized history, then the list is empty
    List *hist = malloc( sizeof(List) );
    history = hist; 
    history->root = rootM; //this function creates a brand new list with a empty node. 
  }
  
}

void add_history(List *list, char* str){
  if( list->root == NULL){ //in a new list, the root node is equal to NULL
    Item *newItem = malloc( sizeof(Item) );
    newItem->next = NULL;
    newItem->id = 1;//i am guessing id is the index of the node in the list

    int len = count_tokens( str ); int sindex = 0;
    char* scopy = malloc( (len+1) * sizeof(char) ), c;
    do{
      c = *(scopy + sindex) = *(str + sindex);
      sindex++;//inspiration from the bst.c
    }while (c);
    newItem->str = scopy;
    list->root = newItem;
  }
  else{
    Item *newItem = malloc( sizeof(Item) );
    Item *curr = malloc( sizeof(Item) );
    curr = list->root;
    while( (curr->next) != NULL){ //this should traverse the linked list
      curr = curr->next;
    }
    newItem->id = (curr->id)+1;//set the id attribute
    int len = count_tokens( str ); int sindex = 0;
    char* scopy = malloc( (len+1) * sizeof(char) ), c;
    do{
      c = *(scopy + sindex ) = *(str + sindex);
      sindex++;
    }while(c);
    newItem->str = scopy;//set the str attribute
    curr->next = newItem;//maintained the linked list.
    newItem->next = NULL;//set the next attribute
    //newItem id, str, and next have been set.
  }
}

char* get_history( List *list, int id){
  Item *curr = malloc( sizeof(Item) );
  curr = list->root;
  while( curr->next != NULL) {
    if( curr->id == id){
      return curr->str;
    }
    curr = curr->next;//move the pointer forward
  }
  printf("there is not that many nodes");
  return 0;
}

void print_history(List *list){
  Item *curr = malloc( sizeof( Item ) );
  char **tokens = malloc( sizeof(char**) );
  curr = list->root;
  while( curr->next != NULL ){
    tokens = tokenize(curr->str); //tokenize takes a char * as an argument and returns a char **
    print_tokens( tokens );
    curr = curr->next; //move forward
  }
  tokens = tokenize( curr->str );
  print_tokens( tokens );
  return;
}

void free_history(List *list){
  if( list->root == NULL){
    free(list);
    return;
  }
  Item *curr = malloc( sizeof(Item) );
  curr = list->root;
  list->root = list->root->next;
  //free_tokens( curr->str);
  free( curr->str );
  free( curr );
  
}
