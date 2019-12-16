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
    add(resultat);
  }
}


void reg_IJ(int resultat){
  if(opcode(resultat) == 15){
    lui(resultat);
  }
  else if(opcode(resultat) == 43){
    sw(resultat);
  }
  else if(opcode(resultat) == 8){
    addi(resultat);
  }
}

void addi(int resultat){
  registre[rt(resultat)] = registre[rs(resultat)] + immediate(resultat);
}

void sw(int resultat){
  memory[registre[rs(resultat)] + immediate(resultat)] = registre[rt(resultat)];
}

void lui(int resultat){
  registre[rt(resultat)] = immediate(resultat);
}

void add(int resultat){
  registre[rd(resultat)] = registre[rs(resultat)] + registre[rt(resultat)];
}

void and(int resultat){
  registre[rd(resultat)] = registre[rs(resultat)] & registre[rt(resultat)];
}

void beq(int resultat){
  if(registre[rs(resultat)] == registre[rt(resultat)]){
    pc += (immediate(resultat) << 2);
  }
}

void bgtz(int resultat){
  if(registre[rs(resultat)] > 0){
    pc += (immediate(resultat) << 2);
  }
}

void blez(int resultat){
  if(registre[rs(resultat)] <= 0){
    pc += (immediate(resultat) << 2);
  }
}

void bne(int resultat){
  if(registre[rs(resultat)] != registre[rt(resultat)]){
    pc += (immediate(resultat) << 2);
  }
}

void reg_div(int resultat){
  lo = (registre[rs(resultat)] / registre[rt(resultat)]);
  hi = (registre[rs(resultat)] % registre[rt(resultat)]);
}

void j(int resultat){
  pc = (target(resultat) << 2);
}

void jal(int resultat){
  registre[31] = pc+8;
  pc = (target(resultat) << 2);
}

void jr(int resultat){
  pc = registre[rs(resultat)];
}

void lw(int resultat){
  registre[rt(resultat)] = memory[registre[rs(resultat)] + immediate(resultat)];
}

void mfhi(int resultat){
  registre[rd(resultat)] = hi;
}

void mflo(int resultat){
  registre[rd(resultat)] = lo;
}

void mult(int resultat){
  long int produit = registre[rs(resultat)] * registre[rt(resultat)];
  lo = mask(produit, 0, 31);
  hi = mask(produit, 32, 63);
}

void nop(){
  sll(0);
}

void or(int resultat){
   registre[rd(resultat)] = registre[rs(resultat)] | registre[rt(resultat)];
 }

void rotr(int resultat){
  int rotation=0;
  rotation = mask(resultat, sa(resultat), 31);
  rotation = rotation | (mask(resultat, 0, sa(resultat)-1) << sa(resultat));
  registre[rd(resultat)] = rotation;
}

void sll(int resultat){
  registre[rd(resultat)] = registre[rt(resultat)] << sa(resultat);
}

void slt(int resultat){
  registre[rd(resultat)] = (registre[rs(resultat)] < registre[rt(resultat)]);
}

void srl(int resultat){
  registre[rd(resultat)] = registre[rt(resultat)] >> sa(resultat);
}

void sub(int resultat){
  registre[rd(resultat)] = registre[rs(resultat)] - registre[rt(resultat)];
}

void xor(int resultat){
   registre[rd(resultat)] = registre[rs(resultat)] ^ registre[rt(resultat)];
}
