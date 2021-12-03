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

int head(struct Queue *q);
int isLeeg(struct Queue *q);
void delHead (struct Queue *q);

int main(){
    struct Queue *q;
    struct node *node1;
    struct node *node2;
    q = (struct Queue *) malloc(sizeof(struct Queue));
    node1 = node2 = (struct node *) malloc(sizeof(struct node));
    node1->getal = 20;
    node1->next = node2;
    node2 ->getal = 30;
    q->head=node1;
    q->tail=node2;
    printf("%d", head(q));
}

int head(struct Queue *q){
    return q->head->getal;
}

void delHead (struct Queue *q){
    struct node *temp2;
    temp2 = q->head;
    q->head = q->head->next;
    free(temp2);
    if (q->head==NULL) q->tail=NULL;
}