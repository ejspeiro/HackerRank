#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()  {
  char cc = '\0';
  char s1[100];
  char s2[100];
  scanf("%c", &cc);
  scanf("%s", s1);
  scanf("\n");
  scanf("%[^\n]%*c", s2);
  printf("%c\n", cc);
  printf("%s\n", s1);
  printf("%s\n", s2);
  return 0;
}
