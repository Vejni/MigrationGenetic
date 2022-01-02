#include "src/Genetic.c"

int main(int argc, char *argv[]){
  /*
  ODE_Parameters params = {
    0.3489494085776018,
    0.000024382635446,
    1500,
    10,
    500,
    10000
    */
  unsigned short n_iter = argc>1? atoi(argv[1]) : 10;
	unsigned short pop_size = argc>2? atof(argv[2]) : 100;
  int fitness_case = argc>3? atof(argv[3]) : -1;
	int select_case = argc>4? atof(argv[4]) : -1;
	int mutation_case = argc>5? atof(argv[5]) : -1;
	int crossover_case = argc>6? atof(argv[6]) : -1;
	double crossover_prob = argc>7? atof(argv[7]) : 0.1;
	double mutation_prob = argc>8? atof(argv[8]) : 0.01;
  unsigned short k = argc>9? atof(argv[9]) : 10;

  GeneticSolve(n_iter, pop_size, fitness_case, select_case, mutation_case, crossover_case, crossover_prob, mutation_prob, k);
}
