#ifndef DIVY_vector_H
#define DIVY_vector_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct Vector
{
	int* data;
	int  vp;
	int  capacity;
} Vector;

Vector* vector_create (int capacity);
void    vector_push_back (Vector* v, int item);
int     vector_get (Vector* v, int index);
void    vector_set (Vector* v, int index, int value);
int     vector_last (Vector* v);
int     vector_size (const Vector* v);
bool    vector_is_empty (const Vector* v);
void    vector_destroy (Vector* v);

#endif  // DIVY_vector_H
