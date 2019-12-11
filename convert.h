#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void conversion_hexa(FILE* fichier_assembleur, FILE* fichier_hexa);
void lireCommande(char commande[], char type[], char parametre1[], char parametre2[], char parametre3[], char commentaire[]);
int detecterType(char type[], char parametre1[], char parametre2[], char parametre3[], char vide[]);
int ADD(char type[], char parametre1[], char parametre2[], char parametre3[]);
int ADDI(char type[], char parametre1[], char parametre2[], char parametre3[]);
int R_fonction(char type[], int type_nombre, char rs[], char rt[], char rd[], char sa[]);
int J_fonction(int type, char target[]);
int I_fonction(int type, char parametre1[], char parametre2[], char parametre3[]);
