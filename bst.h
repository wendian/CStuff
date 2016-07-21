#include <stdio.h>
#include <string.h>

struct t_node
{
	int key;
	int value;
	struct t_node * left;
	struct t_node * right;
};

struct t_node * init_bst(int key, int value)
{
	struct t_node * t = (struct t_node *) malloc(sizeof(struct t_node));
	t->key = key;
	t->value = value;
	t->left = NULL;
	t->right = NULL;
	return t;
}

struct t_node * search_key(struct t_node * root, int key)
{
	struct t_node * here = root;
	while (root != NULL)
	{
		if (key < here->key) here = here->left;
		else if (key > here->key) here = here->right;
		else return here;
	}
	//printf("Key not found\n");
	return NULL;
}

void add(struct t_node * root, int key, int value)
{
	struct t_node * here = root;
	while(1)
	{
		if (key < here->key)
		{
			if (here->left == NULL)
			{
				here->left = init_bst(key, value);
				return;
			}
			else here = here->left;
		}
		else if (key > here->key)
		{
			if (here->right == NULL)
			{
				here->right = init_bst(key, value);
				return;
			}
			else here = here->right;
		}
		else
		{
			here->value = value;
			return;
		}
	}
}

void in_order(struct t_node * root)
{
	if (root != NULL)
	{
		in_order(root->left);
		printf("%d\n", root->value);
		in_order(root->right);
	}
	return;
}