#include<stdio.h>
void merge(int a[],int beg,int mid,int end)
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
		merge(a,beg,mid,end);
	}
}
void swap(int *p1,int *p2)
{
	int temp=*p1;
	*p1=*p2;
	*p2=temp;
}
void quickSort(int a[],int start,int end)
{
	if (start<end){
		int p=partition(a,start,end);
		quickSort(a,start,p-1);
		quickSort(a,p+1,end);
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
void heapify(int a[],int n,int i)
{
	int big,lc,rc;
	big=i;
	lc=2*i;
	rc=2*i+1;
	if (lc<n && a[lc]>=a[big])
		big=lc;
	if (rc<n && a[rc]>=a[big])
		big=rc;
	if (big!=i )
		swap(&a[i],&a[big]);
	if (i>1)
		heapify(a,n,--i);
}
void heapSort(int a[],int n)
{
	int i;
	for (i=n/2;i>=1;i--)
		heapify(a,n,i);
	for (i=n-1;i>1;i--){
		swap(&a[1],&a[i]);
		heapify(a,i,i/2);
	}
}
int main()
{
	int a[9],i;
	for (i=1;i<9;i++){
		printf("Enter element %d:",i);
		scanf("%d",&a[i]);
	}
	heapSort(a,9);
	for (i=1;i<9;i++)
		printf("%d  ",a[i]);
	return 0;
}
