#include "../include/set.h"

Set* set_create ()
{
	Set* New = (Set*) malloc (sizeof (Set));

	New->root = NULL;
	New->size = 0;

	return New;
}

Node* create_node (int data)
{
	Node* new_node = (Node*) malloc (sizeof (Node));
	new_node->data = data;
	new_node->left = new_node->right = NULL;
	new_node->node_colour            = Red;
	return new_node;
}

Node* rotate_left (Node* root)
{
	Node* new_root = root->right;
	root->right    = new_root->left;
	new_root->left = root;
	return new_root;
}

Node* rotate_right (Node* root)
{
	Node* new_root  = root->left;
	root->left      = new_root->right;
	new_root->right = root;
	return new_root;
}

Node* fix_insert (Node* root)
{
	if (root->node_colour == Red && root->left && root->left->node_colour == Red)
	{
		root = rotate_right (root);
	}
	if (root->right && root->right->node_colour == Red && root->right->left && root->right->left->node_colour == Red)
	{
		root = rotate_left (root);
	}
	return root;
}

Node* insert (Node* root, int data)
{
	if (!root) return create_node (data);

	if (data < root->data)
		root->left = insert (root->left, data);
	else if (data > root->data)
		root->right = insert (root->right, data);

	root = fix_insert (root);

	return root;
}

void set_insert (Set* s, int data)
{
	if (!s) return;

	s->root              = insert (s->root, data);
	s->root->node_colour = Black;
	s->size++;
}
void set_delete (Set* s, int data)
{
}

bool set_find (const Set* s, int data)
{
	bool found = false;

	Node* finder = s->root;

	while (finder != NULL)
	{
		if (finder->data == data)
			return true;
		else if (finder->data < data)
		{
			finder = finder->right;
		}
		else if (finder->data > data)
		{
			finder = finder->left;
		}
	}

	return false;
}

void node_dfs (const Node* n)
{
	if (n != NULL)
	{
		node_dfs (n->left);
		printf ("%c \n", n->data);
		node_dfs (n->right);
	}
}

void set_dfs (const Set* s)
{
	printf ("DFS: \n");
	node_dfs (s->root);
	printf ("End of Dfs \n");
}

int set_bfs (const Set* s)
{
	printf ("BFS: \n");

	if (!s->root)
	{
		return;
	}

	Node** queue = (Node**) malloc (100 * sizeof (Node*));
	int    front = 0;
	int    rear  = 0;

	queue[rear++] = s->root;

	while (front < rear)
	{
		Node* current = queue[front++];

		printf ("%d ", current->data);

		queue[rear++] = current->left;
		queue[rear++] = current->right;
	}

	// Free the queue
	free (queue);

	printf ("End of Bfs \n");
}

int set_size (const Set* s)
{
	return s->size;
}

bool set_is_empty (const Set* s)
{
	return (s->size == 0);
}

void node_del (const Node* n)
{
	if (n != NULL)
	{
		node_del (n->left);
		node_del (n->right);
		printf ("Deleting: %c \n", n->data);
		free (n);
	}
}

void set_destroy (Set* s)
{
	printf ("Delete: \n");
	node_del (s->root);
	printf ("End of Deletion \n");
}