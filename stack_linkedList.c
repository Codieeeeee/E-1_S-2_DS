#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
	int data;
	struct stack *link;
};
struct stack *top=NULL;
void choice();
void push(int);
void pop();
void display();
int main()
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
	struct stack *newnode=(struct stack *)malloc(sizeof(struct stack));
	newnode->data=x;
	if (top==NULL){
		newnode->link=NULL;
		top=newnode;
	}
	else{
		newnode->link=top;
		top=newnode;
	}
}
void pop()
{
	if (top==NULL)
		printf("==>STACK IS EMPTY");
	else{
		struct stack *temp=top;
		printf("==>DELETED ELEMENT:%d\n",top->data);
		top=top->link;
		free(temp);
	}
}
void display()
{
	if (top==NULL)
		printf("==>STACK IS EMPTY");
	else{
		struct stack *temp=top; 
		printf("ELEMENTS IN STACK-->");
		while(temp){
			printf("%d  ",temp->data);
			temp=temp->link;
		}
	}
	printf("\n");
}
