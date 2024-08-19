#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct queue{
	int data;
	struct queue *link;
};
struct queue *front=NULL,*rear=NULL;
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
	struct queue *newnode=(struct queue*)malloc(sizeof(struct queue));
	newnode->data=x;
	newnode->link=NULL;
	if(front==NULL || rear==NULL)
		front=rear=newnode;
	else{
		rear->link=newnode;
		rear=newnode;
	}
}
void deque()
{
	struct queue *temp=front;
	if (front==NULL || rear==NULL)
		printf("QUEUE IS EMPTY\n");
	else if(front==rear){
		printf("DELETED ELEMENT:%d\n",front->data);
		rear=front=NULL;
		free(temp);
	}
	else{
		printf("DELETED ELEMENT:%d\n",front->data);
		front=front->link;
		free(temp);
	}
}
void display()
{
	if (front==NULL || rear==NULL)
		printf("QUEUE IS EMPTY");
	else{
		struct queue *temp=front;
		while(temp!=NULL){
			printf("%d  ",temp->data);
			temp=temp->link;
		}
	}
	printf("\n");
}


