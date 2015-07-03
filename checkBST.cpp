#include <bits/stdc++.h>
using namespace std;
struct node
{
	int value;
	struct node *left, *right;
};

node* newNode(int value)
{
	struct node *temp = new node();
	temp->value = value;
	temp->right = temp->left = NULL;
	return temp;
}
vector<int> inorderTraversal;
void inorder(node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		inorderTraversal.push_back(root->value);
		inorder(root->right);
	}
}
bool isBST()
{
	bool ans = true;
	for(int i=0;i<inorderTraversal.size()-1;i++)
	{
		if(inorderTraversal[i]>=inorderTraversal[i+1])
		{
			ans = false;
			break;
		}
	}
	return ans;
}
int main()
{
	struct node *root = newNode(4);
  	root->left        = newNode(2);
  	root->right       = newNode(5);
  	root->left->left  = newNode(1);
  	root->left->right = newNode(3); 
 	inorder(root);
  	if(isBST())
  	  printf("Is BST");
  	else
  	  printf("Not a BST");
	return 0;
}