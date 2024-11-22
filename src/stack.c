#include "../include/stack.h"

Stack* stack_create (int capacity)
{
	Stack* st = (Stack*) malloc (sizeof (Stack));

	st->capacity = capacity;
	st->sp       = 0;

	st->data = (int*) calloc (capacity, sizeof (int));

	return st;
}

void stack_enstack (Stack* st, int item)
{
	if (st->sp >= st->capacity - 1)
	{
		st->capacity *= 2;
		st->data = realloc (st->data, st->capacity * sizeof (int));
	}

	st->data[st->sp++] = item;
}

int stack_destack (Stack* st)
{
	if (st->sp != 0)
	{
		return (st->data[-- st->sp]);
	}

	return INT_MIN;
}

void stack_pop (Stack* st)
{
	if (st->sp > 0)
	{
		st->sp--;
	}
	return -1;
}

int stack_top (Stack* st)
{
	if (st->sp != 0)
		return (st->data[st->sp - 1]);
}

int stack_size (Stack* st)
{
	return st->sp;
}

bool stack_is_empty (Stack* st)
{
	return (st->sp == 0);
	// return (st->front =st ->rear - 1);
}

void stack_destroy (Stack* st)
{
	free (st->data);
	free (st);
}
