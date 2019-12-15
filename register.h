#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define rs(resultat) mask(resultat, 21, 25)
#define opcode(resultat) mask(resultat, 26, 31)
#define rt(resultat) mask(resultat, 16, 20)
#define rd(resultat) mask(resultat, 11, 15)
#define sa(resultat) mask(resultat, 6, 10)
#define fonction(resultat) mask(resultat, 0, 5)
#define immediate(resultat) mask(resultat, 0, 15)
#define target(resultat) mask(resultat, 0, 25)



int registre[32];
int pc;
int hi;
int lo;

void init_register();
int read_register(int numero);
void write_register(int numero, int valeur);
void read_all_register();

void exec(FILE* fichier_hexa);


int mask(int resultat, int first_bit, int last_bit);



void reg_R(int resultat);
void reg_IJ(int resultat);



void reg_addi(int resultat);
void reg_add(int commande);
void reg_lui(int resultat);
void reg_sw(int resultat);
