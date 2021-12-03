#include <stdio.h>
#include <stdlib.h>

int main(){
    int G1, G2, GGD;
    float H;
    scanf("%d%d", &G1,&G2);
    if(G1 > G2){
        H = G1;
        G1 = G2;
        G2 = H;
    }
    while(G1 != 0){
        H = (float)G1/G1;
        G2 = G1;
        G1 = G1*(H-(int)(H));
    }
    GGD = G2;
    return GGD;
}