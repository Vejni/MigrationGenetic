#include <limits.h>

unsigned long int randGene(int size){
  unsigned long int rand;
  do {
    rand = ULNGran(size);
  } while(rand == pow(2, size)); // to exclude the last value of the range
  return rand;
}

void OnePointCrossover(unsigned char len, unsigned long int p1, unsigned long int p2, unsigned long int *f1, unsigned long int *f2){
  /* d \in [1, 8*sizeof(unsigned long int)-1] */
  unsigned char d = uniform() * (8 * sizeof(len) - 1) + 1;
  /* d 0's at the beginning and (8*sizeof(unsigned long int) - d) 1's at the end */
  unsigned long int mask = 0xFFFFFFFFFFFFFFFFU << d;

  *f1 = (p1 & mask) | (p2 & ~mask);
  *f2 = (p2 & mask) | (p1 & ~mask);
}

void TwoPointCrossover(unsigned char len, unsigned long int p1, unsigned long int p2, unsigned long int *f1, unsigned long int *f2){
  unsigned char p = uniform() * (len - 2) + 1; /* p \in [1, len-2] */
  unsigned char q = uniform() * (len - 1 - p) + 1; /* q \in [1, len-1-p] */
  unsigned long int mask = ((1 << q) - 1) << p;
  *f1 = (p1 & mask) | (p2 & ~mask);
  *f2 = (p2 & mask) | (p1 & ~mask);
}

void UniformCrossover(unsigned char len, unsigned long int p1, unsigned long int p2, unsigned long int *f1, unsigned long int *f2, double prob){
  unsigned long int mask = 1;
  register unsigned char i;
  for(i=0; i < len; i++) if(uniform() < prob) mask = mask | (mask << i);
  *f1 = (p1 & mask) | (p2 & ~mask);
  *f2 = (p2 & mask) | (p1 & ~mask);
}

void Crossover(int i, unsigned char len, unsigned long int p1, unsigned long int p2, unsigned long int *f1, unsigned long int *f2, double prob){
  switch (i) {
    case 1:
      TwoPointCrossover(len, p1, p2, f1, f2);
      break;
    case 2:
      UniformCrossover(len, p1, p2, f1, f2, prob);
      break;
    default:
      OnePointCrossover(len, p1, p2, f1, f2);
      break;
  }
  if(*f1 < 0 || *f1 > pow(2, len))
    *f1 = randGene(len);
  if(*f2 < 0 || *f2 > pow(2, len))
    *f2 = randGene(len);
}

void SingleBitFlipMutation(unsigned char len, unsigned long int *f, double prob){
  if(uniform() < prob){
    unsigned char p = uniform() * (len - 1); /* p \in [1, len] */
    unsigned long int mask = 1 << p;
    *f = (*f) ^ mask;
  }
}

void BitFlipMutation(unsigned char len, unsigned long int *f, double prob){
  unsigned long int mask = 1;
  register unsigned char i;
  for(i = 0; i < len; i++) if(uniform() < prob) *f = (*f) ^ (mask << i);
}

void RandomResetMutation(unsigned char len, unsigned long int *f){
  unsigned long int mask = 1;
  register unsigned char i;
  for(i = 0; i < len; i++) if(uniform() < 0.5) *f = (*f) ^ (mask << i);
}

void BitSwapMutation(unsigned char len, unsigned long int *f){
  unsigned char p = uniform() * (len - 2) + 1; /* p \in [1, len-2] */
  unsigned char q = uniform() * (len - 1 - p) + 1; /* q \in [1, len-1-p] */
  /* xor contains xor of two sets */
  unsigned long int xor = ((*f >> p) ^ (*f >> q)) & ((1U << 2) - 1);

  /* To swap two sets, we need to again XOR the xor with original sets */
  *f = *f ^ ( (xor << p) | (xor << q));
}

void Mutate(int i, unsigned char len, unsigned long int *f, double prob){
  switch (i) {
    case 1:
      BitSwapMutation(len, f);
      break;
    case 2:
      BitFlipMutation(len, f, prob);
      break;
    case 3:
      RandomResetMutation(len, f);
      break;
    default:
      SingleBitFlipMutation(len, f, prob);
      break;
  }
  if(*f < 0 || *f > pow(2, len))
    *f = randGene(len);
}
