#include <stdio.h>
#include "tokenizer.c"

#define MAX_INPUT_LEN 100
int main( )
{
  char input[MAX_INPUT_LEN];
  
  printf("The program name is Tokenizer. Please input a message:\n> ");
  // fgets(input, MAX_INPUT_LEN, stdin);
  //printf("Your input was: %s", input);
  char str[] = "Hello World my name is Cassandra Alvarez this is my test";
  char* point = &str[0];
  printf("the value of first char: %c\n", point[0]);
  printf("the value of point %p\n", point );
  printf("the value stored inside point %c\n", *point );
  
  char *start = token_start(point);
  printf("start value: %c\n", *start);
  char *terminator = token_terminator( point );
  printf("terminator value: %c\n", *terminator);
  printf("how many tokens in this string?: %d\nExpected: 11\n", count_tokens( point) );
  short len = 5;
  char *copy = copy_str( point, len );
  printf("the value of copy_str: %s", *copy);
}
