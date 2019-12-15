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

void read_all_memory(){
  int i = 0;
  printf("============ Mémoire ===========\n");
  for (i=0;i<128;i++){
    if(memory[i]<10){
      printf("0%d ", memory[i]);
    }
    else{
      printf("%d ", memory[i]);
    }
    if((i+1)%8 == 0) {printf("\n");}
  }
}
