#include "register.h"
#include "memory.h"

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
  printf("=========== Registres =========\n");
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
  printf("PC = %08x HI = %d LO = %d\n", pc, hi, lo);
}

void exec(FILE* fichier_hexa){
  unsigned int resultat = 0;
  char commande[60];
  while(fgets(commande, 60, fichier_hexa)!=NULL){
    sscanf(commande, "%08x\n", &resultat);
    if(opcode(resultat) == 0){
      reg_R(resultat);
    }
    else{
      reg_IJ(resultat);
    }
    pc+=4;
  }
}

int mask(int resultat, int first_bit, int last_bit){
  long int mask = 0, i = 0;
  for (i=0;i<(last_bit-first_bit+1);i++){
    mask += pow(2, first_bit+i);
  }
  return ((resultat & mask) >> first_bit);
}


void reg_R(int resultat){
  if(fonction(resultat) == 32){
    reg_add(resultat);
  }
}


void reg_IJ(int resultat){
  if(opcode(resultat) == 15){
    reg_lui(resultat);
  }
  else if(opcode(resultat) == 43){
    reg_sw(resultat);
  }
  else if(opcode(resultat) == 8){
    reg_addi(resultat);
  }

}

void reg_addi(int resultat){
  registre[rt(resultat)] = registre[rs(resultat)] + immediate(resultat);
}


void reg_sw(int resultat){
  memory[registre[rs(resultat)] + immediate(resultat)] = registre[rt(resultat)];
}

void reg_lui(int resultat){
  registre[rt(resultat)] = immediate(resultat);
}

void reg_add(int resultat){
  registre[rd(resultat)] = registre[rs(resultat)] + registre[rt(resultat)];
}
