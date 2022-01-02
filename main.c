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
  unsigned short n_iter = argc>1? atoi(argv[1]) : 1;
	unsigned short pop_size = argc>2? atof(argv[2]) : 10;
	int select_case = argc>3? atof(argv[3]) : -1;
	int mutation_case = argc>3? atof(argv[3]) : -1;
	int crossover_case = argc>3? atof(argv[3]) : -1;
	double crossover_prob = argc>5? atof(argv[5]) : 0.5;
	double mutation_prob = argc>5? atof(argv[5]) : 1.0;
  unsigned short k = argc>5? atof(argv[5]) : 10;

  GeneticSolve(n_iter, pop_size, select_case, mutation_case, crossover_case, crossover_prob, mutation_prob, k);
}
