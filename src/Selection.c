#include "Randombits.c"
#include "Utils.c"

typedef struct {
  unsigned long int x0;
  unsigned long int phi;
  unsigned long int lambda;
  unsigned long int mu;
  unsigned long int sigma;
  unsigned long int delta;
} Genotype;

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
  // Get exponent for random  num generation
  unsigned short int n = nextPowerOf2(pop_size);

  unsigned long int * rand;
  if((rand = (unsigned long int *) malloc(k * sizeof(unsigned long int))) == NULL)
    exit(1);

  for (size_t j = 0; j < 2; j++) {
    // Generate k indexes
    for (size_t i = 0; i < k; i++) {
      // While overshooting, generate again
      do {
          rand[i] = ULNGran(n);
      } while(rand[i] > pop_size);
    }

    // Tournament
    int best = INT_MAX;
    size_t best_i = 0;
    for (size_t i = 0; i < k; i++){
      if (fit[rand[i]] < best){
        best = fit[rand[i]];
        best_i = i;
      }
    }
    parents[j] = pop[rand[best_i]];
  }
}

void RankSelection(Genotype * parents, unsigned short pop_size, Genotype * pop, double * fit){
  // Get ranks by ordering them
  size_t * ranks = order_ind(fit, pop_size);
  // From here same as roulette with different total

  // Get total
  size_t total = 0;
  for (size_t i = 0; i < pop_size; i++) {
    total += ranks[i];
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
      total += ranks[i];
      i++;
    }
    // Found it
    parents[j] = pop[i];
  }
}

void RandomSelection(Genotype * parents, unsigned short pop_size, Genotype * pop){
  // Get exponent for random  num generation
  unsigned short int n = nextPowerOf2(pop_size);

  unsigned long int * rand;
  if((rand = (unsigned long int *) malloc(2 * sizeof(unsigned long int))) == NULL)
    exit(1);

  for (size_t j = 0; j < 2; j++){
    // While overshooting, generate again
    do {
      rand[j] = ULNGran(n);
  } while(rand[j] > pop_size);
    parents[j] = pop[rand[j]];
  }
}
