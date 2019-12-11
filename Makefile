prog : main.o fonctions.o register.o guilhemfn.o memory.o
	gcc -o $@ $^ -lm

main.o : main.c fonctions.h guilhemfn.h register.h memory.h
	gcc -Wall -ansi -pedantic -g -c $<

fonctions.o : fonctions.c fonctions.h guilhemfn.h register.h memory.h
	gcc -Wall -ansi -pedantic -g -c $<

register.o : register.c register.h
	gcc -Wall -ansi -pedantic -g -c $<

guilhemfn.o : guilhemfn.c guilhemfn.h register.h memory.h
	gcc -Wall -ansi -pedantic -g -c $<

memory.o : memory.c memory.h
	gcc -Wall -ansi -pedantic -g -c $<

clean :
	rm -rf *.o prog
