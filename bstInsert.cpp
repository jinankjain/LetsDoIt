#include <bits/stdc++.h>
using namespace std;
struct node
{
	int val;
	struct node *right, *left;
};

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }
}
struct node* newNode(int val)
{
	struct node *temp = new struct node();
	temp->val = val;
	temp->left = temp->right = NULL;
	return temp;
}
struct node* insert(struct node *root, int value)
{
	if(root==NULL) return newNode(value);
	if(root->val>value)
	{
		root->left = insert(root->left, value);
	}
	else if(root->val<value)
	{
		root->right = insert(root->right, value);
	}
	return root;
}
int main()
{
	struct node *root = new struct node();
	root = NULL;
	root = insert(root, 50);
	insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
  
    // print inoder traversal of the BST
    inorder(root);
	return 0;
}