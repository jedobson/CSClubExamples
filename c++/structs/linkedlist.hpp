/* linked list library in c++ */
#ifndef _LINKEDLIST__HPP_
#define _LINKEDLIST__HPP_

template <class T>
class linkedList
{
    public:
        struct node
        {
            T item;
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

template <class T>
linkedList<T>::~linkedList()
{
    clear();
}

template <class T>
void linkedList<T>::clear()
{
    linkedList::node* t = NULL;
    while(t)
    {
        t = head->next;
        delete head;
        head = t;
    }
}

template <class T>
int linkedList<T>::insertNode( linkedList::node* i, int n )
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


template <class T>
void linkedList<T>::removeNode(linkedList::node* t, linkedList::node* x)
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

template <class T>
void linkedList<T>::reverseList()
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

template <class T>
void linkedList<T>::iterateList()
{
    linkedList::node* i = head;
    while( i != NULL )
    {
        printf("%d\n", i->item);
        i = i->next;
    }
}

#endif
