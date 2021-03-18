/*
 * Student1: S.K Soekhlal
 * Nummer: 20123493
 * Student2: E.K. Appau
 * Nummer2: 20118775
 * Assignment: C2 - Gemiddelde
 */


#include <stdio.h>

double bereken_gemiddelde (int getal){
    static double x = 0.0;
    static int hoeveelheid;
    x = x + getal;
    hoeveelheid++;
    return (x/hoeveelheid);
}

int main(void){
 double gemiddelde;
 while (1){
    int getal;
    scanf("%d", &getal);
    if (getal == 0)
        break;
    else
    gemiddelde = bereken_gemiddelde(getal);
 }
 printf("%.1f\n", gemiddelde);
 system("PAUSE");
 return 0;
}
