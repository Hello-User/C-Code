#include <stdio.h>
#include <math.h>

int main(){
    int i;
    double wortel;
    int getal;

    printf("Voer een getal in: ");
    scanf("%d", &getal);

    if(getal < 2){
        printf("%d is geen priemgetal", getal);
    }

    else{
    wortel = sqrt(getal);

    for(i = 2; i <= wortel; i++){
       if(getal % i == 0){
           printf("%d is geen priemgetal", getal);
       return 0;
       }
    }
    
    printf("%d is een priemgetal", getal);
    
    }
    return 0;
}