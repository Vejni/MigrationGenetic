#include <limits.h>

void OnePointCrossover(unsigned char len, unsigned long int p1, unsigned long int p2, unsigned long int *f1, unsigned long int *f2){
  /* d \in [1, 8*sizeof(unsigned long int)-1] */
  unsigned char d = uniform()*(8*sizeof(len)-1) + 1;
  /* d 0's at the beginning and (8*sizeof(unsigned long int) - d) 1's at the end */
  unsigned long int mask = 0xFFFFFFFFFFFFFFFFU << d;

  *f1 = (p1 & mask) | (p2 & ~mask);
  *f2 = (p2 & mask) | (p1 & ~mask);
}

void TwoPointCrossover(unsigned char len, unsigned long int p1, unsigned long int p2, unsigned long int *f1, unsigned long int *f2){
  unsigned char p = uniform()*(len-2) + 1; /* p \in [1, len-2] */
  unsigned char q = uniform() * (len - 1 - p) + 1; /* q \in [1, len-1-p] */
  unsigned long int mask = ((1 << q) - 1) << p;
  *f1 = (p1 & mask) | (p2 & ~mask);
  *f2 = (p2 & mask) | (p1 & ~mask);
}

void UniformCrossover(unsigned char len, unsigned long int p1, unsigned long int p2, unsigned long int *f1, unsigned long int *f2, double prob){
  unsigned long int mask = 0U;
  register unsigned char i;
  for(i=0; i < len; i++) if(uniform() < prob) mask = mask | (1U << i);
  *f1 = (p1 & mask) | (p2 & ~mask);
  *f2 = (p2 & mask) | (p1 & ~mask);
}

void Crossover(int i, unsigned char len, unsigned long int p1, unsigned long int p2, unsigned long int *f1, unsigned long int *f2, double prob){
  switch (i) {
    case 1:
      OnePointCrossover(len, p1, p2, f1, f2);
      break;
    case 2:
      TwoPointCrossover(len, p1, p2, f1, f2);
      break;
    default:
      UniformCrossover(len, p1, p2, f1, f2, prob);
      break;
  }

}

void mutation1(unsigned long int *f, double prob){
  if(uniform() < prob) *f = (*f)^(1U << ((unsigned char) uniform()*8*sizeof(*f)));
}

void BitFlipMutation(unsigned long int *f, double prob){
  unsigned char len = 8*sizeof(*f);
  unsigned long int mask = 0U;
  register unsigned char i;
  for(i=0; i < len; i++) if(uniform() < prob) *f = (*f)^(1U << i);
}

void Mutate(int i, unsigned long int *f, double prob){
  switch (i) {
    case 1:
      return;
      break;
    case 2:
      mutation1(f, prob);
      break;
    default:
      BitFlipMutation(f, prob);
      break;
  }
}
