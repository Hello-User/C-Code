#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char invoer[9];
    char nummer[9] = {'0'};
    scanf("%s", &invoer);
    int i;
    for (i=0; i<sizeof(invoer); i++){
        switch (invoer[i]){
        case 'a':
        case 'b':
        case 'c':
            nummer[i] = '2';
            break;
        case 'd':
        case 'e':
        case 'f':
            nummer[i] = '3';
            break;
        case 'g':
        case 'h':
        case 'i':
            nummer[i] = '4';
            break;
        case 'j':
        case 'k':
        case 'l':
            nummer[i] = '5';
            break;
        case 'm':
        case 'n':
        case 'o':
            nummer[i] = '6';
            break;
        case 'p':
        case 'q':
        case 'r':
        case 's':
            nummer[i] = '7';
            break;
        case 't':
        case 'u':
        case 'v':
            nummer[i] = '8';
            break;
        case 'w':
        case 'x':
        case 'y':
        case 'z':
            nummer[i] = '9';
            break;
        default:
            break;
        }
    }
    printf("06-%s\n\n", nummer);
    return 0;
}