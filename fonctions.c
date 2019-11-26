#include "fonctions.h"
#include "register.h"
#include "guilhemfn.h"

void conversion_hexa(FILE* fichier_assembleur, FILE* fichier_hexa) {
  char commande[30];
  int i = 0;
  int resultat;
  char type[30] = "\0";
  char parametre1[30] = "\0";
  char parametre2[30] = "\0";
  char parametre3[30] = "\0";
  char vide[30] = "\0";

  while(fgets(commande, 30, fichier_assembleur)!=NULL) {
    lireCommande(commande, type, parametre1, parametre2, parametre3);
    resultat = detecterType(type, parametre1, parametre2, parametre3, vide);
    for (i=0;i<30;i++) {
      type[i] = '\0';
      parametre1[i] = '\0';
      parametre2[i] = '\0';
      parametre3[i] = '\0';
    }
    fprintf(fichier_hexa, "%08x\n", resultat);
  }
}

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

int detecterType(char type[], char parametre1[], char parametre2[], char parametre3[], char vide[]) {
  int resultat;
  int i=0,j=0;
  char zero[5] = "000";
  if(strcmp(type, "ADD") == 0) {
    resultat = R_fonction(type, 32, parametre2, parametre3, parametre1, vide);
  }
  else if(strcmp(type, "ADDI") == 0){
    resultat = I_fonction(8, parametre1, parametre2, parametre3);
  }
  else if(strcmp(type, "AND") == 0){
    resultat = R_fonction(type, 36, parametre2, parametre3, parametre1, vide);
  }
  else if(strcmp(type, "BEQ") == 0){
  }
  else if(strcmp(type, "BGTZ") == 0){
  }
  else if(strcmp(type, "BLEZ") == 0){
  }
  else if(strcmp(type, "BNE") == 0){
  }
  else if(strcmp(type, "DIV") == 0){
    resultat = R_fonction(type, 26, parametre1, parametre2, parametre3, vide);
  }
  else if(strcmp(type, "J") == 0){
    J_fonction(2, parametre1);
  }
  else if(strcmp(type, "JAL") == 0){
    J_fonction(3, parametre1);
  }
  else if(strcmp(type, "JR") == 0){
    resultat = R_fonction(type, 8, parametre1, parametre2, parametre3, vide);
  }
  else if(strcmp(type, "LUI") == 0){
    resultat = I_fonction(15, parametre1, zero, parametre2); /*fonctionne*/
  }
  else if(strcmp(type, "LW") == 0){
    /*printf ("parametre2 au debut vaut : %s\n", parametre2);*/
    /*configuration de parametre3 pour qu'il corresponde à l'offset*/
    i=0;
    while (parametre2[i]!='('){
      parametre3[i]=parametre2[i];
      i++;
    }
    parametre3[i]='\0';
    /*printf ("mon offset : %s\n", parametre3);*/
    /*configuration de parametre2 poour qu'il corresponde au registre de depart*/
    j=0;
    i=i+1;
    while (parametre2[i]!=')'){
      parametre2[j]=parametre2[i];
      i++;
      j++;
    }
    parametre2[j]='\0';
    /*printf ("parametre2 à la fin vaut : %s\n", parametre2);*/
    resultat = I_fonction(35, parametre1, parametre2, parametre3);
  }
  else if(strcmp(type, "MFHI") == 0){
    resultat = R_fonction(type, 16, parametre2, parametre3, parametre1, vide);
  }
  else if(strcmp(type, "MFLO") == 0){
    resultat = R_fonction(type, 18, parametre2, parametre3, parametre1, vide);
  }
  else if(strcmp(type, "MULT") == 0){
    resultat = R_fonction(type, 24, parametre1, parametre2, parametre3, vide);
  }
  else if(strcmp(type, "NOP") == 0){
    resultat = R_fonction(type, 0, parametre1, parametre2, parametre3, vide);
  }
  else if(strcmp(type, "OR") == 0){
    resultat = R_fonction(type, 37, parametre2, parametre3, parametre1, vide);
  }
  else if(strcmp(type, "ROTR") == 0){
    resultat = R_fonction(type, 2, vide, parametre2, parametre1, parametre3);
  }
  else if(strcmp(type, "SLL") == 0){
    resultat = R_fonction(type, 0, vide, parametre2, parametre1, parametre3);
  }
  else if(strcmp(type, "SLT") == 0){
    resultat = R_fonction(type, 42, parametre2, parametre3, parametre1, vide);
  }
  else if(strcmp(type, "SRL") == 0){
    resultat = R_fonction(type, 2, vide, parametre2, parametre1, parametre3);
  }
  else if(strcmp(type, "SUB") == 0){
    resultat = R_fonction(type, 34, parametre2, parametre3, parametre1, vide);
  }
  else if(strcmp(type, "SW") == 0){
  }
  else if(strcmp(type, "SYSCALL") == 0){
    resultat = R_fonction(type, 12, parametre1, parametre2, parametre3, vide);
  }
  else if(strcmp(type, "XOR") == 0){
    resultat = R_fonction(type, 38, parametre2, parametre3, parametre1, vide);
  }
  return resultat;
}

int ADDI(char type[], char parametre1[], char parametre2[], char parametre3[]) {
  int resultat = 8 << 26;
  resultat += atoi(&parametre3[0]);
  resultat += atoi(&parametre1[1]) << 16;
  resultat += atoi(&parametre2[1]) << 21;
  printf("%08x\n", resultat);
  return resultat;
}

int R_fonction(char type[], int type_nombre, char rs[], char rt[], char rd[], char sa[]) {
  int resultat = type_nombre;
  if (strcmp(type, "ROTR") == 0){
    rs[1] = '1';
  }
  resultat += 0 >> 6;
  resultat += atoi(&sa[1]) << 6;
  resultat += atoi(&rd[1]) << 11;
  resultat += atoi(&rt[1]) << 16;
  resultat += atoi(&rs[1]) << 21;
  printf("%08x\n", resultat);
  return resultat;
}

int J_fonction(int type, char target[]) {
  int resultat = type << 26;
  resultat += (atoi(&target[0]) & 67108863);
  printf("%08x\n", resultat);
  return resultat;
}
