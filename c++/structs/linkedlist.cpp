/* linked list library in c++ */
#include<iostream>
#include<cstdlib>
#include<stdio.h>

class linkedList
{
    public:
        struct node
        {
            int item;
            node* next;
        };

    public:
        ~linkedList();
        void clear();
        int insertNode(node*, int);
        void removeNode(node*, node*);
        void reverseList();
        void iterateList();

    private:
        node* head = NULL;
};

linkedList::~linkedList()
{
    clear();
}

void linkedList::clear()
{
    linkedList::node* t = NULL;
    while(t)
    {
        t = head->next;
        delete head;
        head = t;
    }
}

int linkedList::insertNode( linkedList::node* i, int n )
{
    linkedList::node* curr = NULL;
    int curCount = 1;
    int r = 0;

    if(n == 0)
    {
        i->next = head;
        head = i;
        r = 1;
    }
    else
    {
        curr = head;
        for(curCount; curCount < n; curCount++)
        {
            curr = curr->next;
        }
        
        i->next = curr->next;
        curr->next = i;

        r = 1;
    }

    return r;
}


void linkedList::removeNode(linkedList::node* t, linkedList::node* x)
{
    if(x->next)
    {
        t->next->next;
    }
    else
    {
        t->next = NULL;
    }

    delete x;

}

void linkedList::reverseList()
{
    linkedList::node* prev = NULL;
    linkedList::node* curr = head;
    linkedList::node* n;

    while(curr != NULL)
    {
        n = curr->next;
        curr->next = prev;
        prev = curr;
        curr = n;
    }

    head = prev;

}

void linkedList::iterateList()
{
    linkedList::node* i = head;
    while( i != NULL )
    {
        printf("%d\n", i->item);
        i = i->next;
    }
}


int main()
{
    printf("starting LL test\n");
    int x = 1;
    int pos = 0;

    linkedList ll;
    linkedList::node* node1 = new linkedList::node;
    node1->item = x;
    x++;
    if(!ll.insertNode(node1, pos))
    {
        return 0;
    }
    pos++;

    linkedList::node* node2 = new linkedList::node;
    node2->item = x;
    x++;
    if(!ll.insertNode(node2, pos))
    {
        return 0;
    }
    pos++;

    ll.iterateList();
    ll.reverseList();
    ll.iterateList();

}
