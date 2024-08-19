#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *left;
	struct node *right;
	int data;
}*root;
int precedence(int);
int getLeastPrecedenceOperator(int[],int,int);
struct node* newnode(int x);
struct node* create(struct node *,int[],int,int);
void postOrder(struct node *);
int main()
{
	int exp[]={40,'*',13,'-',78,'/',12,'+',4,'*',3},i;
	root=create(root,exp,0,sizeof(exp)/4);
	printf("Infix expression: ");
	for (i=0;i<sizeof(exp)/4;i++){
		if (exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/' || exp[i]=='^')
			printf("%c ",exp[i]);
		else
			printf("%d ",exp[i]);
	}
	printf("\n");	
	printf("PostOrder of expression tree: ");postOrder(root);
	return 0;
}
int precedence(int ch)
{
	if (ch=='+')
		return 1;
	else if(ch=='-')
		return 2;
	else if (ch=='*')
		return 3;
	else if(ch=='/')
		return 4;
	else if (ch=='^')
		return 5;
	else
		return 6;
}
int getLeastPrecedenceOperator(int a[],int start,int end)
{
	int least=7,leastIndex=end+1,i,j;
	for (i=start;i<end;i++){
		j=precedence(a[i]);
		if(j<=least){
			least=j;
			leastIndex=i;
		}
	}
	return leastIndex;
}
struct node* newnode(int x)
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->left=NULL;
	newnode->right=NULL;
	newnode->data=x;
	return newnode;
}
struct node* create(struct node *root,int a[],int start,int end)
{
	if (start<end)
	{
		int split=getLeastPrecedenceOperator(a,start,end);
		if (root==NULL)
			root=newnode(a[split]);
		root->left=create(root->left,a,start,split);
		root->right=create(root->right,a,split+1,end);
	}
	return root;
}
void postOrder(struct node *root)
{
	if(root==NULL)
		return;
	postOrder(root->left);
	postOrder(root->right);
	int data=root->data;
	if (data=='+' || data=='-' || data=='*' || data=='/' || data=='^')
		printf("%c ",data);
	else
		printf("%d ",data);
}

