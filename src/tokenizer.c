
#include "tokenizer.h"
#include <stdlib.h>

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
  char *p;
  for( p = str; *p != '\0'; ++p){ //this loop will iterate over the char[], until it finds a space.
    if( space_char( *p ) ){
      return ++p;//previously I had p++ and it was returning the address of the space
     }
  }
  return 0;
}

char *token_terminator(char *token)
{
  char *p;
  for( p = token; *p != '\0'; ++p ){
    if( space_char( *p ) ){
      return --p;//similarly, this methods finds the space and returns the previous value
    }
  }
    return 0;
}

int count_tokens(char *str)
{
  char *p;
  int count = 0;
  char *start;
  for( p = str; *p != '\0'; p++){
    p = token_start( p );
    if( p == 0){//meaning it reached the end of the string because token_start returns 0 
      return count+1;
    }
    count++;
  }
  return count;
}

char *copy_str(char *inStr, short len)
{
  //reviewed malloc on geeksforgeeks.com
  char *copy;
  int i;
  //cast type malloc(byte size)
  copy = (char *) malloc(len+1);
  if( copy == NULL ){
    printf("I made it here");
    return 0;
  }
  for( i = 0; i < len; i++){
    printf("stored %c in str\n", *inStr);
    copy = inStr;
    copy++; inStr++;
  }
  copy[len+1] = '\0';
  return copy;
}
