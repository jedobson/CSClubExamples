#include <stdio.h>
#include <stdlib.h>


typedef struct node *link;

struct node 
{
    link left;
    link right;
    link parent;
    int item;
} 
node;


link genNode( int newitem )
{
    link new = malloc( sizeof( new ) );
    
    new->item = newitem;
    new->right = NULL;
    new->left = NULL;
    new->parent = NULL;
}

link search( int key, link x )
{
    link r;

    if( x == NULL || x->item == key )
    {
        return x;
    }
    else if( key < x->item )
    {
        r = x->left;   
    }
    else
    {
        r = x->right;
    }

    return search( key, r);
}

link treeMax( link x )
{
    while( x->right != NULL )
    {
        x = x->right;
    }

    return x;
}

link rTreeMax( link x )
{
    if( x->right != NULL )
    {
        return rTreeMax( x->right);
    }
    return x;
}


link treeMin( link x )
{
    while( x->left != NULL )
    {
        x = x->left;
    }
    return x;
}

link rTreeMin( link x )
{
    if (x->left != NULL )
    {
        return rTreeMin( x->left);
    }
    return x;
}

int main() 
{
    printf("test");
}

