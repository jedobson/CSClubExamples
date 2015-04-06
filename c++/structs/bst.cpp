#include <stdio.h>
#include <iostream>

class Bstree 
{
    public:
        struct node
        {
            node* left;
            node* right;
            node* parent;
            int key;
        }
    public:
        ~Bstree();
        void insert(node*, node*);
        node* search( int, x );
        node* treeMax( node* );
        node* treeMin( node* );
        node* remove( node* );

    private:
        node* root = NULL;

};


