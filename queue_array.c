#include<stdio.h>
#include<string.h>
#define size 7
int queue[size];
int front=-1,rear=-1;
void choice();
void enqueue(int);
void dequeue();
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
			enqueue(x);
			break;
		case '2':
			dequeue();
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
void enqueue(int x)
{
	if (rear==size-1)
		printf("QUEUE IS FULL\n");
	else if(front==-1 || rear==-1){
		front=rear=0;
		queue[rear]=x;
	}
	else{
		rear++;
		queue[rear]=x;
	}
}
void dequeue()
{
	if (rear==-1 || front==-1)
		printf("QUEUE IS EMPTY\n");
	else if(rear==front){
		printf("DELETED ELEMENT:%d\n",queue[front]);
		front=rear=-1;
	}
	else{
		printf("DELETED ELEMENT:%d\n",queue[front]);
		front++;
	}
}
void display()
{
	if (front==-1 || rear==-1)
		printf("QUEUE IS EMPTY\n");
	else{
		int i=front;
		printf("ELEMENTS IN QUEUE-->");
		while(i!=rear+1){
			printf("%d  ",queue[i]);
			i++;
		}
	}
	printf("\n");
}

