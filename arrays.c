#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void choice();
void insertion();
void searching();
void deletion();
int n,*a;
void main()
{
	int i;
	printf("Enter no.of elements:");
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	for (i=0;i<n;i++){
		printf("Enter element %d:",i+1);
		scanf("%d",a+i);
		//a=(int*)realloc(a,sizeof(int));
	}
	printf("Array-->");
	for (i=0;i<n;i++){
		printf("%d  ",*a+i);
	}
	choice();
}
void choice()
{
	char op;
	printf("\n\n1-->Searching\n2-->Insertion\n3-->Deletion\n4-->Exit\n");
	printf("Enter which operation do you want to perform:");
	scanf("%s",&op);
	if (op<'1' || op>'4'){
		printf("Entered operation is invalid\n");
		choice();
	}
	else {
		if (op=='1')
			searching();
		else if (op=='2')
			insertion();
		else if (op=='3')
			deletion();
		else
			printf("Thank you%c%c",1,2);
	}
}
void searching()
{
	int ele,i,c=0;
	printf("Enter the element you want to search:");
	scanf("%d",&ele);
	for (i=0;i<n;i++){
		if(a[i]==ele){
			printf("Element found at index position %d\n",i);
			c++;
			break;
		}
	}
	if (c==0)
		printf("Element is not present in the array\n");
	choice();
}
void insertion()
{
	int ele,ind,i;
	printf("Enter the element you want to insert:");
	scanf("%d",&ele);
	printf("Enter the index position where you want to insert the element:");
	scanf("%d",&ind);
	if (ind<0 || ind>n)
		printf("Insertion not possible\n");
	else
	{
		a=(int*)realloc(a,sizeof(int));
		for (i=n-1;i>=ind;i--){
			a[i+1]=a[i];
		}
		a[ind]=ele;
		n=n+1;
		for (i=0;i<n;i++)
			printf("%d  ",a[i]);
	}
	choice();
}
void deletion()
{
	int ele,c=0,i;
	printf("Enter the element you want to delete:");
	scanf("%d",&ele);
	for (i=0;i<n;i++){
		if (a[i]==ele){
			c=i;
			break;
		}
	}
	if (c==0)
		printf("Entered element is not present in the array\n");
	else{
		for (i=c;i<n;i++)
			a[i]=a[i+1];
		n=n-1;
		for (i=0;i<n;i++){
			printf("%d  ",a[i]);	
		}
	}
	choice();
}
