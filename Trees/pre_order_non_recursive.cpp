
#include <iostream>
#include <stack>

using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
    node* newptr = new node();
    newptr->data = data;
    newptr->left = NULL;
    newptr->right = NULL;
    return(newptr);
};

void non_rec_pre(node *root)
{
    if (root == NULL)
       return;

    stack<node *> nodeStack;
    nodeStack.push(root);

    while (nodeStack.empty() == false)
    {
        node *newptr = nodeStack.top();
        cout<<newptr->data<<" ";
        nodeStack.pop();

        if (newptr->right)
            nodeStack.push(newptr->right);
        if (newptr->left)
            nodeStack.push(newptr->left);
    }
}
int main(void)
{
    /* Constructed binary tree is
            10
          /   \
        8      2
      /  \    / \
    3     5  1   1
  */
  node *root = newNode(10);
  root->left        = newNode(8);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left = newNode(1);
  root->right->right = newNode(1);
  non_rec_pre(root);
  return 0;
}
