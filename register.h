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


/*Fonction générale de l'exécution*/
void exec(FILE* fichier_hexa);

/*Fonction qui sélectionne les bits voulus dans un entier de 32bits en appliquant un masque & puis en décalant les bits*/
int mask(int resultat, int first_bit, int last_bit);

/*Répartition des commandes*/

void reg_R(int resultat);
void reg_IJ(int resultat);

/*Fonctions commandes*/

void addi(int resultat);
void add(int resultat);
void lui(int resultat);
void sw(int resultat);
void and(int resultat);
void beq(int resultat);
void bgtz(int resultat);
void blez(int resultat);
void bne(int resultat);
void reg_div(int resultat);
void j(int resultat);
void jal(int resultat);
void jr(int resultat);
void lw(int resultat);
void mfhi(int resultat);
void mflo(int resultat);
void mult(int resultat);
void nop();
void or(int resultat);
void rotr(int resultat);
void sll(int resultat);
void slt(int resultat);
