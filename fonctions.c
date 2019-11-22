#include "fonctions.h"
#include "register.h"



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

void detecterType(char type[], char parametre1[], char parametre2[], char parametre3[]) {
  if(strcmp(type, "ADD") == 0) {
    printf("ADD\n");
    R_fonction(32, parametre1, parametre2, parametre3);
  }
  else if(strcmp(type, "ADDI") == 0){
    printf("ADDI\n");
    I_fonction(8, parametre1, parametre2, parametre3);
  }
  else if(strcmp(type, "AND") == 0){
    printf("AND");
    R_fonction(36, parametre1, parametre2, parametre3);
  }
  else if(strcmp(type, "BEQ") == 0){
    printf("BEQ");
  }
  else if(strcmp(type, "BGTZ") == 0){
    printf("BGTZ");
  }
  else if(strcmp(type, "BLEZ") == 0){
    printf("BLEZ");
  }
  else if(strcmp(type, "BNE") == 0){
    printf("BNE");
  }
  else if(strcmp(type, "DIV") == 0){
    printf("DIV");
    R_fonction(26, parametre3, parametre1, parametre2);
  }
  else if(strcmp(type, "J") == 0){
    printf("J");

  }
  else if(strcmp(type, "JAL") == 0){
    printf("JAL");
  }
  else if(strcmp(type, "JR") == 0){
    printf("JR");
    R_fonction(8, parametre3, parametre1, parametre2);
  }
  else if(strcmp(type, "LUI") == 0){
    printf("LUI");
  }
  else if(strcmp(type, "LW") == 0){
    printf("LW");
  }
  else if(strcmp(type, "MFHI") == 0){
    printf("MFHI");
    R_fonction(16, parametre1, parametre2, parametre3);
  }
  else if(strcmp(type, "MFLO") == 0){
    printf("MFLO");
    R_fonction(18, parametre1, parametre2, parametre3);
  }
  else if(strcmp(type, "MULT") == 0){
    printf("MULT");
    R_fonction(24, parametre3, parametre1, parametre2);
  }
  else if(strcmp(type, "NOP") == 0){
    printf("NOP");
    R_fonction(0, parametre1, parametre2, parametre3);
  }
  else if(strcmp(type, "OR") == 0){
    printf("OR");
    R_fonction(37, parametre1, parametre2, parametre3);
  }
  else if(strcmp(type, "ROTR") == 0){
    printf("ROTR");
  }
  else if(strcmp(type, "SLL") == 0){
    printf("SLL");
  }
  else if(strcmp(type, "SLT") == 0){
    printf("SLT");
    R_fonction(42, parametre1, parametre2, parametre3);
  }
  else if(strcmp(type, "SRL") == 0){
    printf("SRL");
  }
  else if(strcmp(type, "SUB") == 0){
    printf("SUB");
    R_fonction(34, parametre1, parametre2, parametre3);
  }
  else if(strcmp(type, "SW") == 0){
    printf("SW");
  }
  else if(strcmp(type, "SYSCALL") == 0){
    printf("SYSCALL");
    R_fonction(12, parametre1, parametre2, parametre3);
  }
  else if(strcmp(type, "XOR") == 0){
    printf("XOR");
    R_fonction(38, parametre1, parametre2, parametre3);
  }
}


int ADD(char type[], char parametre1[], char parametre2[], char parametre3[]) {
  int resultat = 32;
  resultat += 0 >> 6;
  resultat += atoi(&parametre1[1]) << 11;
  resultat += atoi(&parametre3[1]) << 16;
  resultat += atoi(&parametre2[1]) << 21;
  printf("%08x\n", resultat);
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

int R_fonction(int type, char rd[], char rs[], char rt[]) {
  int resultat = type;
  resultat += 0 >> 6;
  resultat += atoi(&rd[1]) << 11;
  resultat += atoi(&rt[1]) << 16;
  resultat += atoi(&rs[1]) << 21;
  printf("%08x\n", resultat);
  return resultat;
}
