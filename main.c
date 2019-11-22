#include "fonctions.h"
#include "register.h"

int main(int argc, char *argv[]) {
  char commande[30];
  int i = 0;
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

  while(fgets(commande, 30, fichier)!=NULL) {
    lireCommande(commande, type, parametre1, parametre2, parametre3);
    detecterType(type, parametre1, parametre2, parametre3);
    for (i=0;i<30;i++) {
      type[i] = '\0';
      parametre1[i] = '\0';
      parametre2[i] = '\0';
      parametre3[i] = '\0';
    }
  }

  fclose(fichier);
  return 0;
}
