#include "src/Genetic.c"

int main(int argc, char *argv[]){

  unsigned short n_iter = argc>1? atoi(argv[1]) : 100;
	unsigned short pop_size = argc>2? atoi(argv[2]) : 1000;
	unsigned short unchanged_max = argc>3? atoi(argv[3]) : 100;
  int fitness_case = argc>4? atoi(argv[4]) : -1;
	int select_case = argc>5? atoi(argv[5]) : -1;
  int crossover_case = argc>6? atoi(argv[6]) : -1;
	int mutation_case = argc>7? atoi(argv[7]) : -1;
	double crossover_prob = argc>8? atof(argv[8]) : 0.1;
	double mutation_prob = argc>9? atof(argv[9]) : 0.1;
  unsigned short k = argc>10? atof(argv[10]) : 100;
  char * path = argc>11? argv[11] : "logs/residues.csv";
  char * fittest_path = argc>11? argv[11] : "logs/residues_fittest.csv";

  Genotype fittest = GeneticSolve(n_iter, pop_size, unchanged_max, fitness_case, select_case, mutation_case, crossover_case, crossover_prob, mutation_prob, k, path);

  // Log fittest one only
  FILE *fp = NULL;
  fp = fopen("./logs/residues_fittest.csv", "w");
  if(fp == NULL) exit(1);
  LogResidues(fittest, fp);
  fprintf(fp, "%ld, %ld, %ld, %ld, %ld, %ld", fittest.x0, fittest.phi, fittest.lambda, fittest.mu, fittest.sigma, fittest.delta);
  fclose(fp);
}
