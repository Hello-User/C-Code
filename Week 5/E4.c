#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int countMatches(const char *string, char *searchquery);

int main(void){
    char str[100];
    gets(str);
    char query[20];
    gets(query);
    const char *ptr = str;
    
    int count = countMatches(ptr, query);

    printf("In de gegeven zin komt de combinatie '%s' %d keer voor.\n", query, count);
    system("PAUSE");
    return 0;
}

int countMatches(const char *string, char *searchquery){
    int count = 0;
    while(string = strstr (string, searchquery)){
        count++;
        string++;
    }
    return count;
}