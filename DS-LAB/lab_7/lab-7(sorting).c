#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
void swap(int *p1,int *p2);
int print(int a[],int len);
void bubbleSort(int a[],int len);
void selectionSort(int a[],int len);
void insertionSort(int a[],int len);
void merging(int a[],int beg,int mid,int end);
void mergeSort(int a[],int beg,int end);
int partition(int a[],int start,int end);
void quickSort(int a[],int start,int end);
void choice();
int main()
{
	choice();
	return 0;
}
void choice()
{
	int n,i;
	printf("Enter no.of elements in the array:");
	scanf("%d",&n);
	int array[n];
	for (i=0;i<n;i++){
		printf("Enter element %d:",i+1);
		scanf("%d",&array[i]);
	}
	printf("1-->Bubble Sort  2-->Selection Sort  3-->Insertion Sort  4-->Merge Sort  5-->Quick Sort  6-->Exit\n");
	printf("press which sort do you want:");
	char ch=getche();
	printf("\n");
	switch(ch)
	{
		case '1':
			bubbleSort(array,n);
			print(array,n);
			break;
		case '2':
			selectionSort(array,n);
			print(array,n);
			break;
		case '3':
			insertionSort(array,n);
			print(array,n);
			break;
		case '4':
			mergeSort(array,0,n-1);
			print(array,n);
			break;
		case '5':
			quickSort(array,0,n-1);
			print(array,n);
			break;
		case '6':
			exit(0);
		default:
			printf("INVALID CHOICE\n");
	}
	choice();
}
void swap(int *p1,int *p2)
{
	int temp=*p1;
	*p1=*p2;
	*p2=temp;
}
int print(int a[],int len)
{
	static int i=0;
	if (i==len){
		printf("\n");
		i=0;
		return;
	}
	printf("%d  ",a[i++]);
	print(a,len);
}
void bubbleSort(int a[],int len)
{
	int i,j;
	for (i=0;i<len-1;i++){
		for (j=0;j<len-1-i;j++){
			if (a[j]>a[j+1])
				swap(&a[j],&a[j+1]);
		}
	}
}
void selectionSort(int a[],int len)
{
	int i,j,min_index;
	for (i=0;i<len-1;i++){
		min_index=i;
		for (j=i+1;j<len;j++){
			if (a[j]<a[min_index])
				min_index=j;
		}
		swap(&a[i],&a[min_index]);
	}
}
void insertionSort(int a[],int len)
{
	int i,j,key;
	for (i=1;i<len;i++){
		j=i-1;
		key=a[i];
		while (key<a[j] && j>=0){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}
void merging(int a[],int beg,int mid,int end)
{
	int i=beg,j=mid+1,b[end],index=beg;
	while(i<=mid && j<=end){
		if(a[i]<=a[j])
			b[index++]=a[i++];
		else
			b[index++]=a[j++];
	}
	if (i>mid){
		while(j<=end)
			b[index++]=a[j++];
	}
	else{
		while(i<=mid)
			b[index++]=a[i++];
	}
	for(i=beg;i<=end;i++)
		a[i]=b[i];	
}
void mergeSort(int a[],int beg,int end)
{
	if(beg<end){
		int mid=(beg+end)/2;
		mergeSort(a,beg,mid);
		mergeSort(a,mid+1,end);
		merging(a,beg,mid,end);
	}
}
int partition(int a[],int start,int end)
{
	int i,j,pivot;
	i=start;
	j=end;
	pivot=a[i];
	while(i<j)
	{
		while(a[i]<=pivot)
			i++;
		while(a[j]>pivot)
			j--;
		if(i<j)
			swap(&a[i],&a[j]);
	}
	swap(&a[start],&a[j]);  //a[start]=pivot
	return j;
}
void quickSort(int a[],int start,int end)
{
	if (start<end){
		int p=partition(a,start,end);
		quickSort(a,start,p-1);
		quickSort(a,p+1,end);
	}
}
