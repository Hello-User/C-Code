/*
 * Student1: S.K Soekhlal
 * Nummer: 20123493
 * Student2: E.K. Appau
 * Nummer2: 20118775
 * Assignment: C3 - abc formule
 */


#include<math.h>
#include<stdio.h>

double discriminant(double a, double b, double c){
    return (pow(b,2)-(4*a*c)); /*Bereken Discriminant */
}

void abc(double a, double b, double c){
    float D = discriminant(a, b, c);
    static double x1,x2;
        if (D>0){
        x1 = ((-b+sqrt(D))/(2.0*a));
        x2 = ((-b-sqrt(D))/(2.0*a));
        printf("De oplossingen van %.4lfx^2 + %.4lfx + %.4lf zijn: x1 = %.4lf, x2 = %.4lf\n", a, b, c, x1, x2);
    }
    else if (D<0){
        printf("De vergelijking %.4lfx^2 + %.4lfx + %.4lf heeft geen reële oplossingen.\n", a, b, c);
    }
    else{
        x1 = -b/(2.0*a);
        x2 = x1;
        printf("De oplossing van %.4lfx^2 + %.4lfx + %.4lf is: x = %.4lf\n", a, b, c, x1);
    }
}

int main(){
    int testcases;
    double a,b,c;
    scanf("%d", &testcases);
    for (int i = 0; i < testcases; i++){
        scanf("%lf %lf %lf", &a, &b, &c);
        abc(a, b, c);
    }
    return 0;
}