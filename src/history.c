#include "history.h"
#include "tokenizer.h"
#include <stdlib.h>

s_Item * rootM = 0;
s_List* history = NULL;
/* 
   s_list: s_item *root
   s_item: int id, char *str, s_item* next 
*/
List* init_history()
{
  if( *history == NULL){
    s_List *hist = malloc( sizeof(s_List) );
    history = &hist; 
    history->root = *rootM;
    
  }
}

List* add_history(List *list, char* str){
  if( history->root == 0){
    s_Item *newItem = malloc( sizeof(s_Item) );
    newItem->next = 0;
    newItem->id = 1;

    int len = count_tokens( str ); sindex = 0;
    char* scopy = malloc( (len+1) * sizeof(char) ), c;
    do{
      c = *(scopy + sindex) = *(str + sindex);
      sindex++;
    }while (c);
    newItem->str = scopy;
    *rootM = newItem;
  }
  else{
    s_Item curr = &(history->root);
    if( curr->next == 0 ){
      c
  }
}
