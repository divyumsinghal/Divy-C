#include "../include/queue.h"

Queue* queue_create (int capacity)
{
	Queue* q = (Queue*) malloc (sizeof (Queue));

	q->capacity = capacity;
	q->front    = -1;
	q->rear     = 0;
	q->size     = 0;

	q->data = (int*) calloc (capacity, sizeof (int));

	return q;
}

void queue_enqueue (Queue* q, int item)
{
	if (q->rear >= q->capacity - 1)
	{
		if (q->front < q->capacity / 2)
		{
			q->capacity *= 2;
			q->data = realloc (q->data, q->capacity * sizeof (int));
		}

		for (int i = 0; i < q->rear - q->front; i++)
		{
			q->data[i] = q->data[i + q->front];
		}

		q->rear -= q->front;
		q->front = 0;
	}

	q->data[q->rear++] = item;

	if (queue_is_empty (q))
		q->front++;

	q->size++;
}

int queue_dequeue (Queue* q)
{
	if (q->size != 0)
	{
		q->size--;

		int top = q->data[q->front++];

		if (q->size == 0)
		{
			q->front = -1;
			q->rear  = 0;
		}

		return (top);
	}

	return INT_MIN;
}

void queue_pop (Queue* q)
{
	if (q->size > 0)
	{
		q->size--;
		q->front++;
	}
	return -1;
}

int queue_top (Queue* q)
{
	if (q->front != -1)
		return (q->data[q->front]);
}

int queue_size (Queue* q)
{
	return q->size;
}

bool queue_is_empty (Queue* q)
{
	return (q->size == 0);
	// return (q->front = q->rear - 1);
}

void queue_destroy (Queue* q)
{
	free (q->data);
	free (q);
}
