#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct page{
	int pageNo;
	char content[100];
	char keyword[3][20];
	struct page *link;	
}*head;
int length=0;
void pages_creation();
void print_pages(struct page *);
void sort();
void insert();
void delete_dup();
int main()
{
	pages_creation();
	sort();
	insert();
	delete_dup();
	return 0;
}
void pages_creation()
{
	int i=0;
	struct page *newnode=(struct page*)malloc(sizeof(struct page));
	length++;
	printf("Enter page number:");
	scanf("%d",&newnode->pageNo);
	printf("Enter content:");
	scanf("%[^\t]s",newnode->content);
	while (i<3){
		printf("Enter keyword %d:",i+1);
		scanf("%s",&newnode->keyword[i]);
		i++;
	}
	newnode->link=NULL;
	static struct page *temp=NULL;
	if (head==NULL)
		head=temp=newnode;
	else{
		temp->link=newnode;
		temp=newnode;
	}
	char ch;
	printf("Press 1 to continue,or anything to stop\n");
	ch=getch();
	if (ch=='1')
		pages_creation();
	else
		print_pages(head);
}
void print_pages(struct page *head)
{
	struct page *temp=head;
	while(temp){
		printf("CONTENT:");
		puts(temp->content);
		int i=0;
		printf("KEYWORDS:\n");
		while(i<3){
			printf("\t%d.",i+1);
			puts(temp->keyword[i]);
			i++;
		}
		printf("PAGE NUMBER: ");
		printf("%d\n",temp->pageNo);
		temp=temp->link;
	}
	printf("===================================================================\n");
}
void sort()
{
	struct page *prev=NULL,*current=NULL,*next=NULL;
	int i=length;
	while(i!=1){
		prev=NULL;current=head;next=current->link;
		while(next!=NULL){
			if (current->pageNo>next->pageNo){
				current->link=next->link;
				next->link=current;
				if (prev==NULL)
					head=next;
				else
					prev->link=next;
					
				prev=next;
				//current=current;
				next=current->link;
			}
			else{
				prev=current;
				current=prev->link;
				next=current->link;
			}
		}
		i--;
	}
	printf("<<<<<<<<<<-----AFTER SORTING----->>>>>>>>>>\n");
	print_pages(head);
}
void insert()
{
	struct page *newnode=(struct page*)malloc(sizeof(struct page));
	length++;
	printf("Enter page number:");
	scanf("%d",&newnode->pageNo);
	printf("Enter content:");
	scanf("%[^\t]s",newnode->content);
	int i=0;
	while (i<3){
		printf("Enter keyword %d:",i+1);
		scanf("%s",&newnode->keyword[i]);
		i++;
	}
	newnode->link=NULL;
	
	struct page *current=head,*next=current->link;
	if (newnode->pageNo<=current->pageNo){
		newnode->link=head;
		head=newnode;
	}
	else{
		while (newnode->pageNo>next->pageNo){
			current=next;
			next=current->link;
		}
		current->link=newnode;
		newnode->link=next;
	}
	printf("<<<<<<<<<<-----AFTER INSERTING----->>>>>>>>>>\n");
	print_pages(head);
}
void delete_dup()
{
	struct page *prev=head,*current=prev->link,*temp=NULL;
	while(current!=NULL)
	{
		if (current->pageNo==prev->pageNo){
			temp=current;
			prev->link=current->link;
			temp->link=NULL;
			free(temp);
		}
		prev=current;
		current=prev->link;
	}
	printf("<<<<<<<<<<-----AFTER DELETING----->>>>>>>>>>\n");
	print_pages(head);
}
