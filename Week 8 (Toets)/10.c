#include <stdio.h>

int main(){
    int rekening[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9}, sum;
    int cijfers = 9;
    //for (int i = 0; i<9; i++){
    //    scanf("%d", &rekening[i]);
    //}
    for (int i = 0; i < 9; i++){
        sum += rekening[i] * cijfers;
        cijfers--; 
    }
    if (sum%11 == 0){
        printf("Dit is een geldig rekeningnummer");
        return 0;
    }
    else{
        printf("Niet geldig");
    }
    return 0;
}