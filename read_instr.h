#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


/*Prototypes des fonctions*/

/*Fonction qui converti en hexadecimal les intructions fournies et écrit dans le fichier*/
void conversion_hexa(FILE* fichier_assembleur, FILE* fichier_hexa);

/*Fonction qui détecte les différentes parties de l'instruction et les stocke*/
void lireCommande(char commande[], char type[], char parametre1[], char parametre2[], char parametre3[], char commentaire[]);

/*Fonction qui affiche les instructions et leurs valeurs hexadecimales correspondantes*/
void afficher_A_H(FILE * fichier_assembleur, FILE * fichier_hexa);
