#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct cse{
	char name[11];
	char id[8];
	int roll;
	struct cse *link;
};
struct cse *head=NULL;
void creation();
void sort();
void print_data(struct cse *);
int count_nodes(struct cse *);
int main()
{
	creation();
	sort();
	return 0;
}
void creation ()
{
	static struct cse *newnode=NULL,*temp=NULL;char ch;
	newnode=(struct cse*)malloc(sizeof(struct cse));
	printf("Enter name(Maximum 10 characters):");
	scanf("%s",&newnode->name);
	printf("Enter ID(Maximum 7 characters):");
	scanf("%s",&newnode->id);
	printf("Enter roll.no:");
	scanf("%d",&newnode->roll);
	newnode->link=NULL;
	if (head==NULL)//for 1st linked list
		head=temp=newnode;
	else{
		temp->link=newnode;
		temp=newnode;
	}
	printf("Press 1 to continue,or anything to stop\n");
	ch=getch();
	if (ch=='1')
		creation ();
	else{
		printf("--->BEFORE SORTING:\n");
		print_data(head);
	}
}
/*
void sort()
{
	struct cse *temp1=head,*temp2=head;
	while(temp1!=NULL){
		temp2=head;
		while(temp2->link!=NULL){
			if (temp2->roll>temp2->link->roll){
				int roll_temp=temp2->roll;
				temp2->roll=temp2->link->roll;
				temp2->link->roll=roll_temp;
				//name swapping
				char name_temp[11];
				strcpy(name_temp,temp2->name);
				int i=0;
				while(temp2->link->name[i]!='\0'){
					temp2->name[i]=temp2->link->name[i];
					i++;
				}
				temp2->name[i]='\0';
				i=0;
				while(name_temp[i]!='\0'){
					temp2->link->name[i]=name_temp[i];
					i++;
				}
				temp2->link->name[i]='\0';
				//id swapping
				char id_temp[8];
				strcpy(id_temp,temp2->id);
				i=0;
				while(temp2->link->id[i]!='\0'){
					temp2->id[i]=temp2->link->id[i];
					i++;
				}
				temp2->id[i]='\0';
				i=0;
				while(id_temp[i]!='\0'){
					temp2->link->id[i]=id_temp[i];
					i++;
				}
				temp2->link->id[i]='\0';
			}
			temp2=temp2->link;
		}
		temp1=temp1->link;
	}
	printf("--->AFTER SORTING:\n");
	print_data(head);
}
*/
void sort()
{
	struct cse *prev=NULL,*current=NULL,*next=NULL;int i=count_nodes(head);
	while(i!=1){
		prev=NULL;current=head;next=current->link;
		while(next!=NULL){
			if (current->roll>next->roll){
				if (prev==NULL){
					current->link=next->link;
					next->link=current;
					head=next;
				}
				else{
					current->link=next->link;
					next->link=current;
					prev->link=next;
				}	
				prev=next;
				current=current;
				next=current->link;
			}
			else{
				prev=current;
				current=next;
				next=current->link;
			}
		}
		i--;
	}
	printf("AFTER SORTING-->\n");
	print_data(head);
}
void print_data(struct cse *head)
{
	if (head==NULL)
		printf("There is no data\n");
	else{
		struct cse *temp=head;
		while(temp!=NULL){
			printf("NAME:%s\n",temp->name);
			printf("ID:%s\n",temp->id);
			printf("ROLL.NO:%d\n\n",temp->roll);
			temp=temp->link;
		}
	}
}
int count_nodes(struct cse *h)
{
	int count=0;
	if (h==NULL)
		return 0;
	else{
		struct cse *ptr=h;
		while (ptr!=NULL){
			count++;
			ptr=ptr->link;
		}
		return count;
	}
}

