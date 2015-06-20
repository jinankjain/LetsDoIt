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

node* insert(struct node* root, int value)
{
	if(root==NULL) return newNode(value);
	if(root->value<value)
	{
		root->right = insert(root->right, value);
	}
	else if(root->value>value)
	{
		root->left = insert(root->left, value);
	}

	return root;
}

node* minValueNode(struct node* root)
{
	node* temp = root;
	while(temp->left!=NULL)
	{
		temp = temp->left;
	}
	return temp;
}

void inorder(struct node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->value<<" ";
		inorder(root->right);
	}
}

node* deleteNode(node* root, int value)
{
	if(root==NULL) return root;
	if(root->value>value)
	{
		root->left = deleteNode(root->left, value);
	}
	else if(root->value<value)
	{
		root->right = deleteNode(root->right, value);
	}
	else
	{
		if(root->left==NULL)
		{
			node* temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			node* temp = root->left;
			free(root);
			return temp;
		}
		node* temp = minValueNode(root->right);
		root->value = temp->value;
		root->right = deleteNode(root->right, temp->value);
	}
	return root;
}

int main()
{
	struct node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
 
    root = deleteNode(root, 20);
    root = deleteNode(root, 30);
    root = deleteNode(root, 50);
    inorder(root);
	return 0;
}