#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 7
int s1[size],s2[size];
int top1=-1,top2=-1;
int count=0;
void choice ();
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
void push1(int a)
{
	s1[++top1]=a;
}
void enqueue(int x)
{
	if (top1==size-1)
		printf("QUEUE IS FULL\n");
	else{
		push1(x);
		count++;
	}
}
int pop1()
{
	return s1[top1--];
}
void push2(int a)
{
	s2[++top2]=a;
}
int pop2()
{
	return s2[top2--];
}
void dequeue()
{
	if (count==0)
		printf("QUEUE IS EMPTY\n");
	else{
		int i;
		for (i=0;i<count;i++)
			push2(pop1());
		printf("DELETED ELEMENT:%d\n",pop2());
		count--;
		for (i=0;i<count;i++)
			push1(pop2());
	}
}
void display()
{
	if (count==0)
		printf("QUEUE IS EMPTY");
	else{
		int i;
		for (i=0;i<count;i++)
			printf("%d  ",s1[i]);
	}
	printf("\n");
}

