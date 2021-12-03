#include <stdio.h>

int main(void){
 char s[7] = "abcdef";
 char *ptr = s;
 printf("s[0] is %c en staat op adres %x\n", s[0], &s[0]);
 printf("s[1] is %c en staat op adres %x\n", s[1], (long long)&s[1]);
 printf("s[2] is %c en staat op adres %x\n", s[2], (long long)&s[2]);
 printf("s is %s (%x)\n", s, (long long)s);
 printf("s + 2 is %s (%x)\n", s + 2, (long long)(s + 2));
 printf("ptr is %s (%x)\n", ptr, (long long)ptr);
 printf("ptr + 4 is %s (%x)\n", ptr + 4, (long long)(ptr + 4));
 
 system("PAUSE");
 return 0;
}
