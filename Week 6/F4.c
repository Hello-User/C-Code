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
void voegToe (struct Queue *q, int x);
int tail(struct Queue *q);

int main(){
    struct Queue *q;
    q = (struct Queue *) malloc(sizeof(struct Queue));
    q->head=NULL;
    q->tail=NULL;
    int i;
    for(i=0; i<10; i++){
        voegToe(q, i);
        printf("%d\t%d\n", head(q), tail(q));
    }
}

int head(struct Queue *q){
    return q->head->getal;
}

int tail(struct Queue *q){
    return q->tail->getal;
}

int isLeeg(struct Queue *q){
    if (q->head==NULL){
        return 1;
    }
    else return 0;
}

void voegToe (struct Queue *q, int x){
    struct node *temp;
    temp = (struct node*) malloc(sizeof(struct node));
    temp->getal = x;
    temp->next = NULL;
    if(!isLeeg(q)){
        q->tail->next = temp;
        q->tail = temp;
    }
    else{
        q->head = q->tail = temp;
    }
}
