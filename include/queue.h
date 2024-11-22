#ifndef DIVY_QUEUE_H
#define DIVY_QUEUE_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct Queue
{
	int* data;
	int  front;
	int  rear;
	int  capacity;
	int  size;
} Queue;

Queue* queue_create (int capacity);
void    queue_enqueue (Queue* q, int item);
int    queue_dequeue (Queue* q);
void   queue_pop (Queue* q);
int    queue_top (Queue* q);
int    queue_size (const Queue* q);
bool   queue_is_empty (const Queue* q);
void   queue_destroy (Queue* q);

#endif  // DIVY_QUEUE_H
