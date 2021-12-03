#include <stdio.h>
#include <stdlib.h>

    struct node{
        int getal;
        struct node* next;
    };
    struct Queue{
        struct node* head;
        struct node* tail;
    };

int isLeeg(struct Queue *q);

int main(){

    struct Queue *q;
    struct node *node1;
    struct node *node2;
    q = (struct Queue *) malloc(sizeof(struct Queue));
    node1 = node2 = (struct node *) malloc(sizeof(struct node));
    node1->getal = 10;
    node1->next = node2;
    node2 ->getal = 20;
    q->head = NULL;
    q->tail = NULL;
    printf("%d", isLeeg(q));
}

int isLeeg(struct Queue *q){
    if (q->head==NULL){
        return 1;
    }
    else return 0;
}
