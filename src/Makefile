#compiler flags. -g for debug, -O3 for optimization
CFLAGS=-g

#first target is built by default
all: tokenizer

#include file dependancies
history.o: history.h tokenizer.h
tokenizer.o: tokenizer.h history.h
token.o: tokenizer.h history.h

#$@ =target, $^= prerequisites
#tokenizer: tokenizer.o history.o
tokenizer: tokenizer.o history.o token.o 
	cc -o $@ $^ $(CFLAGS)

#deletes files generated by compilation
clean:
	rm -f *.o src
run:
	./tokenizer
