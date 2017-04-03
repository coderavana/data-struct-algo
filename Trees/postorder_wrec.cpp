#include<iostream>
#include<stack>
using namespace std;

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node *newNode(int data)
{
	node *newptr = new node();
	newptr->data = data;
	newptr->left = NULL;
	newptr->right = NULL;
	return(newptr);
};

void non_rec_post(node *root)
{
	if(root==NULL)
	return;
	
	node *currNode = new node();
	node *pre = new node();
	
	currNode = NULL;
	pre = NULL;
	
	stack<node *> nodeStack;
	nodeStack.push(root);
	
	while(nodeStack.empty()==false)
	{
		currNode = nodeStack.top();
		// Case 1 : We are moving down the tree
		if(!pre||pre->left==currNode||pre->right==currNode) {
			if(currNode->left)
			nodeStack.push(currNode->left);
			else if(currNode->right)
			nodeStack.push(currNode->right);
			else {		//it is a leaf node
				cout<<currNode->data<<" ";
				nodeStack.pop();
			}
		}
		
		// Case 2 : Moving up tree from left
		
		if(currNode->left == pre) {
			if(currNode->right)
			nodeStack.push(currNode->right);
			else {
				cout<<currNode->data<<" ";
				nodeStack.pop();
			}
		}
		
		// Case 3 : Moving Up the tree from right
		
		if(currNode->right == pre) {
			cout<<currNode->data<<" ";
			nodeStack.pop();
		}	
		
		pre = currNode;
	
	}
}

int main(void)
{
	/* Constructed binary tree is
            10
          /   \
        8      2
      /  \    / \
    3     5  1   0
  */
  node *root = newNode(10);
  root->left        = newNode(8);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left = newNode(1);
  root->right->right = newNode(0);
  non_rec_post(root);
	return 0;
}
