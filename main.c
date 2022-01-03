#include "src/Genetic.c"

int main(int argc, char *argv[]){

  int autopilot = argc>1? atoi(argv[1]) : 1;
  unsigned short n_iter = argc>2? atoi(argv[2]) : 1000;
	unsigned short pop_size = argc>3? atoi(argv[3]) : 1000;
	unsigned short unchanged_max = argc>4? atoi(argv[4]) : 50;
  int fitness_case = argc>5? atoi(argv[5]) : 0;
	int select_case = argc>6? atoi(argv[6]) : 0;
  int crossover_case = argc>7? atoi(argv[7]) : 0;
	int mutation_case = argc>8? atoi(argv[8]) : 0;
	double crossover_prob = argc>9? atof(argv[9]) : 0.1;
	double mutation_prob = argc>10? atof(argv[10]) : 0.1;
  unsigned short k = argc>11? atof(argv[11]) : 500;
  char * path = argc>12? argv[12] : "logs/fittness.csv";
  char * fittest_path = argc>13? argv[13] : "logs/residues_fittest.csv";

  Genotype fittest = GeneticSolve(autopilot, n_iter, pop_size, unchanged_max, fitness_case, select_case, mutation_case, crossover_case, crossover_prob, mutation_prob, k, path);

  // Log fittest one only
  FILE *fp = NULL;
  fp = fopen("./logs/residues_fittest.csv", "w");
  if(fp == NULL) exit(1);
  LogResidues(fittest, fp);

  ODE_Parameters params;
  params.phi = (fittest.phi * PHI_RES * 0.000000001) - PHI_OFFSET;
  params.lambda = fittest.lambda * LAMBDA_RES * 0.00001;
  params.mu = fittest.mu * MU_RES * 0.0000001;
  params.sigma = fittest.sigma * SIGMA_RES;
  params.delta = fittest.delta * DELTA_RES;
  fprintf(fp, "BETA = %f X0 = %f PHI = %f LAMBDA = %f MU = %f SIGMA = %f DELTA = %f\n", BETA, fittest.x0 * X0_RES, params.phi, params.lambda, params.mu, params.sigma, params.delta);

  fclose(fp);
}
