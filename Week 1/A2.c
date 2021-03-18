/*
 * Student: S.K Soekhlal
 * Number: 20123493
 * Assignment: A2 - Een rekenkundige rij
 */

#include<stdio.h>
#include<stdlib.h>

int main(){
    double t1,v,n,tn=0;
    scanf("%lf%lf%lf",&t1,&v,&n);
    tn = (t1 + ((n-1)*v));
    printf("%.2lf\n", tn);
    return 0;
}