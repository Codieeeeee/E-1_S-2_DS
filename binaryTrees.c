#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *create();
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);
int main()
{
	struct node *root=NULL;
	root=create();
	printf("IN-ORDER-->");inorder(root);printf("\n");
	printf("PRE-ORDER-->");preorder(root);printf("\n");
	printf("POST-ORDER-->");postorder(root);printf("\n");
	return 0;
}
struct node *create()
{
	int x;
	struct node *newnode=NULL;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter data(-1 for no node):");
	scanf("%d",&x);
	if (x==-1)
		return 0;
	newnode->data=x;
	printf("Enter left child data for %d\n",x);
	newnode->left=create();
	printf("Enter right child data for %d\n",x);
	newnode->right=create();
	return newnode;
}
void inorder(struct node *root)
{
	if (root==NULL)
		return;
	inorder(root->left);
	printf("%d  ",root->data);
	inorder(root->right);
}
void preorder(struct node *root)
{
	if (!root)
		return;
	printf("%d  ",root->data);
	preorder(root->left);
	preorder(root->right);
}
void postorder(struct node *root)
{
	if (root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d  ",root->data);
}
