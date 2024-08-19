#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int N,idArray[100];
struct node{
	char name[20];
	int id;
	char address[20];
	float cgpi;
	struct node *link;
}*head;
void print_students();
void create(int n)
{
	static struct node *temp;
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	printf("Enter student name:");
	scanf("%s",newnode->name);
	printf("Enter student id:");
	scanf("%d",&newnode->id);
	printf("Enter student address:");
	scanf("%s",newnode->address);
	printf("Enter student cgpi:");
	scanf("%f",&newnode->cgpi);
	newnode->link=NULL;
	idArray[n-1]=newnode->id;
	if(head==NULL)
		head=temp=newnode;
	else{
		temp->link=newnode;
		temp=newnode;
	}
	if(--n!=0)
		create(n);
	else
		print_students();
}
void print_students()
{
	struct node *temp=head;
	while(temp!=NULL)
	{
		printf("\nStudent name:");puts(temp->name);
		printf("Student ID:%d\n",temp->id);
		printf("Student address:");puts(temp->address);
		printf("Student CGPI:%.2f",temp->cgpi);
		printf("\n");
		temp=temp->link;
	}
	printf("\n");
}
void swap(int *p1,int *p2)
{
	int temp=*p1;
	*p1=*p2;
	*p2=temp;
}
int partition(int a[],int start,int end)
{
	int i=start,j=end,pivot=a[start];
	while(i<=j)
	{
		while(a[i]<=pivot)
			i++;
		while(a[j]>pivot)
			j--;
		if(i<j)
			swap(&a[i],&a[j]);
	}
	swap(&a[start],&a[j]);
	return j;
}
void quickSortForId(int a[],int start,int end)
{
	if(start<=end)
	{
		int p=partition(a,start,end);
		quickSortForId(a,start,p-1);
		quickSortForId(a,p+1,end);
	}
}
struct node* idCheck(int id)
{
	struct node *temp=head;
	while(temp!=NULL){
		if (temp->id==id)
			return temp;
		temp=temp->link;
	}
}
void main()
{
	int i;
	printf("Enter no.of students:");
	scanf("%d",&N);
	create(N);
	printf("\nStudents after sorting according to ID numbers:\n");
	quickSortForId(idArray,0,N-1);
	for (i=0;i<N;i++)
	{					
		struct node *temp=idCheck(idArray[i]);
		printf("\nStudent name:");puts(temp->name);
		printf("Student ID:%d\n",temp->id);
		printf("Student address:");puts(temp->address);
		printf("Student CGPI:%.2f",temp->cgpi);
		printf("\n");
	}
}


