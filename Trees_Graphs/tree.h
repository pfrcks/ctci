#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <list>
#include <iostream>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
    struct node* nd = (struct node*)malloc(sizeof(struct node));
    nd->data = data;
    nd->left = NULL;
    nd->right = NULL;
    return nd;
}

void printInorder(struct node* tree)
{
    if(tree == NULL)
        return;
    printInorder(tree->left);
    printf("%d ", tree->data);
    printInorder(tree->right);
}

void printLevelOrder(struct node* tree)
{
    std::list<struct node*> queue;
    struct node* tmp = tree;
    while(tmp)
    {
        std::cout << tmp->data;
        if(tmp->left)
            queue.push_back(tmp->left);
        if(tmp->right)
            queue.push_back(tmp->right);
        tmp = queue.front();
        queue.pop_front();
    }
}

struct node* bstSearch(struct node* tree, int data)
{
    if(tree == NULL)
        return NULL;
    if(tree->data == data)
        return tree;
    if(tree->data < data)
        return bstSearch(tree->right, data);
    else
        return bstSearch(tree->left, data);
}

int isBST(struct node* tree, int min, int max)
{
    if(tree==NULL)
        return 1;
    if(tree->data < min || tree->data > max)
        return 0;
    return isBST(tree->left, min, tree->data -1) &&
        isBST(tree->right, tree->data+1, max);
}

int checkBST(struct node* tree)
{
    return isBST(tree, INT_MIN, INT_MAX);
}

struct node* insertBST(struct node* tree, int data)
{
    if(tree==NULL)
        return newNode(data);
    if(tree->data > data)
        tree->left = insertBST(tree->left, data);
    else if(tree->data < data)
        tree->right = insertBST(tree->right, data);

    return tree;
}

