#include <stdio.h>
#include <math.h>

void update(int *a,int *b) {
    int res1 = *a + *b;
    int res2 = abs(*a - *b);
    *a = res1;
    *b = res2;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;

    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
