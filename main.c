#include "convert.h"
#include "register.h"
#include "guilhemfn.h"
#include "memory.h"
#include "read_instr.h"

int main(int argc, char *argv[]) {
  FILE* fichier_assembleur;
  FILE* fichier_hexa;
  int retour = 1;

  if(argc == 3){
    fichier_assembleur = fopen(argv[1], "r+");
    fichier_hexa = fopen(argv[2], "wb+");
    if((fichier_assembleur != NULL) && (fichier_hexa != NULL)) {
      conversion_hexa(fichier_assembleur, fichier_hexa);
    }
    else{
      perror("Problème d'ouverture\n");
      retour = 0;
    }
  }
  else if(argc == 1){
    fichier_assembleur = fopen("assembleur.txt", "r+");
    fichier_hexa = fopen("hexadecimal.txt", "wb+");
    if((fichier_assembleur != NULL) && (fichier_hexa != NULL)) {
      /*mode_interactif*/
    }
    else{
      perror("Problème d'ouverture\n");
      retour = 0;
    }
  }
  else{
    perror("Problème d'ouverture\n");
    retour = 0;
  }
  
  fclose(fichier_assembleur);
  fclose(fichier_hexa);

  return retour;
}
