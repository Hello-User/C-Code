/*
 * Student: S.K Soekhlal
 * Number: 20123493
 * Assignment: A1 - Convert C to K and F
 */

#include<stdio.h>
#include<stdlib.h>

int main(){
    double c,k=0,f=0; /*Declaring variables*/
    scanf("%lf",&c); /*Storing an inputted value in variable C(for celsius)*/
    k = c + 273.15; /*Calculating temperature in Kelvin*/
    f = (c*1.8)+32; /*Calculating temperature in Fahrenheit*/
    printf("C\tK\tF\n");
    printf("%.2f\t%.2f\t%.2f\n",c,k,f); /*printing values*/
    return 0;
}