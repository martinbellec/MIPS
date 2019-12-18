#include "register.h"
#include "memory.h"
#include "exec.h"

void exec(FILE* fichier_hexa){
  unsigned int resultat = 0;
  char commande[60];
  while(fgets(commande, 60, fichier_hexa)!=NULL){
    sscanf(commande, "%08x\n", &resultat);
    pc+=4;
    if(opcode(resultat) == 0){
      reg_R(resultat);
    }
    else{
      reg_IJ(resultat);
    }
    decal_pc(fichier_hexa);
  }
}

void decal_pc(FILE* fichier_hexa){
  int compteur = pc/4;
  char ligne[60];
  rewind(fichier_hexa);
  while( (compteur!=0) && ( fgets(ligne, 60, fichier_hexa) != NULL ) ) {
    compteur--;
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
  else if(fonction(resultat) == 36){
    and(resultat);
  }
  else if(fonction(resultat) == 37){
    or(resultat);
  }
  else if(fonction(resultat) == 38){
    xor(resultat);
  }
  else if((fonction(resultat) == 2) && (rs(resultat) == 1)) {
    rotr(resultat);
  }
  else if(fonction(resultat) == 2){
    srl(resultat);
  }
  else if(fonction(resultat) == 0){
    sll(resultat);
  }
  else if(fonction(resultat) == 42){
    slt(resultat);
  }
  else if(fonction(resultat) == 16){
    mfhi(resultat);
  }
  else if(fonction(resultat) == 18){
    mflo(resultat);
  }
  else if(fonction(resultat) == 8){
    jr(resultat);
  }
  else if(fonction(resultat) == 34){
    sub(resultat);
  }
  else if(fonction(resultat) == 24){
    mult(resultat);
  }
  else if(fonction(resultat) == 26){
    reg_div(resultat);
  }
}


void reg_IJ(int resultat){
  if(((opcode(resultat) != 2) || (opcode(resultat) != 3)) && (immediate(resultat)<0)) {
    resultat+=pow(2,16);
  }
  if(opcode(resultat) == 15){
    lui(resultat);
  }
  else if(opcode(resultat) == 43){
    sw(resultat);
  }
  else if(opcode(resultat) == 8){
    addi(resultat);
  }
  else if(opcode(resultat) == 35){
    lw(resultat);
  }
  else if(opcode(resultat) == 4){
    beq(resultat);
  }
  else if(opcode(resultat) == 5){
    bne(resultat);
  }
  else if(opcode(resultat) == 7){
    bgtz(resultat);
  }
  else if(opcode(resultat) == 6){
    blez(resultat);
  }
  else if(opcode(resultat) == 2){
    j(resultat);
  }
  else if(opcode(resultat) == 3){
    jal(resultat);
  }
}

void addi(int resultat){
  registre[rt(resultat)] = registre[rs(resultat)] + immediate(resultat);
}

void sw(int resultat){
  memory[registre[rs(resultat)] + immediate(resultat)] = registre[rt(resultat)];
}

void lui(int resultat){
  registre[rt(resultat)] += immediate(resultat) << 16;
}

void add(int resultat){
  registre[rd(resultat)] = registre[rs(resultat)] + registre[rt(resultat)];
}

void and(int resultat){
  registre[rd(resultat)] = registre[rs(resultat)] & registre[rt(resultat)];
}

void beq(int resultat){
  if(registre[rs(resultat)] == registre[rt(resultat)]){
    pc -= 4;
    pc += (immediate(resultat) << 2);
  }
}

void bgtz(int resultat){
  if(registre[rs(resultat)] > 0){
    pc -= 4;
    pc += (immediate(resultat) << 2);
  }
}

void blez(int resultat){
  if(registre[rs(resultat)] <= 0){
    pc -= 4;
    pc += (immediate(resultat) << 2);
  }
}

void bne(int resultat){
  if(registre[rs(resultat)] != registre[rt(resultat)]) {
    pc -= 4;
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
  registre[31] = pc+4;
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

void or(int resultat){
   registre[rd(resultat)] = registre[rs(resultat)] | registre[rt(resultat)];
 }

void rotr(int resultat){
  int rotation=0;
  rotation = registre[rt(resultat)];
  rotation = (rotation >> sa(resultat)) | (rotation << (32-sa(resultat)));
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
