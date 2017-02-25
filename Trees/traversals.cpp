#include<iostream>
using namespace std;

typedef struct node {
struct node *left;
struct node *right;
int data;
};

struct node *newNode(int ndata)
{
    node *newptr = new node();
    newptr->data = ndata;
    newptr->left = NULL;
    newptr->right = NULL;

    return newptr;
}

void printPreorder(struct node *pnode)
{
    if(pnode == NULL)
        return;

    cout<<pnode->data;
    printPreorder(pnode->left);
    printPreorder(pnode->right);
}

void printInorder(struct node *pnode)
{
    if(pnode == NULL)
        return;

    printInorder(pnode->left);
    cout<<pnode->data;
    printInorder(pnode->right);
}

void printPostorder(struct node *pnode)
{
    if(pnode == NULL)
        return;

    printPostorder(pnode->left);
    printPostorder(pnode->right);
    cout<<pnode->data;
}

int main(void) //driver program
{
    struct node *root  = newNode(1);
     root->left        = newNode(2);
     root->right       = newNode(3);
     root->left->left  = newNode(4);
     root->left->right = newNode(5);

    cout<<"\nPreorder traversal of binary tree is \n";
     printPreorder(root);

     cout<<"\nInorder traversal of binary tree is \n";
     printInorder(root);

     cout<<"\nPostorder traversal of binary tree is \n";
     printPostorder(root);
     return 0;
}
