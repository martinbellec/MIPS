#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int memory[128];


/*Prototypes des fonctions*/

/*Fonction qui initialise la mémoire du processeur*/
void init_memory();

/*Fonction qui permet d'écrire dans une case mémoire particulière une valeur demandée*/
void write_memory(int numero, int valeur);

/*Fonction qui renvoie la valeur d'une case mémoire demandée*/
int read_memory(int numero);

/*Fonction qui affiche le contenu de toute la mémoire*/
void read_all_memory();
