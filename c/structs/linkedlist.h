#ifndef _LINKEDLIST__H_
#define _LINKEDLIST__H_


typedef struct node *link;
struct node
{
    int item;
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

void initList(link h, link t)
{
    list.head = h;
    list.tail = t;

    h->next = t;
    list.count = 1;
}

link genNode(int itemN)
{
    link nn = malloc( sizeof *nn);

    nn->item = itemN;
    nn->next = NULL;

    return nn;
}

//insert node at nth position in the list
int insertNode(link i, int n)
{
    link current = NULL;
    int curCount = 1;
    int r = 0;

    if(n == 0)
    {
	      i->next = list.head;
	      list.head = i;
	      r = 1;
    }
    else 
    {
	      current = list.head;
	      for(curCount; curCount < n; curCount++)
	      {
	         /* if( current->next->next == NULL )
	          {
		            r = -1;
	          }*/
		
	          current = current->next;
	      } 
            
	      i->next = current->next;
	      current->next = i;

	      if( i->next == NULL)
	      {
	          setTail( i );
	      }

	      r = 1;
    }
	    	
    list.count++;

    return r;
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
    while (i != NULL)
    {
        printf("%d\n", i->item);
        i = i->next;
    }
}

void reverseList(link h)
{

  link prev = NULL;
  link current = h;
  link n;

  while (current != NULL)
  {
      n = current->next; 
      current->next = prev;  
      prev = current;
      current = n;
  }

  list.head = prev;

}

#endif
