#include "Predict.c"
#include "Selection.c"
#include "Crossovers.c"
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

const int observations[] = {14177, 13031, 9762, 11271, 8688, 7571, 6983, 4778, 2067, 1586, 793};

void PrintGenotype(Genotype gene){
    printf("X0 = %ld PHI = %ld LAMBDA = %ld MU = %ld SIGMA = %ld DELTA = %ld\n", gene.x0, gene.phi, gene.lambda, gene.mu, gene.sigma, gene.delta);
}

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
  //printf("%f %ld %ld %ld %ld %ld %ld\n", BETA, gene.x0,gene.phi, gene.mu, gene.sigma, gene.delta, gene.lambda);
  //printf("%f %f %f %f %f %f %f\n", params.beta, gene.x0 * X0_RES,params.phi, params.mu, params.sigma, params.delta, params.lambda);

  int x = GenerateEDOPrediction(xt, gene.x0 * X0_RES, YEARS, &params);
  return xt;
}

double fitness(Genotype gene){
  int res = INT_MIN;
  double * xt = Predict(gene);
  for (size_t i = 0; i < YEARS; i++) {
    int diff = (xt[i] - observations[i]);
    res = fmax(res, diff * diff);
    //printf("%d\n", xt[i]);
  }
  return res;
}

unsigned long int randGene(int size){
  unsigned long int rand;
  do {
    rand = ULNGran(size);
  } while(rand == pow(2, size)); // to exclude the last value of the range
  return rand;
}

void InitPopulation(Genotype * pop, unsigned short pop_size){
  for (size_t i = 0; i < pop_size; i++) {
    do {
      pop[i].x0 = randGene(21);
      pop[i].phi = randGene(34);
      pop[i].lambda = randGene(25);;
      pop[i].mu = randGene(25);
      pop[i].sigma = randGene(17);
      pop[i].delta = randGene(15);
      //Should not need this in theory
    } while(fitness(pop[i]) == 0);
    //PrintGenotype(pop[i]);
  }
}

void GetOffspings(int i, Genotype * parents, Genotype * offsprings, double prob){
  Crossover(i, parents[0].x0, parents[1].x0, &offsprings[0].x0, &offsprings[1].x0, prob);
  Crossover(i, parents[0].phi, parents[1].phi, &offsprings[0].phi, &offsprings[1].phi, prob);
  Crossover(i, parents[0].lambda, parents[1].lambda, &offsprings[0].lambda, &offsprings[1].lambda, prob);
  Crossover(i, parents[0].mu, parents[1].mu, &offsprings[0].mu, &offsprings[1].mu, prob);
  Crossover(i, parents[0].sigma, parents[1].sigma, &offsprings[0].sigma, &offsprings[1].sigma, prob);
  Crossover(i, parents[0].delta, parents[1].delta, &offsprings[0].delta, &offsprings[1].delta, prob);
}

void MutateOffsprings(int i, Genotype * offspring, double prob){
  for (size_t j = 0; j < 2; j++) {
    //PrintGenotype(offspring[j]);
    Mutate(i, &offspring[j].x0, prob);
    Mutate(i, &offspring[j].phi, prob);
    Mutate(i, &offspring[j].lambda, prob);
    Mutate(i, &offspring[j].mu, prob);
    Mutate(i, &offspring[j].sigma, prob);
    Mutate(i, &offspring[j].delta, prob);
    //PrintGenotype(offspring[j]);
  }
}

Genotype GeneticSolve(unsigned short n_iter, unsigned short pop_size, int select_case, int mutation_case, int crossover_case, double crossover_prob, double mutation_prob, unsigned short k){
  // It's easier to deal with an even population
  if(pop_size % 2)
    pop_size++;

  // Generate Initial Population
  randomize();
  Genotype * pop;
  if((pop = (Genotype *) malloc(pop_size * sizeof(Genotype))) == NULL)
      exit(1);
  InitPopulation(pop, pop_size);

  // Fitness for each Individual
  double * fit;
  if((fit = (double *) malloc(pop_size * sizeof(double))) == NULL)
    exit(1);

  // Init new_pop, parents, offsprings
  Genotype * new_pop;
  if((new_pop = (Genotype *) malloc(pop_size * sizeof(Genotype))) == NULL)
      exit(1);
  Genotype * offsprings;
  if((offsprings = (Genotype *) malloc(2 * sizeof(Genotype))) == NULL)
      exit(1);
  Genotype * pars;
  if((pars = (Genotype *) malloc(2 * sizeof(Genotype))) == NULL)
      exit(1);

  // While not converging
  unsigned short iter = 0;
  while(iter < n_iter){
    // Calculate fitness of new generation
    for (size_t i = 0; i < pop_size; i++) {
      fit[i] = fitness(pop[i]);
    }

    // For Half the population do
    for (size_t i = 0; i < pop_size / 2; i++) {
      // select two individuals from old generation for mating
      Selection(4, pars, pop_size, pop, fit, k);
      PrintGenotype(pars[0]);
      PrintGenotype(pars[1]);

      // Combine the two individuals to give two offspring
      GetOffspings(crossover_case, pars, offsprings, crossover_prob);

      // Mutate
      MutateOffsprings(mutation_case, offsprings, mutation_prob);

      // insert offspring in new generation
      new_pop[i*2] = offsprings[0];
      new_pop[i*2 + 1] = offsprings[1];
    }
    iter++;
  }
  return pop[0];
}
