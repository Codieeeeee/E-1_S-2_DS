#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	int data;
	struct node *link;	
};
struct node *head1=NULL,*head2=NULL;
void creation();
void concatination();
void sort();
void print_data(struct node *);
int count_nodes(struct node *);
int main()
{
	creation();
	creation();
	concatination();
	sort();
	return 0;
}
void creation ()
{
	static int i=1;
	static struct node *newnode=NULL,*temp=NULL;char ch;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter data:");
	scanf("%d",&newnode->data);
	newnode->link=NULL;
	if (head1==NULL)//for 1st linked list
		head1=temp=newnode;
	else if(head2==NULL && i!=1)//for 2nd linked list
		head2=temp=newnode;
	else{
		temp->link=newnode;
		temp=newnode;
	}
	printf("Press 1 to continue,or anything to stop\n");
	ch=getch();
	if (ch=='1')
		creation ();
	else{
		printf("Linked list-->");
		if (i==1)
			print_data(head1);
		else
			print_data(head2);
		i++;
	}
}
void concatination(){
	struct node *temp=head1;
	while(temp->link!=NULL)
		temp=temp->link;
	temp->link=head2;
	print_data(head1);
}
/*
//Bubble sort
void sort()
{
	struct node *temp1=head1,*temp2=head1;
	while(temp1!=NULL){
		temp2=head1;
		while(temp2->link!=NULL){
			if (temp2->data>temp2->link->data){
				int temp=temp2->data;
				temp2->data=temp2->link->data;
				temp2->link->data=temp;
			}
			temp2=temp2->link;
		}
		temp1=temp1->link;
	}
	print_data(head1);
}
*/
//Changing links
void sort()
{
	struct node *prev=NULL,*current=head1,*next=current->link;int i=count_nodes(head1);
	while(i!=1){
		prev=NULL;current=head1;next=current->link;
		while(next!=NULL){
			if (current->data>next->data){
				if (prev==NULL){
					current->link=next->link;
					next->link=current;
					head1=next;
				}
				else{
					current->link=next->link;
					next->link=current;
					prev->link=next;
				}	
				prev=next;
				current=current;
				next=current->link;
			}
			else{
				prev=current;
				current=next;
				next=next->link;
			}
		}
		i--;
		print_data(head1);
	}
	printf("AFTER SORTING-->");
	print_data(head1);
}
void print_data(struct node *p)
{
	if (p==NULL)
		printf("Linked list is not present\n");
	else{
		struct node *ptr=p;
		while(ptr!=NULL){
			printf("%d  ",ptr->data);
			ptr=ptr->link;
		}
		printf("\n");
	}
}
int count_nodes(struct node *h)
{
	int count=0;
	if (h==NULL)
		return 0;
	else{
		struct node *ptr=h;
		while (ptr!=NULL){
			count++;
			ptr=ptr->link;
		}
		return count;
	}
}


