#ifndef _BSTREE__H
#define _BSTREE__H


typedef struct node *link;

struct node 
{
    link left;
    link right;
    link parent;
    int key;
} 
node;

struct bstree
{
    link root;
}
bstree


link genNode( int newitem )
{
    link newN = malloc( sizeof( newN ) );
    
    newN->right = NULL;
    newN->left = NULL;
    newN->parent = NULL;
    newN->key = newitem;
}

void insert( link newN )
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



link treeMin( link x )
{
    while( x->left != NULL )
    {
        x = x->left;
    }
    return x;
}

int removeNode( int k )
{
    link f = bstree.root;
    if( f->key == k )
    {
        bstree.root = f->left;
        free(f);
    }
    else
    {
        while( k != f->key )
        {
            if( f->key < k )
            {
                f = f->right;
            }
            else
            {
                f = f->left;
            }
        }

        if( f->left == NULL && f->right == NULL )
        {
            f = NULL;
        }
        else if( f->left && f->right == NULL )
        {
            f = f->left;
        }
        else if( f->right && f->left == NULL )
        {
            f = f->right;
        }
        else if( f->right && f->left )
        {
            f->key = treeMin( f->right )->key;
            free(treeMin( f->right ) );
        }
    }
    return 1;

}





#endif
