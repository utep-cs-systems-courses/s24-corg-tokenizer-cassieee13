#include "stdlid.h"
#include "tokenizer.h"

int space_char(char c)
{
  if( c == '\t' | c == ' '){
    return 1;
  }
  return 0;
}

int non_space_char(char c)
{
  if( c != '\t' | c != ' '){
    return 1;
  }
  return 0;
}

char *token_start(char *str)
{
}
