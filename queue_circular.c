#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 6
int circ_queue[size],front=-1,rear=-1;
void choice();
void enque(int);
void deque();
void display();
int main()
{
	choice();
	return 0;
}
void choice ()
{
	char ch;int x;
	printf("1-->Insertion(enque)\n2-->Deletion(deque)\n3-->Display\n4-->Exit\n");
	printf("Press on your choice(Example:Press 2 for deletion):\n");
	ch=getch();
	switch(ch)
	{
		case '1':
			printf("Enter element to insert:");
			scanf("%d",&x);
			enque(x);
			break;
		case '2':
			deque();
			break;
		case '3':
			display();
			break;
		case '4':
			printf("THANK YOU\n");
			break;
		default:
			printf("INVALID CHOICE\n");
	}
	if (ch!='4')
		choice();
}
void enque(int x)
{
	if ((rear+1)%size==front)
		printf("QUEUE IS FULL\n");
	else if (front==-1 || rear==-1){
		front=rear=0;
		circ_queue[rear]=x;
	}
	else{
		rear=(rear+1)%size;
		circ_queue[rear]=x;
	}
}
void deque()
{
	if(front==-1 || rear==-1)
		printf("QUEUE IS EMPTY\n");
	else if(rear==front){
		printf("DELETED ELEMENT:%d\n",circ_queue[front]);
		front=rear=-1;
	}
	else{
		printf("DELETED ELEMENT:%d\n",circ_queue[front]);
		front=(front+1)%size;
	}
}
void display()
{
	if(front==rear)
		printf("QUEUE IS EMPTY");
	else{
		int i=front;
		do{
			printf("%d\t",circ_queue[i]);
			i=(i+1)%size;
		}while(i!=(rear+1)%size);
	}
	printf("\n");
}
