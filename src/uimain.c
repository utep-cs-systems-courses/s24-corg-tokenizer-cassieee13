#include <stdio.h>
#include "tokenizer.c"

int main()
{
  space_char('\t');
  space_char(' ');
  non_space_char(' ');
  non_space_char('c');
  return 0;
}
