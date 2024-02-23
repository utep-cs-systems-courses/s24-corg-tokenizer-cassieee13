
#include "tokenizer.h"
#include <string.h>

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

char *token_start(char* str)
{
  int index = 0;
  while( str[index] != '\0' ){ //all strings aka char arrays end with the '\0'
    
   if( space_char( str[index]) ){//if you find a space in the char[]
     return str[index+1];//return the next value which is the start of the next token
   }
   index++;
  }
  return 0;
}

char *token_terminator(char *token)
{
  int index = 0;
  while( token[index] != '\0' ){
   if( space_char( token[index] )){
     return token[index-1]; //when it finds the space, that means the token has ended.
   }
   index++;
  }
  return 0;
}


