#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


void lireCommande(char commande[], char type[], char parametre1[], char parametre2[], char parametre3[]);
void detecterType(char type[], char parametre1[], char parametre2[], char parametre3[]);
int ADD(char type[], char parametre1[], char parametre2[], char parametre3[]);
int ADDI(char type[], char parametre1[], char parametre2[], char parametre3[]);
int R_fonction(int type, char parametre1[], char parametre2[], char parametre3[]);
