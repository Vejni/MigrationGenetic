void OnePointCrossover(unsigned long int p1, unsigned long int p2, unsigned long int *f1, unsigned long int *f2){
  /* d \in [1, 8*sizeof(unsigned long int)-1] */
  unsigned char d = uniform()*(8*sizeof(unsigned long int)-1) + 1;
  /* d 0's at the beginning and (8*sizeof(unsigned long int) - d) 1's at the end */
  unsigned long int mask = 0xFFFFFFFFU << d;
  *f1 = (p1 & mask) | (p2 & ~mask);
  *f2 = (p2 & mask) | (p1 & ~mask);
}

void OnePointCrossover2(unsigned long int p1, unsigned long int p2, unsigned long int *f1, unsigned long int *f2){
  unsigned char len = 8*sizeof(unsigned long int);
  unsigned char d = uniform()*(len-1) + 1, di = len - d; /* d \in [1, len-1] */
  *f1 =((p1>>d)<<d) | ((p2<<di)>>di);
  *f2 =((p2>>d)<<d) | ((p1<<di)>>di);
}

void TwoPointCrossover(unsigned long int p1, unsigned long int p2, unsigned long int *f1, unsigned long int *f2){
  unsigned char len = 8*sizeof(unsigned long int);
  unsigned char p = uniform()*(len-2) + 1; /* p \in [1, len-2] */
  /* We want a mask with p 0's at the beginning; len-q zeros at the end;
  * and 1's between the positions p and q inclusive
  * where q \in [p+1, len-1].
  * CONSISTENCY NOTE: p <= len-2 ==> p+1 <= len-1
  * THEN: mask = (0xFFFFFFFFU >> (len-q+p)) << p;
  * OBSERVE THAT: p+1 <= len-q+p <= len-1 is a random number
  * THUS: len-q+p = uniform()*(len-p-1) + p+1; */
  unsigned long int mask = (0xFFFFFFFFU >> (((unsigned char) uniform()*(len-p-1)) + p+1)) << p;
  *f1 = (p1 & mask) | (p2 & ~mask);
  *f2 = (p2 & mask) | (p1 & ~mask);
}

void UniformCrossover(unsigned long int p1, unsigned long int p2, unsigned long int *f1, unsigned long int *f2, double prob){
  unsigned char len = 8*sizeof(*f1);
  unsigned long int mask = 0U;
  register unsigned char i;
  for(i=0; i < len; i++) if(uniform() < prob) mask = mask | (1U << i);
  *f1 = (p1 & mask) | (p2 & ~mask);
  *f2 = (p2 & mask) | (p1 & ~mask);
}

void Crossover(int i, unsigned long int p1, unsigned long int p2, unsigned long int *f1, unsigned long int *f2, double prob){
  switch (i) {
    case 1:
      OnePointCrossover(p1, p2, f1, f2);
      break;
    case 2:
      OnePointCrossover2(p1, p2, f1, f2);
      break;
    case 3:
      TwoPointCrossover(p1, p2, f1, f2);
      break;
    default:
      UniformCrossover(p1, p2, f1, f2, prob);
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
