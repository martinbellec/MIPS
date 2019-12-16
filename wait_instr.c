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
  viderBuffer();
  printf("Quelle est votre commande assembleur? \n");
  fgets(mon_assembleur, 60, stdin);
  fprintf(fichier_assembleur, "%s", mon_assembleur);
  conversion_hexa(fichier_assembleur, fichier_hexa);

}
