#include <stdio.h>

int main(){
    int a[] = {5,12,34,54,14,2,52,72};
    int *p = a, *q = &a[5];

    printf("%d\n", *p<*q);
    return 0;
}