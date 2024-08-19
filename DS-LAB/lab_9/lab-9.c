#include<stdio.h>
void swap(int *p1,int *p2);
int print(int a[],int len);
void maxHeapify(int a[],int n,int i);
void minHeapify(int a[],int n,int i);
int main()
{
	int array[]={45,23,12,34,40,7,5,0,19,11};
	int len=sizeof(array)/4,i;
	printf("Array before Heapify: ");
	print(array,len);
	for (i=len/2-1;i>=0;i--) 
		maxHeapify(array,len,i);
	printf("Array after Max-heapify: ");
	print(array,len);
	for (i=len/2-1;i>=0;i--) 
		minHeapify(array,len,i);
	printf("Array after Min-heapify: ");
	print(array,len);
	return 0;
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
void maxHeapify(int a[],int n,int i)
{
	int big,lc,rc;
	big=i;lc=2*i+1;rc=2*i+2;
	if (lc<n && a[lc]>a[big])
		big=lc;
	if (rc<n && a[rc]>a[big])
		big=rc;
	if (big!=i){
		swap(&a[i],&a[big]);
		maxHeapify(a,n,big);
	}
}
void minHeapify(int a[],int n,int i)
{
	int small,lc,rc;
	small=i;lc=2*i+1;rc=2*i+2;
	if (lc<n && a[lc]<a[small])
		small=lc;
	if (rc<n && a[rc]<a[small])
		small=rc;
	if (small!=i){
		swap(&a[i],&a[small]);
		minHeapify(a,n,small);
	}
}
