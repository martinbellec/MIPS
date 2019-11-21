#include "fonctions.h"
#include "register.h"

int main(int argc, char *argv[]) {
  char commande[30];
  char type[30] = "\0";
  char parametre1[30] = "\0";
  char parametre2[30] = "\0";
  char parametre3[30] = "\0";
  FILE* fichier;
  fichier = fopen("test.txt", "r+");
  if(fichier == NULL) {
    perror("Problème d'ouverture\n");
    return 0;
  }

  rewind(fichier);
  if(fgets(commande, 30, fichier)==NULL){
      printf("Erreur");
  }
  lireCommande(commande, type, parametre1, parametre2, parametre3);




  fclose(fichier);
  return 0;
}
