#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int main(int argc, char **argv )
{
  List* history = init_history();
  printf("The program name is <%s>\n", *(argv+0) );
  for( char **p = &argv[1]; *p; p++){
    add_history( history, *p);
  }
  print_history( history );
  free_history( history );
  //char *p = input;
  //char **tokens = tokenize( p );
  //print_tokens( tokens );
  //free_tokens( tokens );
  
  
}
