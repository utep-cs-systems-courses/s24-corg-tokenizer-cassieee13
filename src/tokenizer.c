
#include "tokenizer.h"

int space_char(char c)
{
  if( c == '\t' | c == ' '){ //if the char IS a tab or space
    return 1;
  }
  return 0;
}

int non_space_char(char c)
{
  if( c != '\t' | c != ' '){ //if the char is NOT a tab or space
    return 1;
  }
  return 0;
}

char *token_start(char *str)
{
  while( *str != '\0'){ //all strings aka char arrays end with the '\0'
    
   if( space_char(*str) ){
      return *str;
   }
   *str += 1;
  }
  return *str;
}
