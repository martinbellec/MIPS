#include "convert.h"
#include "read_instr.h"

int detecterType(char type[], char parametre1[], char parametre2[], char parametre3[], char vide[]) {
  int resultat = 0;
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
  else if(strcmp(type, "BEQ") == 0){ /*fonctionne*/
    resultat = I_fonction(4, parametre2, parametre1, parametre3);
  }
  else if(strcmp(type, "BGTZ") == 0){ /*fonctionne*/
    resultat = I_fonction(7, zero, parametre1, parametre2);
  }
  else if(strcmp(type, "BLEZ") == 0){
    resultat = I_fonction(6, zero, parametre1, parametre2);
  }
  else if(strcmp(type, "BNE") == 0){ /*fonctionne*/
    resultat = I_fonction(5, parametre2, parametre1, parametre3);
  }
  else if(strcmp(type, "DIV") == 0){ /*fonctionne*/
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
  else if(strcmp(type, "LUI") == 0){ /*fonctionne*/
    resultat = I_fonction(15, parametre1, zero, parametre2);
  }
  else if(strcmp(type, "LW") == 0){ /*fonctionne*/
    /*configuration de parametre3 pour qu'il corresponde à l'offset*/
    i=0;
    while (parametre2[i]!='('){
      parametre3[i]=parametre2[i];
      i++;
    }
    parametre3[i]='\0';
    /*configuration de parametre2 poour qu'il corresponde au registre de depart*/
    j=0;
    i=i+1;
    while (parametre2[i]!=')'){
      parametre2[j]=parametre2[i];
      i++;
      j++;
    }
    parametre2[j]='\0';
    /*transformation en hexa*/
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
    resultat = R_fonction(type, 0, vide, vide, vide, vide);
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
    /*configuration de parametre3 pour qu'il corresponde à l'offset*/
    i=0;
    while (parametre2[i]!='('){
      parametre3[i]=parametre2[i];
      i++;
    }
    parametre3[i]='\0';
    /*configuration de parametre2 poour qu'il corresponde au registre de depart*/
    j=0;
    i=i+1;
    while (parametre2[i]!=')'){
      parametre2[j]=parametre2[i];
      i++;
      j++;
    }
    parametre2[j]='\0';
    /*transformation en hexa */
    resultat = I_fonction(43, parametre1, parametre2, parametre3);
  }
  else if(strcmp(type, "SYSCALL") == 0){
    resultat = R_fonction(type, 12, parametre1, parametre2, parametre3, vide);
  }
  else if(strcmp(type, "XOR") == 0){
    resultat = R_fonction(type, 38, parametre2, parametre3, parametre1, vide);
  }
  return resultat;
}

int R_fonction(char type[], int type_nombre, char rs[], char rt[], char rd[], char sa[]) {
  int resultat = type_nombre;
  if (strcmp(type, "ROTR") == 0){
    rs[1] = '1';
  }
  resultat += 0 >> 6;
  resultat += atoi(&sa[0]) << 6;
  resultat += atoi(&rd[1]) << 11;
  resultat += atoi(&rt[1]) << 16;
  resultat += atoi(&rs[1]) << 21;
  return resultat;
}

int J_fonction(int type, char target[]) {
  int resultat = type << 26;
  resultat += (atoi(&target[0]) & 67108863);
  return resultat;
}

int I_fonction(int type, char parametre1[], char parametre2[], char parametre3[]){
  int resultat = type << 26;
  resultat += atoi(&parametre3[0]);
  resultat += atoi(&parametre1[1]) << 16;
  resultat += atoi(&parametre2[1]) << 21;
  return resultat;
}
