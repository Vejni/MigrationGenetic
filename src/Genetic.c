#include "Randombits.c"
#include "Predict.c"
#include <math.h>
#include <limits.h>

#define YEARS 11
#define BETA 0.000024382635446
#define X0_RES 0.0079155006005766
#define LAMBDA_RES 8.940696982762
#define MU_RES 5.960464655174
#define SIGMA_RES 0.007629452739355006
#define DELTA_RES 0.7629627368999298
#define PHI_OFFSET 100
#define PHI_RES 5.841138773

typedef struct {
  unsigned long int x0;
  unsigned long int phi;
  unsigned long int lambda;
  unsigned long int mu;
  unsigned long int sigma;
  unsigned long int delta;
} Genotype;

const int observations[] = {14177, 13031, 9762, 11271, 8688, 7571, 6983, 4778, 2067, 1586, 793};

double * Predict(Genotype gene){
  double *xt;

  if((xt = (double *) malloc(YEARS * sizeof(double))) == NULL)
    exit(1);

  // Genotype to Phenotype
  ODE_Parameters params;
  params.phi = (gene.phi * PHI_RES * 0.000000001) - PHI_OFFSET;
  params.beta = BETA;
  params.lambda = gene.lambda * LAMBDA_RES * 0.00001;
  params.mu = gene.mu * MU_RES * 0.0000001;
  params.sigma = gene.sigma * SIGMA_RES;
  params.delta = gene.delta * DELTA_RES;
  //printf("%f %ld %ld %ld %ld %ld\n", BETA, gene.phi, gene.mu, gene.sigma, gene.delta, gene.lambda);
  //printf("%f %f %f %f %f %f\n", params.beta, params.phi, params.mu, params.sigma, params.delta, params.lambda);

  int x = GenerateEDOPrediction(xt, gene.x0 * X0_RES, YEARS, &params2);
  return xt;
}

double fitness(Genotype gene){
  int res = INT_MIN;
  double * xt = Predict(gene);
  for (size_t i = 0; i < YEARS; i++) {
    int diff = (xt[i] - observations[i]);
    res = fmax(res, diff * diff);
  }
  return res;
}

unsigned long int randGene(int size){
  unsigned long int rand;
  do {
    rand = ULNGran(21);
  } while(rand == pow(2, size)); // to exclude the last value of the range
  return rand;
}

Genotype * InitPopulation(unsigned short pop_size){
  Genotype * pop;
  int i;

  if((pop = (Genotype *) malloc(pop_size * sizeof(Genotype))) == NULL)
    exit(1);

  for (i = 0; i < pop_size; i++) {
    pop[i].x0 = randGene(21);
    pop[i].phi = randGene(34);
    pop[i].lambda = randGene(25);
    pop[i].mu = randGene(25);
    pop[i].sigma = randGene(17);
    pop[i].delta = randGene(15);
    //printf("%ld %ld %ld %ld %ld %ld\n", pop[i].x0, pop[i].phi, pop[i].lambda, pop[i].mu, pop[i].sigma, pop[i].delta);
  }

  return pop;
}

Genotype GeneticSolve(unsigned short pop_size){
  // Generate Initial Population
  randomize();
  Genotype * pop = InitPopulation(pop_size);

  // Compute Fitness for each Individual
  double * fit;
  if((fit = (double *) malloc(pop_size * sizeof(double))) == NULL)
    exit(1);
  for (size_t i = 0; i < pop_size; i++) {
    fit[i] = fitness(pop[i]);
    printf("%f\n", fit[i]);
  }

  // While not converging
  while(1){
    // produce new generation

    // For Half the population do
    for (size_t i = 0; i < 10; i++) {
      // select two individuals from old generation for mating
      // ecombine the two individuals to give two offspring
      // compute fitness of the two offspring
      // insert offspring in new generation
      break;
    }
    break;
  }
  return pop[0];
}
