#include "convert.h"
#include "register.h"
#include "guilhemfn.h"
#include "memory.h"
#include "read_instr.h"
#include "wait_instr.h"
#include "exec.h"


int main(int argc, char *argv[]) {
  FILE* fichier_assembleur;
  FILE* fichier_hexa;
  int retour = 1;
  pas = 0;

/*Traitement des arguments*/

/*Cas du mode non intéractif : Test de l'option -pas et traitement des erreurs d'appel du programme*/

  if((argc == 3) || (argc == 4)){
    if((argc == 4) && (strcmp(argv[3], "-pas")!=0)){
      printf("Mauvais appel du programme !\n");
      printf("Le programme doit être appelé sous la forme : ./prog fichier_entree.txt fichier_sortie.txt , suivi ou non de l'option -pas\n");
      retour = 0;
    }
    else if ((argc == 4) && (strcmp(argv[3], "-pas")==0)){
      pas = 1;
      printf("%d\n", pas);
    }
    if (retour){
      if(strcmp(argv[2], "-pas")!=0){
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
      else{
        printf("Mauvais appel du programme !\n");
        printf("Le programme doit être appelé sous la forme : ./prog fichier_entree.txt fichier_sortie.txt , suivi ou non de l'option -pas\n");
        retour = 0;
      }
    }
  }

/*Cas du mode intéractif : Test de l'option -pas et traitement des erreurs d'appel du programme*/

  else if((argc == 1) || (argc == 2)){
    if((argc == 2) && (strcmp(argv[1], "-pas")!=0)){
      printf("Mauvais appel du programme !\n");
      printf("Le programme doit être appelé sous la forme : ./prog fichier_entree.txt fichier_sortie.txt , suivi ou non de l'option -pas\n");
      retour = 0;
    }
    else if ((argc == 2) && (strcmp(argv[1], "-pas")==0)){
      pas = 1;
      printf("%d\n", pas);
    }
    if(retour){
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
  }
  else{
    printf("Mauvais appel du programme !\n");
    printf("Le programme doit être appelé sous la forme : ./prog fichier_entree.txt fichier_sortie.txt , suivi ou non de l'option -pas\n");
    retour = 0;
  }

/*Retour = 1 si il n'y a eu aucun problèmes auparavant*/

  if(retour){
    rewind(fichier_hexa);
    init_register();
    init_memory();
    exec(fichier_hexa);
    read_all_register();
    read_all_memory();
    fclose(fichier_assembleur);
    fclose(fichier_hexa);
  }

  return retour;
}
