#include <stdio.h>
#include <stdlib.h>

float gemiddeld(int beoordeling[], int n){
    int i;
    float sum = 0.0;
    for (i = 0; i < n; i++){
        sum = sum + beoordeling[i];
    }
    return sum/n;
}

int main(){
    int resultaat[10]={8,7,3,2,5,6,10,1,1,8};
    printf("Het gemiddelde is: %.3f\n\n", gemiddeld(resultaat,10));
    return 0;
}