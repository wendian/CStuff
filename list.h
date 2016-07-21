#include <stdio.h>
#include <string.h>

struct node
{
	int n;
	char * info;
	struct node * next;
};

struct node head;

void push(int n, char * info)
{
	struct node * t = (struct node *) malloc(sizeof(struct node));
	t->n = n;
	t->info = info;
	t->next = head.next;
	head.next = t;
}

struct node * pop()
{
	struct node * t = head.next;
	if (t == NULL)
	{
		printf("List is empty, nothing was popped\n");
	}
	head.next = t->next;
	return t;
}

struct node * peek()
{
	struct node * t = head.next;
	if (t == NULL)
	{
		printf("List is empty\n");
	}
	return t;
}