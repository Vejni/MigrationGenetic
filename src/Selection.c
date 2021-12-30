#include "Randombits.c"

typedef struct {
  unsigned long int x0;
  unsigned long int phi;
  unsigned long int lambda;
  unsigned long int mu;
  unsigned long int sigma;
  unsigned long int delta;
} Genotype;

unsigned short int nextPowerOf2(unsigned long int n){
  unsigned count = 0;
  // First n in the below condition
  // is for the case where n is 0
  if (n && !(n & (n - 1)))
      return n;

  while( n != 0){
      n >>= 1;
      count += 1;
  }
  return count;
}

void RouletteWheelSelection(Genotype * parents, unsigned short pop_size, Genotype * pop, double * fit){
  // Get total
  double total = 0;
  for (size_t i = 0; i < pop_size; i++) {
    total += fit[i];
  }

  // Get exponent for random  num generation
  unsigned short int n = nextPowerOf2(total);

  // Spin the wheel for both parents
  for (size_t j = 0; j < 2; j++) {
    // While overshooting, generate again
    unsigned long int rand;
    do {
      rand = ULNGran(n);
    } while(rand > total);

    // Find Genotype
    total = 0;
    int i = 0;
    while (total < rand){
      total += fit[i];
      i++;
    }
    // Found it
    parents[j] = pop[i];
  }
}

void StochasticUniversalSampling(Genotype * parents, unsigned short pop_size, Genotype * pop, double * fit){
  // Get total
  double total = 0;
  for (size_t i = 0; i < pop_size; i++) {
    total += fit[i];
  }

  // Get exponent for random  num generation
  unsigned long n = nextPowerOf2(total);

  // In this case we spin the wheel once with 2 balls
  unsigned long int * rand;
  if((rand = (unsigned long int *) malloc(2 * sizeof(unsigned long int))) == NULL)
    exit(1);
  for (size_t j = 0; j < 2; j++){
    // While overshooting, generate again
    do {
      rand[j] = ULNGran(n);
    } while(rand[j] > total);
  }

  // Oder it
  if (rand[1] > rand[0]){
    n = rand[1];
    rand[1] = rand[0];
    rand[0] = n;
  }

  for (size_t j = 0; j < 2; j++) {
    // Find Genotype
    total = 0;
    int i = 0;
    while (total < rand[j]){
      total += fit[i];
      i++;
    }
    // Found it
    parents[j] = pop[i];
  }
}

void TournamentSelection(Genotype * parents, unsigned short pop_size, Genotype * pop, double * fit, unsigned short k){
  return;
}

void RankSelection(Genotype * pop){
  return;
}

void RandomSelection(Genotype * parents, unsigned short pop_size, Genotype * pop){
  // Get exponent for random  num generation
  unsigned short int n = nextPowerOf2(pop_size);
  printf("%d\n", n);

  unsigned long int * rand;
  if((rand = (unsigned long int *) malloc(2 * sizeof(unsigned long int))) == NULL)
    exit(1);

  for (size_t j = 0; j < 2; j++){
    // While overshooting, generate again
    do {
      rand[j] = ULNGran(n);
  } while(rand[j] > pop_size);
    parents[j] = pop[rand[j]];
        printf("%ld\n", rand[j]);
  }
}
