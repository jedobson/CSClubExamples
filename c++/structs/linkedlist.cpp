/* linked list library in c++ */
#include<iostream>
#include<cstdlib>

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
        node* genNode(int);
        int insertNode(node*, int);
        void removeNode(node*, node*);
        void reverseList();

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


linkedList::node* linkedList::genNode( int item )
{
    linkedList::node* n = (linkedList::node*)malloc(sizeof *n);
    n->item = item;
    n->next = NULL;

    return n;
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

    free(x);
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


int main(){}
