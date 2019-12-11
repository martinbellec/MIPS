#include "fonctions.h"
#include "register.h"
#include "guilhemfn.h"
#include "memory.h"


int main(int argc, char *argv[]) {
  FILE* fichier_assembleur = fopen(argv[1], "r+");
  FILE* fichier_hexa = fopen(argv[2], "wb+");

  if(argc != 3){
    perror("Problème d'ouverture\n");
    return 0;
  }

  if(fichier_assembleur == NULL) {
    perror("Problème d'ouverture\n");
    return 0;
  }

  if(fichier_hexa == NULL) {
    perror("Problème d'ouverture\n");
    return 0;
  }

  conversion_hexa(fichier_assembleur, fichier_hexa);

  fclose(fichier_assembleur);
  fclose(fichier_hexa);
  return 0;
}
