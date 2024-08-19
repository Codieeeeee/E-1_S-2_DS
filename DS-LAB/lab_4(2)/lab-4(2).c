#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student{
	int id;
	struct student *link;
}*head;
int length=0;
void create();
void print();
void print_n(int);
void delete_n(int);
void pal();
int main()
{
	create();
	int n;
	printf("Enter n:");
	scanf("%d",&n);
	if (n<1 || n>length)
		printf("%d number of nodes not present\n",n);
	else{
		print_n(n);
		delete_n(n);
	}
	pal();
	return 0;
}
void create()
{
	struct student *node=(struct student*)malloc(sizeof(struct student));
	length++;
	printf("Enter ID:");
	scanf("%d",&node->id);
	node->link=NULL;
	static struct student *temp;
	if (head==NULL){
		head=temp=node;
	}
	else{
		temp->link=node;
		temp=temp->link;
	}
	printf("Press 1 to continue,or anything to stop\n");
	char ch=getch();
	if (ch=='1')
		create();
	else
		print();
}
void print()
{
	if (head==NULL)
		printf("Linked list is not present\n");
	else{
		struct student *ptr=head;
		while(ptr!=NULL){
			printf("%d  ",ptr->id);
			ptr=ptr->link;
		}
		printf("\n");
	}
}
void print_n(int n)
{
	struct student *temp=head;
	int i=length-n;
	while(i!=0){
		temp=temp->link;
		i--;
	}
	printf("Data of node %d from last:%d\n",n,temp->id);
}
void delete_n(int n)
{
	struct student *temp=head,*ptr=NULL;
	int i=length-n;
	if (i==0){
		head=temp->link;
		free(temp);
	}
	else{
		while(i!=1){
			temp=temp->link;
			i--;
		}
		ptr=temp->link;
		temp->link=ptr->link;
		free(ptr);
	}
	printf("After deleting node %d from last:\n",n);
	print();
}
void pal()
{
	struct student *temp=head;int n,rem,rev,t=0;
	while(temp){
		n=temp->id,rem=0,rev=0;
		while(n){
			rem=n%10;
			rev=rev*10+rem;
			n=n/10;
		}
		if (rev==temp->id){
			if (t==0)
				printf("Palindrome ID students data:\n");
			printf("%d  ",temp->id);
			t++;
		}
		temp=temp->link;
	}
	if (t==0)
		printf("There are no students with palindrome ID's\n");
}
