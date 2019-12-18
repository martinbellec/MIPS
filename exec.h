#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Macros pour la fonction mask qui permet de simplifier la lecture des fonctions et leur débuggage*/

#define rs(resultat) mask(resultat, 21, 25)
#define opcode(resultat) mask(resultat, 26, 31)
#define rt(resultat) mask(resultat, 16, 20)
#define rd(resultat) mask(resultat, 11, 15)
#define sa(resultat) mask(resultat, 6, 10)
#define fonction(resultat) mask(resultat, 0, 5)
#define immediate(resultat) (short)mask(resultat, 0, 15)
#define target(resultat) mask(resultat, 0, 25)

/*Prototypes des fonctions*/

/*Fonction générale de l'exécution*/
void exec(FILE* fichier_hexa);

/*Fonction qui gère se déplace dans les adresses d'instruction (ici le fichier_hexa) en fonction du Prgram Counter*/
void decal_pc(FILE* fichier_hexa);

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
void or(int resultat);
void rotr(int resultat);
void sll(int resultat);
void slt(int resultat);
void srl(int resultat);
void sub(int resultat);
void xor(int resultat);
