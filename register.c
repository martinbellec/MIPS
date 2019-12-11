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
