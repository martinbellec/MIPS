#include "convert.h"
#include "read_instr.h"



void conversion_hexa(FILE* fichier_assembleur, FILE* fichier_hexa) {
  char commande[60];
  int i = 0;
  int resultat;
  char type[30] = "\0";
  char parametre1[30] = "\0";
  char parametre2[30] = "\0";
  char parametre3[30] = "\0";
  char vide[30] = "\0";
  char commentaire[30] = "\0";
  printf("\n =======Tableau des instructions=======\n");
  while(fgets(commande, 60, fichier_assembleur)!=NULL) {
    lireCommande(commande, type, parametre1, parametre2, parametre3, commentaire);
    if (commentaire[0] == '#'){
      for (i = 0;i<30;i++){
        printf("%c", commentaire[i]);
      }
    }
    if(type[0] != '\0' && type[0] != '\n'){
      resultat = detecterType(type, parametre1, parametre2, parametre3, vide);
      if ((resultat != 0)||(strcmp(type,"NOP")==0)) {
        fprintf(fichier_hexa, "%08x\n", resultat);
        printf("%08x = %s", resultat, commande);
      }
    }
    for (i=0;i<30;i++) {
      type[i] = '\0';
      parametre1[i] = '\0';
      parametre2[i] = '\0';
      parametre3[i] = '\0';
      commentaire[i] = '\0';
      vide[i] = '\0';
    }
  }
}

void lireCommande(char commande[], char type[], char parametre1[], char parametre2[], char parametre3[], char commentaire[]) {
  int indice = 0, j = 0;
  while((commande[indice] == ' ') && (commande[indice] != '#')){
    indice++;
  }
  if (commande[indice] == '#'){
    while(commande[indice]!='\0'){
      commentaire[j] = commande[indice];
      indice++;
      j++;
    }
  }
  j = 0;

  while((commande[indice]!=' ') && (commande[indice]!='\0') && (commande[indice] != '#') && (commande[indice] != '\n') && (commande[indice] != '\r')) {
    type[j] = commande[indice];
    indice++;
    j++;
  }
  j = 0;
  if (commande[indice] == '#'){
    while(commande[indice]!='\0'){
      commentaire[j] = commande[indice];
      indice++;
      j++;
    }
  }
  j = 0;
  indice++;
  while((commande[indice]!=',') && (commande[indice]!='\0') && (commande[indice] != '#')) {
    parametre1[j] = commande[indice];
    indice++;
    j++;
  }
  j = 0;
  if (commande[indice] == '#'){
    while(commande[indice]!='\0'){
      commentaire[j] = commande[indice];
      indice++;
      j++;
    }
  }
  j = 0;
  indice++;
  while((commande[indice]!=',') && (commande[indice]!='\0') && (commande[indice] != '#')) {
    parametre2[j] = commande[indice];
    indice++;
    j++;
  }
  j = 0;
  if (commande[indice] == '#'){
    while(commande[indice]!='\0'){
      commentaire[j] = commande[indice];
      indice++;
      j++;
    }
  }
  j = 0;
  indice++;
  while(commande[indice]!='\0' && (commande[indice] != '#')) {
    parametre3[j] = commande[indice];
    indice++;
    j++;
  }
  j = 0;
  if (commande[indice] == '#'){
    while(commande[indice]!='\0'){
      commentaire[j] = commande[indice];
      indice++;
      j++;
    }
  }
}

void afficher_A_H(FILE * fichier_assembleur, FILE * fichier_hexa){
  char hexa[60];
  char assembleur[60];
  rewind(fichier_hexa);
  rewind(fichier_assembleur);
  printf("\n =======Tableau des instructions=======\n");
  while(fgets(hexa, 60, fichier_hexa)!=NULL){
    fgets(assembleur, 60, fichier_assembleur);
    if ((assembleur[0]=='\r')||(assembleur[0]=='\n')||(assembleur[0]=='#')){
      fgets(assembleur, 60, fichier_assembleur);
    }
    hexa[8]=' ';
    printf("%s= %s", hexa, assembleur);
  }
  printf("\n");
}
