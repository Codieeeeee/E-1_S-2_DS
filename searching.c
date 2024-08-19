#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int linearSearch(int a[],int key,int n)
{
	static int i=0;
	if (i==n)
		return -1;
	else if (a[i]==key)
		return i;
	i++;
	linearSearch(a,key,n);
	
}
int binarySearch(int a[],int key,int start,int end)
{
	int mid=(start+end)/2;
	if(a[mid]==key)
		return mid;
	else if(key<a[mid])
		end=mid-1;
	else
		start=mid+1;
	if(start>end)
		return -1;
	binarySearch(a,key,start,end);
}
void choice()
{
	int n,i;
	printf("Enter no.of elements in the array:");
	scanf("%d",&n);
	int a[n],ind,key;
	for (i=0;i<n;i++){
		printf("Enter element %d:",i+1);
		scanf("%d",&a[i]);
	}
	printf("1-->Linear Search   2-->Binary Search  3-->Exit\n");
	printf("Enter your choice:");
	char ch=getche();
	printf("\n");
	switch(ch)
	{
		case '1':
			printf("Enter element to search:");
			scanf("%d",&key);
			ind=linearSearch(a,key,(sizeof(a)/4)-1);
			if (ind==-1)
				printf("Required element is not present in the array\n\n");
			else
				printf("Required element is in the index position %d\n\n",ind);
			break;
		case '2':
			printf("Enter element to search:");
			scanf("%d",&key);
			ind=binarySearch(a,key,0,(sizeof(a)/4)-1);
			if (ind==-1)
				printf("Required element is not present in the array\n\n");
			else
				printf("Required element is in the index position %d\n\n",ind);
			break;
		case '3':
			exit(0);
		default:
			printf("INVALID CHOICE\n");
	}
	choice();
}
int main()
{
	choice();
	return 0;
}
