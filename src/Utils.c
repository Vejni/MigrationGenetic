#include <string.h>

struct str{
    double value;
    size_t index;
};

void printBinary(unsigned long int n, int len){
  // Prints unsigned long in binary format
  char * binary = (char*)malloc(sizeof(char) * len);
  int k = 0;
  for (unsigned i = (1 << len - 1); i > 0; i = i / 2) {
      binary[k++] = (n & i) ? '1' : '0';
  }
  binary[k] = '\0';
  printf("%s\n", binary);
}


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

int cmp(const void *a, const void *b){
  // Comparison function  for custom sorting
  struct str *a1 = (struct str *)a;
  struct str *a2 = (struct str *)b;
  if ((*a1).value > (*a2).value)
      return -1;
  else if ((*a1).value < (*a2).value)
      return 1;
  else
      return 0;
}

size_t * order_ind(double * arr, size_t n){
  // Use struct
  struct str objects[n];
  for (size_t i = 0; i < n; i++){
      objects[i].value = arr[i];
      objects[i].index = i + 1;
  }

  //sort objects array according to value maybe using qsort
  qsort(objects, 3, sizeof(objects[0]), cmp);

  // Get the indices
  size_t * indices;
  if((indices = (size_t *) malloc(n * sizeof(size_t))) == NULL)
    exit(1);

  for (size_t i = 0; i < n; i++)
    indices[i] = objects[i].index;

  return indices;
}
