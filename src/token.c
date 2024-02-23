#include <stdio.h>

#define MAX_INPUT_LEN 100
int main( )
{
  char input[MAX_INPUT_LEN];
  
  printf("The program name is Tokenizer. Please input a message:\n> ");
  // fgets(input, MAX_INPUT_LEN, stdin);
  //printf("Your input was: %s", input);
  char str[] = "Hello ";
  char* point = str;
  printf("the value inside input: %c\n", point[0]);
  
}
