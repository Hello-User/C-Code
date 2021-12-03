#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    char *n;
    char str[] = "Deze zin dient e als een voorbeeld.";
    n = strstr(str, "ee");
    printf("%x\n", &str[21]);
    printf("%x", n);
}