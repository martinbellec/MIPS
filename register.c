#include "register.h"

void init_register(){
  int i = 0;
  for (i = 0;i<32;i++){
    registre[i] = 0;
  }
}

int read_register(int numero){
  return registre[numero];
}

void write_register(int numero, int valeur){
  registre[numero] = valeur;
}

void read_all_register(){
  int i = 0;
  for (i=0;i<32;i++){
    if(i<10){
      printf("R0%d = %d ", i, registre[i]);
    }
    else{
      printf("R%d = %d ", i, registre[i]);
    }
    if((i+1)%4==0){
      printf("\n");
    }
  }
  printf("PC = %d HI = %d LO = %d\n", pc, hi, lo);
}

void exec(FILE* fichier_hexa){
  unsigned int resultat = 0;
  char commande[60];
  while(fgets(commande, 60, fichier_hexa)!=NULL){
    sscanf(commande, "%08x\n", &resultat);
    printf("%d\n", resultat);
    if((resultat & 0x0000003f) == 32){
      reg_add(resultat);
    }
  }
}

void reg_add(int resultat){
  registre[(resultat & 0x0000f800) >> 11] = registre[(resultat & 0x03e00000) >> 21] + registre[(resultat & 0x001f0000) >> 16];
}
