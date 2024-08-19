#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	int data;
	struct node *link;
};
struct node* creation();
int count_nodes(struct node*);
void print_data(struct node*);
struct node* delete(struct node *,int num);
void main()
{
	struct node* head=creation();
printf("\nEnter the integer you want to delete:");
int n;scanf("%d",&n);
	delete(head,n);
	print_data(head);
}
struct node* creation()
{
	struct node *head=NULL,*temp=NULL;
	char n='1';
	while (n=='1'){
		struct node *node=(struct node*)malloc(sizeof(struct node));
		printf("Enter data:");scanf("%d",&node->data);
		node->link=NULL;
		if (head==NULL)
			head=temp=node;
		else{
			temp->link=node;
			temp=temp->link;
		}
		printf("Enter 1 to continue or anything to stop");
		n=getch();
		printf("\n");
	}
	print_data(head);
return head;
}
struct node* delete(struct node *head,int num)
{
	struct node *temp=head,*temp1=NULL;
	if(head==NULL)
		printf("Deletion not possible\n");
	else if (num==head->data){
		temp=head;
		head=head->link;
		free(temp);
		return head;
	}
	else{
		temp1=head;temp=head->link;
		while(temp->data!=num && temp!=NULL){
			temp1=temp;
			temp=temp->link;
		}
		temp1->link=temp->link;
		temp->link=NULL;
		free(temp);
	}
	return head;
}
void print_data(struct node *p)
{
	if (p==NULL)
		printf("Linked list is not present\n");
	else{
		while(p!=NULL){
			printf("%d  ",p->data);
			p=p->link;
		}
		printf("\n");
	}
}

