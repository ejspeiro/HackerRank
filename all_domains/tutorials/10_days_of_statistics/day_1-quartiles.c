#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int CompareFunction(const void *aa, const void *bb) {

   return (*(int*)aa - *(int*)bb);
}

int SortedMedian(const int *values, size_t num_elems) {

  size_t index_median = 0;  // Index of the median.
  double num_elems_as_double = (double) num_elems;  // Explicit cast for ceil().
  int median = 0;  // Actual median.

  if (num_elems%2 == 0) {
    // Even number of elements.
    size_t upper_idx = (size_t) ceil(num_elems_as_double/2.0);
    size_t lower_idx = upper_idx - 1;
    median = (values[upper_idx] + values[lower_idx])/2;
  } else {
    // Odd number of elements.
    index_median = (size_t) ceil(num_elems_as_double/2.0 - 1.0);
    median = values[index_median];
  }

  return median;
}

int main() {

  size_t num_elems = 0;  // Number of elements.

  fscanf(stdin, "%zu", &num_elems);

  int *values = NULL;  // Array of values.

  values = (int *) calloc(num_elems, sizeof(int));
  if (values == NULL) {
    fprintf(stderr, "ERROR: Allocation failed for values.\n");
    return EXIT_FAILURE;
  }
  for (size_t ii = 0; ii < num_elems; ++ii) {
    fscanf(stdin, "%d ", &values[ii]);
  }

  // Sort given values. Linearithmic complexity.
  qsort(values, num_elems, sizeof(int), CompareFunction);

  // Compute quartiles.
  int q1 = 0;
  int q2 = SortedMedian(values, num_elems);
  int q3 = 0;

  if (num_elems%2 == 0) {
    q1 = SortedMedian(values, num_elems/2);
    q3 = SortedMedian(values + num_elems/2, num_elems/2);
  } else {
    q1 = SortedMedian(values, num_elems/2);
    q3 = SortedMedian(values + num_elems/2 + 1, num_elems/2);
  }

  fprintf(stdout, "%d\n", q1);
  fprintf(stdout, "%d\n", q2);
  fprintf(stdout, "%d\n", q3);

  return EXIT_SUCCESS;
}
