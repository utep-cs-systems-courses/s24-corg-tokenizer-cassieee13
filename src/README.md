Project 1: Tokenizer
====================
Before I explain the Tokenizer project, I would like to say that this lab
effectively challenged me and made me rethink majoring in Computer Science. I
regret allowing myself to fall behind because the more we moved forward and
this lab was still due, the worse I felt. Then I would revisit this lab and
still feel stuck and confused. I reread the chapters and watched videos but
most of the parts I was stuck on had nothing to do with the logic of the
program, it was small mistakes like missing a semicolon or the wrong < or >
signs.
	I will explain the two main files of this project, tokenizer.c and
	history.c. tokenizer.c includes eight methods that aid the main
	"tokenize" method. tokenize takes a char* as a parameter and returns a
	pointer of char pointers. The way I reminded myself to think about it
	was it was returning a pointer to an array of addresses which were
	more pointers that pointed to a string (not really a string). It is
	important to recognize that the methods print_tokens and free_tokens
	take a char** as a parameter which implies you must use the tokenize
	method. I forgot that about that and had multiple errors telling me
	"incompatible type given char* expected char**". It honestly was
	simple mistakes that made this lab brain frying.

	The second main file is history.c. history.c included five methods
	that constructed a linked list of words to keep track of. In my
	opinion, add_history was the hardest methods because I have not
	thought about Linked Lists in two years. I knew how they worked but
	not exactly how to code a linked list which was something I had to
	review before continuing on. 
