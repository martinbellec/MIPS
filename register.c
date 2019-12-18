#include "register.h"
#include "memory.h"
#include "exec.h"


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
