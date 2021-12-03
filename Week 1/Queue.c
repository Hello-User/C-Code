/*  This program implements a queue as a linked list using pointers.  
	The main function enqueues 10 digits (0-9) in order to the queue,
	and then dequeues and prints them in order.  The queue functions
	could of course be used for a more useful purpose such as a simulation
	although as implemented, the queue only stores int values.  */

#include <stdio.h>			
#include <stdlib.h>				// needed for malloc 

//  data structures for the program:

typedef struct node				// a node in a linked list
{
	int item;					// consists of the int item
	struct node *next;			// and a pointer to the next item in the linked list
};

typedef struct Queue			// the Queue will have a pointer to the front
{								// and a pointer to the rear of the queue
	struct node *front;			// the pointers will equal NULL if the list is empty
	struct node *rear;			// or will point at the same location for a 1-item queue
};

//   function prototypes:

void enqueue(struct Queue *q, int item);	// enqueue item to the rear of q
int dequeue(struct Queue *q);				// dequeue and return the first item of q
int empty(struct Queue *q);					// checks to see if the queue is empty (returns 0) or not (returns 1)


// functions:

void main()
{
	struct Queue *q;			// the queue itself
	int i;						// an int for the data
	q = (struct Queue *) malloc(sizeof(struct Queue));	// allocate the queue
	q->front = NULL;			// initialize the queue's pointers to NULL
	q->rear = NULL;

	for(i=0;i<10;i++)			// just enqueue the first 10 digits 0-9 and then we will dequeue them
		enqueue(q, i);
	while(empty(q)!=0)
	{
		i = dequeue(q);
		printf("%d\n", i);
	}
}

void enqueue(struct Queue *q, int i)	// this function will create a new node storing i and
{										// add it to the rear of the queue
	struct node *temp;
	temp = (struct node *) malloc(sizeof(struct node));
	temp->item = i;
	temp->next = NULL;
	if(empty(q)!=0)						// if the queue is not empty, add it at the rear
	{									// adjusting the last node's next pointer to point
		q->rear->next = temp;			// at it
	}
	else
		q->front = temp;				// otherwise it is the only item, adjust front to point at it
	q->rear = temp;						// in either case point rear at the newly added item

}

int dequeue(struct Queue *q)			// dequeue the next item and return the int value,
{										// deallocating the memory for node
	int temp =-999;						// temp will be the int value, initialize it to -999 in case q is empty
	struct node *temp2;					// temp2 will point at the dequeued node temporarily
	if(empty(q)!=0)						// if there are items in the queue, we can dequeue the first
	{
		temp = q->front->item;			// temp is the number stored there
		temp2 = q->front;				// temp2 points at the node
		q->front = q->front->next;		// reset front to point at the next item in the queue
		free(temp2);					// and deallocate the front node
		if(q->front==NULL) q->rear=NULL; // if the queue is now empty, set rear to NULL also
	}
	else printf("ERROR, Queue empty, cannot dequeue\n");	// if queue was empty, output error message
	return temp;						// return dequeued item or -999 if error
}

int empty(struct Queue *q)			// see if the queue is empty, if so, return 0, else
{									// else return 1
	if(q->front==NULL) return 0;
		else return 1;
}
		