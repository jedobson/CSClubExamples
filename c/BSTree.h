#ifndef _BSTREE__H
#define _BSTREE__H
#include <stdio.h>


typedef struct node *link;

struct node 
{
    link left;
    link right;
    link parent;
    int item;
    int key;
} 
node;


link genNode( int newitem )
{
    link newN = malloc( sizeof( newN ) );
    
    newN->item = newitem;
    newN->right = NULL;
    newN->left = NULL;
    newN->parent = NULL;
    newN->key = NULL;
}

void insert( link root, link newN )
{

    if( root->key > newN->key )
    {
        if ( !root->left )
        {
            root->left = newN;
            newN->parent = root;
        }
        else 
        {
            insert( root->left, newN );
        }
    }

    else if( root->key < newN->key )
    {
        if( !root->right )
        {
            root->right = newN;
            newN->parent = root;
        }
        else
        {
            insert( root->right, newN );
        }
    }

}

link search( int key, link x )
{
    link r;

    if( x == NULL || x->key == key )
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

    search( key, r);
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
        rTreeMax( x->right);
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
        rTreeMin( x->left);
    }
    return x;
}

#endif
