#include "memory.h"

void init_memory(){
  int i = 0;
  for(i=0;i<128;i++){
    memory[i] = 0;
  }
}

int read_memory(int numero){
  return memory[numero];
}

void write_memory(int numero, int valeur){
  memory[numero] = valeur;
}
