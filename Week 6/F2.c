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

int main(){
    struct Queue *q;
    struct node *temp;
    temp = (struct node*) malloc(sizeof(struct node));
    int d;
    scanf("%d", &d);
    temp->getal = d;
    temp->next = NULL;
    q->head = temp;
    q->tail=temp;
    printf("%d\n", head(q));
}

int head(struct Queue *q){
    return q->head->getal;
}

int isLeeg(struct Queue *q){
    if (q->head==NULL){
        return 1;
    }
    else return 0;
}