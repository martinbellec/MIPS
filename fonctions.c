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

void detecterType(char type[], char parametre1[], char parametre2[], char parametre3[]) {
  if(strcmp(type, "ADD") == 0)
    printf("ADD");

  else if(strcmp(type, "ADDI") == 0){
    printf("ADDI");
  }
  else if(strcmp(type, "AND") == 0){
    printf("AND");
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
  }
  else if(strcmp(type, "J") == 0){
    printf("J");
  }
  else if(strcmp(type, "JAL") == 0){
    printf("JAL");
  }
  else if(strcmp(type, "JR") == 0){
    printf("JR");
  }
  else if(strcmp(type, "LUI") == 0){
    printf("LUI");
  }
  else if(strcmp(type, "LW") == 0){
    printf("LW");
  }
  else if(strcmp(type, "MFHI") == 0){
    printf("MFHI");
  }
  else if(strcmp(type, "MFLO") == 0){
    printf("MFLO");
  }
  else if(strcmp(type, "MULT") == 0){
    printf("MULT");
  }
  else if(strcmp(type, "NOP") == 0){
    printf("NOP");
  }
  else if(strcmp(type, "OR") == 0){
    printf("OR");
  }
  else if(strcmp(type, "ROTR") == 0){
    printf("ROTR");
  }
  else if(strcmp(type, "SLL") == 0){
    printf("SLL");
  }
  else if(strcmp(type, "SLT") == 0){
    printf("SLT");
  }
  else if(strcmp(type, "SRL") == 0){
    printf("SRL");
  }
  else if(strcmp(type, "SUB") == 0){
    printf("SUB");
  }
  else if(strcmp(type, "SW") == 0){
    printf("SW");
  }
  else if(strcmp(type, "SYSCALL") == 0){
    printf("SYSCALL");
  }
  else if(strcmp(type, "XOR") == 0){
    printf("XOR");
  }
}
