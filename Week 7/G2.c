#include <stdio.h>			
#include <stdlib.h>
#include <string.h>

struct node{
    int getal;
    struct node* next;
};
struct Queue{
    struct node* head;
    struct node* tail;
};

struct Queue* copy (struct Queue *Q);
void voegToe (struct Queue *q, int x);
int isLeeg(struct Queue *q);

int main(){
    struct Queue *q;
    struct Queue *R;
    q = (struct Queue *) malloc(sizeof(struct Queue));
    q->head=NULL;
    q->tail=NULL;
    int i;
    for(i=0; i<3; i++){
        voegToe(q, i);
    }
    printf("%p\n", copy(q));
    q->head = NULL;
}

struct Queue* copy (struct Queue *Q){
    struct Queue *temp;
    temp = (struct Queue*) malloc(sizeof(struct Queue));
    if(Q->head == NULL){
        temp->head == NULL;
    }
    else{
        struct node *tempNode = malloc(sizeof(struct node));
        tempNode->getal = Q->head->getal;
        struct node *QHead = malloc(sizeof(struct node));
        QHead = Q->head;
        struct node *n = malloc(sizeof(struct node));
        n = tempNode;
        QHead = QHead->next;
        while(QHead != NULL){
            n->next = malloc(sizeof(struct node));
            n = n->next;
            n->getal = QHead->getal;
            QHead = QHead->next;
        }
        temp->head = tempNode;
    }
    return temp;
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