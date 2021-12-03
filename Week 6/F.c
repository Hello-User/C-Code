#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//int isLeeg(struct Queue Q);
//void print_list(node_t * head);

int main(){
    typedef struct Node{
        int getal;
        struct Node* next;
    }node_t;
    struct Queue{
        struct Node* head;
        struct Node* tail;
    } Queues;
    node_t *head = NULL;
    head = (node_t *) malloc(sizeof(node_t));
    if (head == NULL){
        return 1;
    }
    head->getal = 15;
    head->next = (node_t *) malloc(sizeof(node_t));
    head->next->getal = 30;
    head->next->next = (node_t *) malloc(sizeof(node_t));
    head->next->next->getal = 10;
    head->next->next->next= NULL;

    void print_list(node_t *head) {
        node_t * current = head;

        while (current != NULL) {
            printf("%d\n", current->getal);
            current = current->next;
        }
    }
    print_list(head);
}