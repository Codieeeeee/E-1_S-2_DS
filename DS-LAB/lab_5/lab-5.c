#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct process{
	int burst_time;
	struct process *link;
};
struct process *head,*tail;
void creation(int);
void print_processes();
void print();
void sum();
void min_time();
int main()
{
	int p;
	printf("Enter no.of processes:");
	scanf("%d",&p);
	creation(p);
	print();
	min_time();
	sum();
	return 0;
}
void creation(int p)
{
	static struct process *newnode=NULL;int i=1;
	newnode=(struct process *)malloc(sizeof(struct process));
	printf("Enter burst time of p%d:",i++);
	scanf("%d",&newnode->burst_time);
	if (head==NULL){
		head=tail=newnode;
	}
	else{
		tail->link=newnode;
		tail=newnode;
	}
	newnode->link=head;
	if (--p!=0)
		creation(p);
	else
		print_processes(tail);
}
void print_processes()
{
	if (head==NULL)
		printf("Circular linked list is not available");
	else{
		struct process *temp=tail->link;
		do{
			printf("%d  ",temp->burst_time);
			temp=temp->link;
		}while(temp!=head);
	}
	printf("\n");
}
void print()
{
	if (head==NULL)
		printf("There are no processes\n");
	else{
		struct process *temp=head;
		int i=0;
		do{
			printf("p%d:%d\n",++i,temp->burst_time);
			temp=temp->link;
		}while(temp!=head);
		printf("p1:%d\n",temp->burst_time);
	}
}
void min_time()
{
	if (head==NULL)
		printf("There are no processes\n");
	else{
		struct process *temp=head->link;
		int min=head->burst_time,i=2,p=1;
		while (temp!=head){
			if (temp->burst_time<min){
				min=temp->burst_time;
				p=i;
			}
			i++;
			temp=temp->link;
		}
		printf("Shortest process is p%d and it's burst time is %d\n",p,min);
	}
}
void sum()
{
	struct process *temp=head;
	int sum=0;
	do{
		sum+=temp->burst_time;
		temp=temp->link;
	}while(temp!=head);
	printf("Total burst time:%d\n",sum);
}

