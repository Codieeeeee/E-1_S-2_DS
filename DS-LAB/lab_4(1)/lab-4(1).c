#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct process{
	int pid;
	int pbt;
	int pft;
	int pct;
	struct process *link;
};
struct process *top=NULL,*front=NULL,*rear=NULL;
void push();
void print_process();
void print_queue();
void min_max_pct();
int main()
{
	push();
	print_queue();
	min_max_pct();
	return 0;
}
void push()
{
	struct process *newnode1=(struct process *)malloc(sizeof(struct process));
	struct process *newnode2=(struct process *)malloc(sizeof(struct process));
	printf("Enter PID(Process ID):");
	scanf("%d",&newnode1->pid);
	newnode2->pid=newnode1->pid;
	printf("Enter PBT(Process Begin Time):");
	scanf("%d",&newnode1->pbt);
	newnode2->pbt=newnode1->pbt;
	printf("Enter PFT(Process Finish Time):");
	scanf("%d",&newnode1->pft);
	newnode2->pft=newnode1->pft;
	newnode1->pct=newnode1->pft-newnode1->pbt;
	newnode2->pct=newnode1->pft-newnode1->pbt;
	//For stack
	if (top==NULL){
		newnode1->link=NULL;
		top=newnode1;
	}
	else{
		newnode1->link=top;
		top=newnode1;
	}
	//For queue
	if (front==NULL){
		front=rear=newnode2;
		rear->link=NULL;
	}
	else{
		rear->link=newnode2;
		rear=newnode2;
		rear->link=NULL;
	}
	printf("Press 1 to push,or anything to stop\n");
	char ch=getch();
	if (ch=='1')
		push();
	else
		print_process();
}
void print_process()
{
	if (top==NULL)
		printf("There are no processes\n");
	else{
		printf("---->STACK\n");
		struct process *temp=top;
		while(temp){
			printf("PID: %d\n",temp->pid);
			printf("PBT: %d\n",temp->pbt);
			printf("PFT: %d\n",temp->pft);
			printf("PCT: %d\n\n",temp->pct);
			temp=temp->link;
		}
	}
}
void print_queue()
{
	if (front==NULL)
		printf("There are no processes\n");
	else{
		printf("---->QUEUE:\n");
		struct process *temp=front;
		while(temp){
			printf("PID: %d\n",temp->pid);
			printf("PBT: %d\n",temp->pbt);
			printf("PFT: %d\n",temp->pft);
			printf("PCT: %d\n\n",temp->pct);
			temp=temp->link;
		}
	}
}
void min_max_pct()
{
	struct process *temp=front,*temp1=front,*temp2=front;
	int min=temp->pct,max=temp->pct;
	while(temp){
		if (temp->pct<min){
			min=temp->pct;
			temp1=temp;
		}
		else if(temp->pct>max){
			max=temp->pct;
			temp2=temp;
		}
		temp=temp->link;
	}
	printf("MINIMUM PROCESS:\n");
	printf("PID: %d\n",temp1->pid);
	printf("PBT: %d\n",temp1->pbt);
	printf("PFT: %d\n",temp1->pft);
	printf("PCT: %d\n\n",temp1->pct);
	printf("MAXIMUM PROCESS\n");
	printf("PID: %d\n",temp2->pid);
	printf("PBT: %d\n",temp2->pbt);
	printf("PFT: %d\n",temp2->pft);
	printf("PCT: %d\n\n",temp2->pct);
}
