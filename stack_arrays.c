#include<stdio.h>
#include<string.h>
#define size 7
int stack[size],top=-1;
void choice();
void push(int);
void pop();
void display();
int main ()
{
	choice();
	return 0;
}
void choice ()
{
	char ch;int x;
	printf("1-->Insertion(push)\n2-->Deletion(pop)\n3-->Display\n4-->Exit\n");
	printf("Press on your choice(Example:Press 2 for deletion):\n");
	ch=getch();
	switch(ch)
	{
		case '1':
			printf("Enter element to insert:");
			scanf("%d",&x);
			push(x);
			break;
		case '2':
			pop();
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
void push(int x)
{
	if(top==size-1)
		printf("==>STACK IS FULL\n");
	else{
		top++;
		stack[top]=x;
	}
}
void pop()
{
	if (top==-1)
		printf("==>STACK IS EMPTY\n");
	else{
		printf("==>DELETED ELEMENT:%d\n",stack[top]);
		top--;
	}
}
void display()
{
	if (top==-1)
		printf("==>STACK IS EMPTY");
	else{
		int i;
		printf("==>ELEMENTS IN STACK-->");
		for (i=top;i>=0;i--)
			printf("%d  ",stack[i]);
	}
	printf("\n");
}
