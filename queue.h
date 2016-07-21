#include <stdio.h>
#include <string.h>

struct node
{
	int n;
	char * info;
	struct node * next;
};

struct node head;
struct node * rear = &head;
struct node * front = &head;

void enqueue(int n, char * info)
{
	struct node * t = (struct node *) malloc(sizeof(struct node));
	t->n = n;
	t->info = info;
	t->next = NULL;
	rear->next = t;
	rear = t;
}

struct node * dequeue()
{
	struct node * t = front->next;
	if (t == NULL)
	{
		printf("Queue is empty, nothing was dequeued\n");
	}
	front = front->next;
	return t;
}

struct node * peek()
{
	if (front->next == NULL)
	{
		printf("Queue is empty\n");
	}
	return front->next;
}


