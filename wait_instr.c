#include "read_instr.h"
#include "wait_instr.h"


void viderBuffer(){
    int c = 0;
    while (c != '\n' && c != EOF){
        c = getchar();
    }
}

void mode_interactif(FILE * fichier_assembleur, FILE * fichier_hexa){
  char mon_assembleur[60] = "\0";
  do {
    printf("Quelle est votre commande assembleur? \n");
    fgets(mon_assembleur, 60, stdin);
    if (strcmp(mon_assembleur, "EXIT\n")) {
      fprintf(fichier_assembleur, "%s", mon_assembleur);
    }
  } while (strcmp(mon_assembleur, "EXIT\n"));
  rewind(fichier_assembleur);
  conversion_hexa(fichier_assembleur, fichier_hexa);
}
