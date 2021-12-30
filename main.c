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
  };

  unsigned short years = 11;
  double x0 = 15329;
  double *xt;

  if((xt = (double *) malloc(years * sizeof(double))) == NULL)
    exit(1);

  int res = GenerateEDOPrediction(xt, x0, years, &params);

  for(int i = 0; i < years; i++)
    printf("x[%d] = %f\n", i, xt[i]);
  printf("Result = %d\n", res);
  */

  GeneticSolve(100);
}
