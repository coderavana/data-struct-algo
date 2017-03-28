#include<iostream>
#include<stack>
#include<conio.h>

using namespace std;
struct node {                           //declaring the structure for the node
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data){         //making the new node
    node *newPtr = new node();
    newPtr->data = data;
    newPtr->left = NULL;
    newPtr->right = NULL;
    return newPtr;
};

void in_order_wrec(node *root) {
    if(root == NULL) //checking the base condition
        return;
    std::stack <node *>nodeStack;

    node *current_ptr = root;

    while(nodeStack.empty()==false||current_ptr!=NULL) {
     if(current_ptr) {
        nodeStack.push(current_ptr);
        current_ptr = current_ptr->left;
     }
     else {
        current_ptr = nodeStack.top(); // storing the value to be popped
        nodeStack.pop();        //popping done
        cout<<current_ptr->data<<" ";
        current_ptr = current_ptr->right;
     }
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
  in_order_wrec(root);
    return 0;
}
