#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "dlist.h"

int main()
{
	struct node * head = init_head();

	int i;
	char a[32];
	strcpy(a, "aaaa");
	for (i = 0; i < 20; i++)
	{
		push_front(head, i, a);
		printf("pushed %d and %s\n", i, a);
		push_back(head, i, a);
		printf("pushed %d and %s\n", i, a);

	}
	struct node * x;
	while (peek_front(head))
	{
		x = pop_back(head);
		printf("%d\n%s\n", x->n, x->info);
		free(x);
		x = pop_front(head);
		printf("%d\n%s\n", x->n, x->info);
		free(x);
	}
	return 0;
}

/*
#include "bst.h"

int main()
{
	int i;
	struct t_node * root = init_bst(5, 100);
	for (i = 0; i < 10; i++) add(root, i, i + 5);
	struct t_node * x = search_key(root, 7);
	printf("%d\n", x->value);
	x = search_key(root, 6);
	printf("%d\n", x->value);
	in_order(root);
	return 0;
}
*/


/*
#include "list.h"
int main()
{
	int i;
	char a[32];
	strcpy(a, "aaaa");
	for (i = 0; i < 20; i++)
	{
		push(i, a);
		printf("pushed %d and %s\n", i, a);
	}
	struct node * x;
	while (peek())
	{
		x = pop();
		printf("%d\n%s\n", x->n, x->info);
		free(x);
	}
	return 0;
}
*/

/*
#include "queue.h"
int main()
{
	int i;
	char a[32];
	strcpy(a, "aaaa");
	for (i = 0; i < 20; i++)
	{
		enqueue(i, a);
		printf("enqueued %d and %s\n", i, a);
	}
	struct node * x;
	while (peek())
	{
		x = dequeue();
		printf("%d\n%s\n", x->n, x->info);
		free(x);
	}
	return 0;
}
*/