#include "register.h"
#include "guilhemfn.h"
#include "memory.h"


int I_fonction(int type, char parametre1[], char parametre2[], char parametre3[]){
  int resultat = type << 26;
  resultat += atoi(&parametre3[0]);
  resultat += atoi(&parametre1[1]) << 16;
  resultat += atoi(&parametre2[1]) << 21;
  /*printf("%08x\n", resultat);*/
  return resultat;
}
