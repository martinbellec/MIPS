#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int registre[32];
int pc;
int hi;
int lo;

void init_register();
int read_register(int numero);
void write_register(int numero, int valeur);
