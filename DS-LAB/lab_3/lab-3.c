#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct points{
	float x;
	float y;
	struct points *link;
};
struct points *head;
void creation ();
void print(struct points *);
void insert(struct points *);
void print_adjacent(struct points *);
void sort(struct points *);
void del (struct points *);
int main()
{
	creation();
	insert(head);
	print_adjacent(head);
	sort(head);
	del(head);
	return 0;
}
void creation ()
{
	static struct points *newnode=NULL,*temp=NULL;char ch;
	newnode=(struct points *)malloc(sizeof(struct points*));
	printf("Enter x:");
	scanf("%f",&newnode->x);
	printf("Enter y:");
	scanf("%f",&newnode->y);
	newnode->link=NULL;
	if (head==NULL){
		head=temp=newnode;
	}
	else{
		temp->link=newnode;
		temp=temp->link;
	}
	printf("Press 1 to continue,or anything to stop\n");
	ch=getch();
	if (ch=='1')
		creation();
	else
		print(head);
}
void print(struct points *head)
{
	if (head==NULL)
		printf("No points are available");
	else{
		struct points *temp=head;
		while(temp!=NULL){
			printf("(%.2f,%.2f)  ",temp->x,temp->y);
			temp=temp->link;
		}
	}
	printf("\n");
}
void insert(struct points *head)
{
	struct points *newnode,*temp=head;
	newnode=(struct points *)malloc(sizeof(struct points*));
	printf("Enter x:");
	scanf("%f",&newnode->x);
	printf("Enter y:");
	scanf("%f",&newnode->y);
	newnode->link=NULL;
	while(temp!=NULL){
		if ((fabs(temp->x-newnode->x)+fabs(temp->y-newnode->y))<=1){
			newnode->link=temp->link;
			temp->link=newnode;
			break;
		}
		temp=temp->link;
	}
	print(head);
}
void print_adjacent(struct points *head)
{
	struct points *temp1=head,*temp2=NULL;int n=0;
	printf("Adjacent points:\n");
	while (temp1->link!=NULL){
		temp2=temp1->link;
		while (temp2!=NULL){
			if ((fabs(temp1->x-temp2->x)+fabs(temp1->y-temp2->y))<=1){
				printf("(%.2f,%.2f)  (%.2f,%.2f)\n",temp1->x,temp1->y,temp2->x,temp2->y);
				n++;
			}
			temp2=temp2->link;
		}
		temp1=temp1->link;
	}
	if (n==0)
		printf("There are no adjacent points\n");
}
void sort(struct points *head)
{
	struct points *temp1=head,*temp2=head;float temp;
	while(temp1->link!=NULL){
		temp2=head;
		while(temp2->link!=NULL){
			if (temp2->x>temp2->link->x || (temp2->x==temp2->link->x && temp2->y>temp2->link->y)){
				temp=temp2->x;
				temp2->x=temp2->link->x;
				temp2->link->x=temp;
				temp=temp2->y;
				temp2->y=temp2->link->y;
				temp2->link->y=temp;
			}
			temp2=temp2->link;
		}
		temp1=temp1->link;
	}
	printf("After sorting:\n");
	print(head);
}
void del(struct points *head)
{
	struct points *temp1=head,*temp2=NULL;
	while(temp1!=NULL){
		temp2=temp1->link;
		while(temp2!=NULL){
			if ((fabs(temp1->x-temp2->x)+fabs(temp1->y-temp2->y))<=1){
				temp1->link=temp2->link;
				free(temp2);
				temp2=temp1->link;
			}
			else
				temp2=temp2->link;
		}
		temp1=temp1->link;
	}
	printf("After deletion:\n");
	print(head);
}
