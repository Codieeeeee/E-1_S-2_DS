#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 7
int deque[size];
int front=-1,rear=-1;
void choice ();
void enqueuefront(int);
void enqueuerear(int);
void dequeuefront();
void dequeuerear();
void display();
int main()
{
    choice();
    return 0;
}
void choice ()
{
	int x;
	printf("1-->Insertion from front\n2-->Insertion from rear\n3-->Deletion from front\n4-->Deletion from rear\n5-->Display\n6-->Exit\n");
	printf("Press on your choice(Example:Press 5 for display):");
	char ch=getche();
    printf("\n");
	switch(ch)
	{
		case '1':
			printf("Enter element to insert:");
			scanf("%d",&x);
			enqueuefront(x);
			break;
        case '2':
			printf("Enter element to insert:");
			scanf("%d",&x);
			enqueuerear(x);
			break;
		case '3':
			dequeuefront();
			break;
        case '4':
			dequeuerear();
			break;
		case '5':
			display();
			break;
		case '6':
			printf("THANK YOU\n");
			break;
		default:
			printf("INVALID CHOICE\n");
	}
	if (ch!='6')
		choice();
}
void enqueuefront(int x)
{
    if ((rear+1)%size==front)
        printf("DEQUE IS FULL\n");
    else if(front==-1 && rear==-1){
        front=rear=0;
        deque[front]=x;
    }
    else if (front==0){
        front=size-1;
        deque[front]=x;
    }
    else
        deque[--front]=x;
}
void enqueuerear(int x)
{
    if ((rear+1)%size==front)
        printf("DEQUE IS FULL\n");
    else if(front==-1 && rear==-1){
        front=rear=0;
        deque[rear]=x;
    }
    else{
        rear=(rear+1)%size;
        deque[rear]=x;
    }
}
void dequeuefront()
{
    if(front==-1 && rear==-1)
        printf("DEQUE IS EMPTY\n");
    else if(front==rear){
        printf("Deleted element:%d\n",deque[front]);
        front=rear=-1;
    }
    else{
        printf("Deleted element:%d\n",deque[front]);
        front=(front+1)%size;
    }
}
void dequeuerear()
{
    if(front==-1 && rear==-1)
        printf("DEQUE IS EMPTY\n");
    else if(front==rear){
        printf("Deleted element:%d\n",deque[rear]);
        front=rear=-1;
    }
    else if(rear==0){
        printf("Deleted element:%d\n",deque[rear]);
        rear=size-1;
    }
    else
        printf("Deleted element:%d\n",deque[rear--]);
}
void display()
{
    if(front==-1 && rear==-1)
        printf("DEQUE IS EMPTY\n");
    else{
        int i=front;
        while(i!=rear){
            printf("%d  ",deque[i]);
            i=(i+1)%size;
        }
        printf("%d\n",deque[i]);
    }
}
