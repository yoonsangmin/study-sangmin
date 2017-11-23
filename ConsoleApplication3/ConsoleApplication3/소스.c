#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* left;
	struct node* right;
}Node;

Node *createNode(int x);
Node *insertNode(Node *root, int x);

int main(void)
{

	return 0;
}

Node *createNode(int x)
{
	Node *temp = NULL;

	temp = (Node *)malloc(sizeof(Node));
	temp->data = x;
	temp->right = NULL;
	temp->left = NULL;

	return temp;
}

Node *insertNode(Node *root, int x)
{
	if(root == NULL)
	{
		root = createNode(x);
		return root;
	}

	else if(x < root->data)
		root->left = insertNode(root->left, x);
	else
		root->right = insertNode(root->right, x);

}