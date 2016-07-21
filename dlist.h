#include <stdio.h>
#include <string.h>

struct node
{
	int n;
	char * info;
	struct node * next;
	struct node * prev;
};

struct node * init_head()
{
	struct node * t = (struct node *) malloc(sizeof(struct node));
	t->next = t;
	t->prev = t;
	return t;
}

void push_front(struct node * head, int n, char * info)
{
	struct node * t = (struct node *) malloc(sizeof(struct node));
	struct node * hnext = head->next;
	t->n = n;
	t->info = info;
	hnext->prev = t;
	head->next = t;
	t->next = hnext;
	t->prev = head;
}

void push_back(struct node * head, int n, char * info)
{
	struct node * t = (struct node *) malloc(sizeof(struct node));
	struct node * hprev = head->prev;
	t->n = n;
	t->info = info;
	hprev->next = t;
	head->prev = t;
	t->next = head;
	t->prev = hprev;
}

struct node * pop_front(struct node * head)
{
	struct node * t = head->next;
	struct node * tnext = t->next;
	if (t == head)
	{
		printf("List is empty\n");
	}
	tnext->prev = head;
	head->next = tnext;
	t->next = NULL;
	t->prev = NULL;
	return t;
}

struct node * pop_back(struct node * head)
{
	struct node * t = head->prev;
	struct node * tprev = t->prev;
	if (t == head)
	{
		printf("List is empty\n");
	}
	tprev->next = head;
	head->prev = tprev;
	t->next = NULL;
	t->prev = NULL;
	return t;
}

struct node * peek_front(struct node * head)
{
	struct node * t = head->next;
	if (t == head)
	{
		printf("List is empty\n");
		t = NULL;
	}
	return t;
}

struct node * peek_back(struct node * head)
{
	struct node * t = head->prev;
	if (t == head)
	{
		printf("List is empty\n");
		t = NULL;
	}
	return t;
}