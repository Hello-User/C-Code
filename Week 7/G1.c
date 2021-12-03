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
void koppelB (struct Queue *Q, struct Queue *R);
void koppelA(struct Queue *Q, struct Queue *R);
void delHead (struct Queue *q);
void print_list(struct node *head);

int main(){
    struct Queue *q;
    struct Queue *R;
    q = (struct Queue *) malloc(sizeof(struct Queue));
    R = (struct Queue *) malloc(sizeof(struct Queue));
    q->head=NULL;
    q->tail=NULL;
    R->head=NULL;
    R->tail=NULL;
    for(int i=0; i<3; i++){
        voegToe(q, i);
        voegToe(R, i);
        //printf("%d\t%d\n", tail(q), tail(R));
    }
    printf("Q voor koppeling: \n");
    print_list(q->head);
    koppelB(q, R);
    printf("Q na koppeling: \n");
    print_list(q->head);
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

void delHead (struct Queue *q){
    struct node *temp2;
    temp2 = q->head;
    q->head = q->head->next;
    free(temp2);
    if (q->head==NULL) q->tail=NULL;
}

void koppelB (struct Queue *Q, struct Queue *R){
    if (Q->head){
        Q->tail->next = R->head;
        Q->tail=R->tail;
        R->head = NULL;
        R->tail = NULL;
    }
    else{
        Q->head = R->head;
        Q->tail = R->tail;
        R->head = NULL;
        R->tail = NULL;
    }
    //free(R);
}

void koppelA(struct Queue *Q, struct Queue *R){
    while(!isLeeg(R)){
        voegToe(Q, head(R));
        delHead(R);
    }
}

void print_list(struct node *head) {
    struct node * current = head;
    while (current != NULL) {
        printf("%d\n", current->getal);
        current = current->next;
    }
}
