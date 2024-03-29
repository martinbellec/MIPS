prog : main.o convert.o register.o guilhemfn.o memory.o read_instr.o wait_instr.o exec.o
	gcc -o $@ $^ -lm

main.o : main.c convert.h guilhemfn.h register.h memory.h read_instr.h wait_instr.h exec.h
	gcc -Wall -ansi -pedantic -g -c $<

convert.o : convert.c convert.h read_instr.h
	gcc -Wall -ansi -pedantic -g -c $<

register.o : register.c register.h memory.h exec.h
	gcc -Wall -ansi -pedantic -g -c $<

guilhemfn.o : guilhemfn.c guilhemfn.h register.h memory.h
	gcc -Wall -ansi -pedantic -g -c $<

memory.o : memory.c memory.h
	gcc -Wall -ansi -pedantic -g -c $<

read_instr.o : read_instr.c read_instr.h convert.h
	gcc -Wall -ansi -pedantic -g -c $<

wait_instr.o : wait_instr.c wait_instr.h read_instr.h
	gcc -Wall -ansi -pedantic -g -c $<

exec.o : exec.c register.h memory.h exec.h
	gcc -Wall -ansi -pedantic -g -c $<


clean :
	rm -rf *.o prog
