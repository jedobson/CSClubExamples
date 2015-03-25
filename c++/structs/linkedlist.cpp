/* linked list library in c++ */
#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include"linkedlist.hpp"


int main()
{
    printf("starting LL test\n");
    int x = 1;
    int pos = 0;

    linkedList<int> ll;
    linkedList<int>::node* node1 = new linkedList<int>::node;
    node1->item = x;
    x++;
    if(!ll.insertNode(node1, pos))
    {
        return 0;
    }
    pos++;

    linkedList<int>::node* node2 = new linkedList<int>::node;
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
