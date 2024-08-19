#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char week[][10]={"sunday","monday","tuesday","wednesday","thursday","friday","saturday"};
char year[][10]={"JANUARY","FEBRUARY","MARCH","APRIL","MAY","JUNE","JULY","AUGUST","SEPTEMBER","OCTOBER","NOVEMBER","DECEMBER"};
struct days{
	char day[10];
	struct days *link;
}*head;
struct months{
	char month[10];
	struct months *link;
}*start;
void printDays()
{
	printf("If you want to know today press 1 or else press anything:");
	char ch=getch();
	static struct days *ptr=NULL;
	if (ch=='1'){
		if (ptr==NULL)
			ptr=head;
		puts(ptr->day);
		ptr=ptr->link;
		printDays();
	}
}
void Week()
{
	static int i=0;
	struct days* newnode=(struct days *)malloc(sizeof(struct days));
	static struct days*temp=NULL;
	strcpy(newnode->day,strupr(week[i]));
	if (head==NULL)
		head=temp=newnode;
	else{
		temp->link=newnode;
		temp=newnode;
	}
	i++;
	if(i!=7)
		Week();
	else{
		newnode->link=head;
		printDays();
	}
}
void printMonths()
{
	printf("If you want to know month press 1 or else press anything:");
	char ch=getch();
	static struct months *ptr=NULL;
	if (ch=='1'){
		if (ptr==NULL)
			ptr=start;
		puts(ptr->month);
		ptr=ptr->link;
		printMonths();
	}
}
void Year()
{
	static int i=0;
	struct months* newnode=(struct months *)malloc(sizeof(struct months));
	static struct months*temp=NULL;
	strcpy(newnode->month,year[i]);
	if (start==NULL)
		start=temp=newnode;
	else{
		temp->link=newnode;
		temp=newnode;
	}
	i++;
	if(i!=12)
		Year();
	else{
		newnode->link=start;
		printMonths();
	}
}
void printDayUsingArray()
{
	printf("If you want to know today press 1 or else press anything:");
	char ch=getch();
	static int i=0;
	if (ch=='1')
	{
		puts(week[i]);
		i=(i+1)%7;
		printDayUsingArray();
	}
	else
		i=0;
}
void printMonthUsingArray()
{
	printf("If you want to know month press 1 or else press anything:");
	char ch=getch();
	static int i=0;
	if (ch=='1')
	{
		puts(year[i]);
		i=(i+1)%12;
		printMonthUsingArray();
	}
	else
		i=0;
}
int main()
{
	printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<DAYS USING CIRCULAR LINKED LIST>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	Week();
	printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<MONTHS USING CIRCULAR LINKED LIST>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	Year();
	printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<DAYS USING CIRCULAR ARRAY>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	printDayUsingArray();
	printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<MONTHS USING CIRCULAR LINKED LIST>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	printMonthUsingArray();
	return 0;
}
