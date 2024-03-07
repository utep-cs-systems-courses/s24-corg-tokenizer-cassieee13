
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
  if( space_char( c )){ //if the char is NOT a tab or space
    return 0;
  }
  return 1;
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
  copy = malloc((len+1)* sizeof(char*)) ;
  if( copy == NULL ){
    printf("check copy_str\n");
    return 0;
  }
  //influenced by bstInsert
  for( i=0; i < len; i++){
    *(copy+i) = *(inStr + i);
  }
  return copy;
}
//needs to return an array of each token in the string
char **tokenize(char *str)
{
  int i;
  int count = count_tokens(str);
  //printf( "tokens: %d\n", count);
  /*
    I have had the most frustrating error where this function was ending at "hello" and copy_str was printing the message "check copy_str" which meant malloc was unable to work. after creating several print statements to debug my code, I decided to print the value of countLetters BEFORE sending it to copy_str and the value was -67234. This whole time it was because I was incrementing countLetters before assigning a value to countLetters. I fixed it with countLetters = 0; 
  */
  int countLetters = 0;
  char** tokens = malloc( (count+1) * sizeof( char) );
  int reachedEnd = 0; //acting as a boolean for the while loop
  char *temp = str; //temp and str share the same address
  
  for( i = 0; i < count; i++){
  
    while ( reachedEnd != 1  ){
      if( *temp == '\0'){
	reachedEnd = 1;
	break;
      }
      if(non_space_char( *temp ) ){
	//printf("in loop: %c\n", *temp);
	countLetters++;
       
      }
      else{
	reachedEnd = 1;
      }
      temp++;
    }
    //printf("count letters: %d", countLetters);
    tokens[i] = copy_str( str, countLetters); //stores the word in the array
    if( *temp == '\0' ){
      break;
    }
    countLetters = 0; //reset the count for the next word
    str = token_start( str ); // point to the beginning of the next word
    temp = str;
    reachedEnd = 0; //reset while loop condition
  }
  tokens[count] = 0;
  return tokens;
}

void print_tokens( char ** tokens) {
  int i = 0;
  while( tokens[i] != 0){
    printf("%s ",( tokens[i]) );
    i++;
  }
  printf("\n");
}
