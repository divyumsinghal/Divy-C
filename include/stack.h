#ifndef DIVY_stack_H
#define DIVY_stack_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct Stack
{
	int* data;
	int  sp;
	int  capacity;
} Stack;

Stack* stack_create (int capacity);
void   stack_enstack (Stack* st, int item);
int    stack_destack (Stack* st);
void   stack_pop (Stack* st);
int    stack_top (Stack* st);
int    stack_size (const Stack* st);
bool   stack_is_empty (const Stack* st);
void   stack_destroy (Stack* st);

#endif  // DIVY_stack_H
