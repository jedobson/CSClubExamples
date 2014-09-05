#ifndef _LINKEDLIST__H_
#define _LINKEDLIST__H_

#include <stdio.h>

typedef struct node *link;

struct node
{
    void* item;
    link next;
}
node;

struct list
{
    link head;
    link tail;
    int count;
}
list;

void setHead(link h)
{
    list.head = h;
}

void setTail(link t)
{
    list.tail = t;
}

void initList()
{
    link h = list.head;
    link t = list.tail;

    h->next = t;
}

link genNode(void *itemN)
{
    link nn = malloc( sizeof *nn);

    nn->item = itemN;

    return nn;
}

void insertNode(link t, link x, link y)
{
    t->next = x;
    x->next = y;
    list.count++;
}

void removeNode(link t, link x)
{
    if (x->next)
    {
        t->next->next;
    }
    else
    {
        t->next = NULL;
    }

    list.count--;
    free(x);
}

void removeHead(link t)
{
    list.head = t->next;
    free(t);
}

void iterateList()
{
    link i = list.head;
    while (i->next)
    {
        printf("%d\n", i->item);
        i = i->next;
    }
}

#endif












