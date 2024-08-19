#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	int data;
	struct node *prev;
	struct node *next;
};
struct node *head,*tail;
void creation ();
void insertion();
void deletion();
void reverse(struct node *,struct node *);
void print_data(struct node *);
int length(struct node *);
int main ()
{
	creation ();
	//insertion();
	//print_data(head);
	deletion();
	print_data(head);
	//printf("Length:%d\n",length(head));
	//reverse(head,head->next);
	return 0;
}
void creation ()
{
	static struct node *newnode=NULL;char ch;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter data:");
	scanf("%d",&newnode->data);
	newnode->prev=NULL;newnode->next=NULL;
	if (head==NULL)
		head=tail=newnode;
	else{
		tail->next=newnode;
		newnode->prev=tail;
		tail=newnode;
	}
	printf("Press 1 to continue,or anything to stop\n");
	ch=getch();
	if (ch=='1')
		creation ();
	else
		print_data(head);
}
void insertion()
{
	int pos;struct node *temp=head;
	printf("Enter at which position do you want to insert:");
	scanf("%d",&pos);
	if (head==0 || pos<1 || pos>length(head)+1 )
		printf("Invalid position\n");
	else{
		struct node *newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enter data for the new node:");
		scanf("%d",&newnode->data);
		newnode->next=NULL;newnode->prev=NULL;
		//At beginning
		if (pos==1){
			newnode->next=head;
			head->prev=newnode;
			head=newnode;
		}
		//At end
		else if (pos==length(head)+1){
			newnode->prev=tail;
			tail->next=newnode;
			tail=newnode;
		}
		else{
			while (pos-1!=1){
				temp=temp->next;
				pos--;
			}
			newnode->prev=temp;
			newnode->next=temp->next;
			temp->next=newnode;
			newnode->next->prev=newnode;
		}
	}
}
//void deletion ()
//{
//	int pos;struct node *temp=head;
//	printf("Enter the position you want to delete:");
//	scanf("%d",&pos);
//	if (head==0 || pos<1 || pos>length(head))
//		printf("Invalid position\n");
//	//At beginning
//	else if (pos==1){
//		temp=head;
//		head=head->next;
//		head->prev=NULL;
//		free(temp);
//	}
//	//At end
//	else if (pos==length(head)){
//		temp=tail;
//		tail=tail->prev;
//		tail->next=NULL;
//		free(temp);
//	}
//	else{
//		temp=head;
//		while(pos!=1){
//			temp=temp->next;
//			pos--;
//		}
//		temp->prev->next=temp->next;
//		temp->next->prev=temp->prev;
//		free(temp);
//	}
//}
void deletion ()
{
	int num;struct node *temp=head;
	printf("Enter the integer you want to delete:");
	scanf("%d",&num);
	if (head==NULL)
		printf("Deletion not possible");
	else if (head->data==num){
		temp=head;
		head=head->next;
		head->prev=NULL;
		free(temp);
	}
	//At end
	else if (tail->data==num){
		temp=tail;
		tail=tail->prev;
		tail->next=NULL;
		free(temp);
	}
	else{
		temp=head;
		while(temp->data!=num && temp!=NULL)
			temp=temp->next;
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
		free(temp);
	}
}
void reverse(struct node *current,struct node *nextnode)
{
	current->next=current->prev;
	current->prev=nextnode;
	current=nextnode;
	if (current==NULL){
		current=head;
		head=tail;
		tail=current;
		print_data(head);
	}
	else
		reverse(current,current->next);
}
/*
void reverse()
{
	struct node *temp=head,*temp1=NULL;
	while(temp!=NULL){
		temp1=temp->next;
		temp->next=temp->prev;
		temp->prev=temp1;
		temp=temp->prev;
	}
	temp=head;
	head=tail;
	tail=temp;
}
*/
void print_data(struct node *head)
{
	if (head==NULL)
		printf("Doubly linked list is not present");
	else{
		struct node* temp=head;
		while(temp!=NULL){
			printf("%d  ",temp->data);
			temp=temp->next;
		}
	}
	printf("\n"); 
}
int length(struct node* head)
{
	if (head==tail)
		return 1;
	else{
		struct node *temp=head;int len=0;
		while(temp!=NULL){
			len++;
			temp=temp->next;
		}
		return len;
	}	
}

