// set.h: Header file for set

#include <stdbool.h>
#include <stdlib.h>

typedef enum Colour {
	Red,
	Black
} Colour;

typedef struct Node
{
	int          data;
	struct Node* left;
	struct Node* right;
	Colour       node_colour;
} Node;

typedef struct Set
{
	Node* root;
	int   size;
} Set;

Set* set_create ();
void set_insert (Set* s, int data);
void set_delete (Set* s, int data);
bool set_find (const Set* s, int data);
void set_dfs (const Set* s);
int  set_bfs (const Set* s);
int  set_size (const Set* s);
bool set_is_empty (const Set* s);
void set_destroy (Set* s);