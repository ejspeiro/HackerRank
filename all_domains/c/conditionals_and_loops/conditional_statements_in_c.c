#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();



int main()
{
    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    switch (n) {
      case 1: {
        fprintf(stdout, "one\n");
        break;
      }
      case 2: {
        fprintf(stdout, "two\n");
        break;
      }
      case 3: {
        fprintf(stdout, "three\n");
        break;
      }
      case 4: {
        fprintf(stdout, "four\n");
        break;
      }
      case 5: {
        fprintf(stdout, "five\n");
        break;
      }
      case 6: {
        fprintf(stdout, "six\n");
        break;
      }
      case 7: {
        fprintf(stdout, "seven\n");
        break;
      }
      case 8: {
        fprintf(stdout, "eight\n");
        break;
      }
      case 9: {
        fprintf(stdout, "nine\n");
        break;
      }
      default: {
        fprintf(stdout, "Greater than 9\n");
        break;
      }
    }

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}
