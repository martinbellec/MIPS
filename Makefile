prog : main.o fonctions.o register.o
	gcc -o $@ $^ -lm

main.o : main.c fonctions.h
	gcc -Wall -ansi -pedantic -g -c $<

fonctions.o : fonctions.c fonctions.h
	gcc -Wall -ansi -pedantic -g -c $<

register.o : register.c register.h
	gcc -Wall -ansi -pedantic -g -c $<

clean :
	rm -rf *.o prog
