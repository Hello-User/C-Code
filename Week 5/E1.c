#include <stdio.h>

int main(void){
 int a, b;
 int *ptr;
 a = 1;
 b = 2;
 ptr = &a;
 printf("a heeft waarde %d en staat op adres %x\n", a, (long long)&a);
 printf("b heeft waarde %d en staat op adres %x\n", b, (long long)&b);
 printf("ptr heeft waarde %x en staat op adres %x\n", (long long)ptr, (long long)&ptr);
 printf("De integer waarde waar ptr naar wijst is %d\n", *ptr);
 system("PAUSE");
 return 0;
}
