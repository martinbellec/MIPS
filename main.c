#include "convert.h"
#include "register.h"
#include "guilhemfn.h"
#include "memory.h"
#include "read_instr.h"
#include "wait_instr.h"

int main(int argc, char *argv[]) {
  FILE* fichier_assembleur;
  FILE* fichier_hexa;
  int retour = 1;

  if(argc == 3){
    fichier_assembleur = fopen(argv[1], "r+");
    fichier_hexa = fopen(argv[2], "w+");
    if((fichier_assembleur != NULL) && (fichier_hexa != NULL)) {
      conversion_hexa(fichier_assembleur, fichier_hexa);
    }
    else{
      perror("Problème d'ouverture\n");
      retour = 0;
    }
  }
  else if(argc == 1){
    fichier_assembleur = fopen("assembleur.txt", "w+");
    fichier_hexa = fopen("hexadecimal.txt", "w+");
    if((fichier_assembleur != NULL) && (fichier_hexa != NULL)) {
      mode_interactif(fichier_assembleur, fichier_hexa);
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
  rewind(fichier_hexa);
  init_register();
  init_memory();
  write_register(3,4);
  read_all_register();
  exec(fichier_hexa);
  read_all_register();
  read_all_memory();

  fclose(fichier_assembleur);
  fclose(fichier_hexa);

  return retour;
}
