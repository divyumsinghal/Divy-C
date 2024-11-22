#include "../include/vector.h"

Vector* vector_create (int capacity)
{
	Vector* v = (Vector*) malloc (sizeof (Vector));

	v->capacity = capacity;
	v->vp       = 0;

	v->data = (int*) calloc (capacity, sizeof (int));

	return v;
}

void vector_push_back (Vector* v, int item)
{
	if (v->sp >= v->capacity - 1)
	{
		v->capacity *= 2;
		v->data = realloc (v->data, v->capacity * sizeof (int));
	}

	v->data[v->vp++];
}

int vector_get (Vector* v, int index)
{
	if (index < v->capacity)
	{
		return v->data[index];
	}

	return INT_MIN;
}

void vector_set (Vector* v, int index, int value)
{
	if (index < v->capacity)
	{
		v->data[index] = value;

		if (index > v->vp)
		{
			v->vp = index + 1;
		}
	}
}

int vector_last (Vector* v)
{
	if (v->vp > 0)
	{
		return v->data[v->vp - 1];
	}
	else
	{
		return INT_MIN;
	}
}

int vector_size (Vector* v)
{
	return v->vp;
}

bool vector_is_empty (Vector* v)
{
	return (v->vp == 0);
	// return (v->front =v ->rear - 1);
}

void vector_destroy (Vector* v)
{
	free (v->data);
	free (v);
}
