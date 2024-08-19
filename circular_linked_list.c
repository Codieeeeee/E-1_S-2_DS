#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
	int data;
	struct node *link;
};
struct node *tail;
void creation();
void insertion();
void deletion();
void reverse();
void print_data(struct node *);
int length(struct node *);
int main()
{
	creation();
	printf("Length:%d\n",length(tail));
	insertion();
	printf("Length:%d\n",length(tail));
	deletion();
	printf("Length:%d\n",length(tail));
	reverse();
	return 0;
}
void creation()
{
	static struct node *newnode=NULL;char ch;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter data:");
	scanf("%d",&newnode->data);
	if (tail==NULL){
		tail=newnode;
		tail->link=newnode;
	}
	else{
		newnode->link=tail->link;
		tail->link=newnode;
		tail=newnode;
	}
	printf("Press 1 to continue,or anything to stop\n");
	ch=getch();
	if (ch=='1')
		creation();
	else
		print_data(tail);
}
void insertion()
{
	int pos;
	printf("Enter at which position do you want to insert:");
	scanf("%d",&pos);
	if(pos<1 || pos>length(tail)+1 || tail==NULL)
		printf("Not possible\n");
	else{
		struct node *newnode=NULL,*current=tail->link;
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter data:");
		scanf("%d",&newnode->data);
		newnode->link=NULL;
		//At beginning
		if (pos==1){
			newnode->link=tail->link;
			tail->link=newnode;
		}
		//At end
		else if (pos==length(tail)+1){
			newnode->link=tail->link;
			tail->link=newnode;
			tail=newnode;
		}
		else{
			while(pos-1!=1){
				current=current->link;
				pos--;
			}
			newnode->link=current->link;
			current->link=newnode;
		}
	}
	print_data(tail);
}
void deletion()
{
	int pos;struct node *current=NULL,*previous=NULL;
	printf("Enter the position you want to delete:");
	scanf("%d",&pos);
	if(pos<1 || pos>length(tail) || tail==0)
		printf("Not possible\n");
	else if(pos==1){
		current=tail->link;
		tail->link=current->link;
		free(current);
	}
	else if (pos==length(tail)){
		current=tail->link;
		while(current->link!=tail->link){
			previous=current;
			current=current->link;
		}
		previous->link=current->link;
		tail=previous;
		free(current);
	}
	else{
		current=tail->link;
		while(pos!=1){
			previous=current;
			current=current->link;
			pos--;
		}
		previous->link=current->link;
		free(current);
	}
	print_data(tail);
}
void reverse()
{
	if (tail==0)
		printf("Circular linked list is not present\n");
	else{
		struct node *previous=NULL,*current=tail->link,*next=current->link;
		while(current!=tail){
			previous=current;
			current=next;
			next=current->link;
			current->link=previous;
		}
		next->link=current;
		tail=next;
	}
	print_data(tail);
}
void print_data(struct node *tail)
{
	if (tail==NULL)
		printf("Circular linked list is not available");
	else{
		struct node *temp=tail->link;
		do{
			printf("%d  ",temp->data);
			temp=temp->link;
		}while(temp!=tail->link);
	}
	printf("\n");
}
int length(struct node *tail)
{
	if (tail==0)
		return 0;
	else{
		struct node *temp=tail->link;int len=0;
		do{
			len++;
			temp=temp->link;
		}while(temp!=tail->link);
		return len;
	}
}
