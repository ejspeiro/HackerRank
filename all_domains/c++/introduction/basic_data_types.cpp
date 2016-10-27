#include <cstdio>

int main () {
  
    int aa{};
    long bb{};
    long long cc{};
    char dd{};
    float ee{};
    double ff{};
    
    fscanf(stdin, "%d %ld %lld %c %f %lf", &aa, &bb, &cc, &dd, &ee, &ff);
    fprintf(stdout, "%d\n%ld\n%lld\n%c\n%.2f\n%.9lf\n", aa, bb, cc, dd, ee, ff);
}
