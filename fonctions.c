#include "fonctions.h"



void lireCommande(char commande[], char type[], char parametre1[], char parametre2[], char parametre3[]) {
  int indice = 0, j = 0;
  while((commande[indice]!=' ') && (commande[indice]!='\0')) {
    type[j] = commande[indice];
    indice++;
    j++;
  }
  j = 0;
  indice++;
  while((commande[indice]!=',') && (commande[indice]!='\0')) {
    parametre1[j] = commande[indice];
    indice++;
    j++;
  }
  j = 0;
  indice++;
  while((commande[indice]!=',') && (commande[indice]!='\0')) {
    parametre2[j] = commande[indice];
    indice++;
    j++;
  }
  j = 0;
  indice++;
  while(commande[indice]!='\0') {
    parametre3[j] = commande[indice];
    indice++;
    j++;
  }
}

void detecterType(char* type[], char* parametre1[], char* parametre2[], char* parametre3[]) {

}
