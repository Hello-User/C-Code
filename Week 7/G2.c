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
void print_list(struct node *head);

int main(){
    struct Queue *q;
    q = (struct Queue *) malloc(sizeof(struct Queue));
    q->head=NULL;
    q->tail=NULL;
    int i;
    for(i=0; i<3; i++){
        voegToe(q, i);
    }
    printf("Address nieuwe queue: %p\n", copy(q));
    q->head = NULL;
}

struct Queue* copy (struct Queue *Q){
    struct Queue *temp;
    temp = (struct Queue*) malloc(sizeof(struct Queue));
    if(Q->head == NULL){ //check if Q exists
        temp->head == NULL;
    }
    else{
        struct node *tempNode = malloc(sizeof(struct node));
        tempNode->getal = Q->head->getal; //create and initialize node
        struct node *QHead = malloc(sizeof(struct node));
        QHead = Q->head; //create node
        struct node *n = malloc(sizeof(struct node));
        n = tempNode; //create new node and assign it memory values of tempNode.
        QHead = QHead->next;
        while(QHead != NULL){ //iterate through Q
            n->next = malloc(sizeof(struct node));
            n = n->next;
            n->getal = QHead->getal;
            QHead = QHead->next;
        }
        temp->head = tempNode; //set new queue head to first node
        temp->tail = n; //set tail to n (last node after iteration)
        n->next=NULL;
    }
    printf("Queue na copy:\n");
    print_list(temp->head);
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

void print_list(struct node *head) {
    struct node * current = head;
    while (current != NULL) {
        printf("%d\n", current->getal);
        current = current->next;
    }
}