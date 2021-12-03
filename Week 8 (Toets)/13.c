#include <stdlib.h>

struct knoop{
    int getal;
    struct knoop *next;
 };


int is_leeg(struct knoop *begin){
    if(begin == NULL){
        return 1;
    }
    else return 0;
}

int zoek(struct knoop *begin, int n){
    struct knoop *temp;
    for(temp = begin; temp != NULL; temp = temp->next){
        if (temp->getal == n){
            return 1;
        }
    }
    return 0;
}

struct knoop *remove(struct knoop *begin, int n){
    struct knoop *cur, *prev;
    for(cur = begin, prev = NULL; cur != NULL && cur->getal != n; prev = cur, cur = cur->next){
        if (cur == NULL){
            return begin;
        }
        else{
            if (prev == NULL){
                begin = cur->next;
            }
            else {
                cur->getal = NULL;
                prev->next = cur->next;
            }
        }
    }
    free (cur);
    return begin;
}