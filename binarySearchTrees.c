#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	int data;
	struct node* left;
	struct node* right;
}*root;
void choice();
struct node* newnode(int);
struct node* insertion(struct node*,int);
void deletion(struct node*,int);
void inorder(struct node *);
struct node *deletenode(struct node *,int);
void search(struct node *,int);
int totalNodes(struct node *);
int main()
{
	choice();
	return 0;
}
void choice()
{
	char ch;int data;
	printf("1-Insertion    2-Deletion   3-SEARCH	4-NODES COUNT	5-Display	6-Exit\n");
	printf("Enter your choice:");
	ch=getche();
	printf("\n");
	switch(ch)
	{
		case '1':
			printf("Enter the data to insert:");
			scanf("%d",&data);
			root=insertion(root,data);
			choice();
			break;
		case '2':
			printf("Enter the data to delete:");
			scanf("%d",&data);
			deletenode(root,data);
			choice();
			break;
		case '3':
			printf("Enter value to search:");
			scanf("%d",&data);
			search(root,data);
			choice();
			break;
		case '4':
			printf("Total no.of nodes:%d\n",totalNodes(root));
			choice();
			break;
		case '5':
			printf("IN-ORDER-->");inorder(root);printf("\n");
			choice();
			break;
		case '6':
			printf("------THANKYOU-------\n");
			break;
		default:
			printf("INVALID CHOICE\n\n");
			choice();
	}
}
struct node *newnode(int x)
{
	struct node *node =(struct node *)malloc(sizeof(struct node));
	node->data=x;
	node->left=NULL;
	node->right=NULL;
	return node;
}
struct node* insertion(struct node *root,int x)
{
	if(root==NULL)
		return newnode(x);
	else if(x<=root->data)
		root->left=insertion(root->left,x);
	else if(x>root->data)
		root->right=insertion(root->right,x);
	return root;
}
//void deletion(struct node *temp,int x)
//{
//	struct node *extra1,*extra2,*extra3;
//	if(temp==NULL)
//		printf("Element is not present in the tree\n");
//	else if(temp->left!=NULL && x==temp->left->data)
//	{
//		if(temp->left->left==NULL && temp->left->right==NULL){
//			extra1=temp->left;
//			temp->left=NULL;
//			free(extra1);
//		}
//		else if(temp->left->left==NULL){
//			extra1=temp->left;
//			temp->left=temp->left->right;
//			free(extra1);
//		}
//		else if(temp->left->right==NULL){
//			extra1=temp->left;
//			temp->left=temp->left->left;
//			free(extra1);
//		}
//		else{
//			extra1=temp->left;
//			extra2=extra1;
//			while(extra2->right->right!=NULL)
//				extra2=extra2->right;
//			if(extra2->right->left==NULL){
//				extra1->data=extra2->right->data;
//				extra3=extra2->right;
//				extra2->right=NULL;
//				free(extra3);
//			}
//			else{
//				extra1->data=extra2->right->data;
//				extra3=extra2->right;
//				extra2->right=extra2->right->left;
//				free(extra3);
//			}
//		}
//	}
//	else if(temp->right!=NULL && x==temp->right->data)
//	{
//		if(temp->right->left==NULL && temp->right->right==NULL){
//			extra1=temp->right;
//			temp->right=NULL;
//			free(extra1);
//		}
//		else if(temp->right->left==NULL){
//			extra1=temp->right;
//			temp->right=temp->right->right;
//			free(extra1);
//		}
//		else if(temp->left->right==NULL){
//			extra1=temp->right;
//			temp->right=temp->right->left;
//			free(extra1);
//		}
//		else{
//			extra1=temp->right;
//			extra2=extra1;
//			while(extra2->right->right!=NULL)
//				extra2=extra2->right;
//			if(extra2->right->left==NULL){
//				extra1->data=extra2->right->data;
//				extra3=extra2->right;
//				extra2->right=NULL;
//				free(extra3);
//			}
//			else{
//				extra1->data=extra2->right->data;
//				extra3=extra2->right;
//				extra2->right=extra2->right->left;
//				free(extra3);
//			}
//		}
//	}
//	else
//	{
//		if(x<temp->data)
//			deletion(temp->left,x);
//		else
//			deletion(temp->right,x);
//	}
//}
void inorder(struct node *root)
{
	if (root==NULL)
		return;
	inorder(root->left);
	printf("%d  ",root->data);
	inorder(root->right);
}
struct node* inOrderpredeseccor(struct node* root)
{
	while(root!=NULL && root->right!=NULL)
		root=root->right;
	return root;
}
struct node *deletenode(struct node* root,int key)
{
	struct node *temp;
	if (root==NULL){
		printf("Deletion not possible\n");
		return NULL;
	}
	if (key < root->data)
		root->left=deletenode(root->left,key);
	else if (key > root->data)
		root->right=deletenode(root->right,key);
	else{
		if(root->left==NULL){
			temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL){
			temp=root->left;
			free(root);
			return temp;
		}
		temp=inOrderpredeseccor(root->left);
		root->data=temp->data;
		root->left=deletenode(root->left,temp->data);
	}
	return root;
}
void search(struct node *root,int key)
{
	if(root->data==key)
		printf("Key is present in the tree\n");
	else if(root->left==NULL && root->right==NULL)
		printf("key is not present in the tree\n");
	else if(key<root->data)
		search(root->left,key);
	else
		search(root->right,key);
}
int totalNodes(struct node *root)
{
	if (root==NULL)
		return 0;
	else
		return totalNodes(root->left)+totalNodes(root->right)+1;
}
