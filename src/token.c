#include <stdio.h>
#include "tokenizer.c"

#define MAX_INPUT_LEN 100
int main( )
{
  char input[MAX_INPUT_LEN];
  
  printf("The program name is Tokenizer. Please input a message:\n> ");
  // fgets(input, MAX_INPUT_LEN, stdin);
  //printf("Your input was: %s", input);
  char str[] = "Hello World";
  char* point = str;
  printf("the value of first char: %c\n", point[0]);

  printf("the value of the end of token: %c\n", token_terminator( point ) );
  printf("how many tokens in this string?: %d\n", count_tokens( str) );
}
