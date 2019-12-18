#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Variables globales des registres*/

int registre[32];
int pc;
int hi;
int lo;

/*Variable globale correspondant au mode pas à pas*/

int pas;

/*Prototypes des fonctions*/

/*Fonction qui intialise les registres*/
void init_register();

/*Fonction qui lit le registre correspondant au numéro appelé*/
int read_register(int numero);

/*Fonction qui écrit dans le registre correspondant au numéro appelé*/
void write_register(int numero, int valeur);

/*Fonction qui affiche tous les registres*/
void read_all_register();
