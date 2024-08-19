#include<stdio.h>
#include<math.h>
void bubbleSort(int a[],int len);
void countingSort(int a[],int len);
void swap(int *,int *);
int getMaxElement(int a[],int len);
void swap(int *p1,int *p2)
{
	int temp=*p1;
	*p1=*p2;
	*p2=temp;
}
void bubbleSort(int a[],int len)
{
	int i,j;
	for(i=0;i<len-1;i++){
		for (j=0;j<len-1-i;j++){
			if (a[j]>a[j+1])
				swap(&a[j],&a[j+1]);
		}
	}
}
void countingSort(int a[],int len)
{
	int i,temp[len],m=getMaxElement(a,len);
	int count[m+1];
	for (i=0;i<len;i++)
		count[i]=0;
	for (i=0;i<len;i++)
		++count[a[i]];
	for (i=1;i<len;i++)
		count[i]=count[i-1]+count[i];
	for (i=len-1;i>=0;i--)
		temp[--count[a[i]]]=a[i];
	for (i-0;i<len;i++)
		a[i]=temp[i];
}
int getMaxElement(int a[],int len)
{
	int max=a[0],i=0;
	for (i=0;i<len;i++){
		if (a[i]>max)
			max=a[i];
	}
	return max;
}
int main()
{
	int a1[]={10,7,65,43,56,49,13,19,25,16};
	int a2[]={1,7,9,6,5,1,4,7,3,2,5,10,10,7};
	int i;
	printf("Array before bubble sort:\n");
	for (i=0;i<sizeof(a1)/4;i++)
		printf("%d\t",a1[i]);
	printf("\nArray after bubble sort:\n");
	bubbleSort(a1,sizeof(a1)/4);
	for (i=0;i<sizeof(a1)/4;i++)
		printf("%d\t",a1[i]);
	printf("\nArray before counting sort:\n");
	for (i=0;i<sizeof(a2)/4;i++)
		printf("%d\t",a2[i]);
	printf("\nArray after counting sort:\n");
	countingSort(a2,sizeof(a2)/4);
	for (i=0;i<sizeof(a2)/4;i++)
		printf("%d\t",a2[i]);
}
