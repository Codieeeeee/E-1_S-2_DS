#include<stdio.h>
char arr[30],arr1[30];int n,n1;
void read_print();
void even_odd();
void arrange();
void insert();
void delete();
int main()
{
    read_print();
    return 0;
}
void read_print()
{
	printf("NOTE:You need to enter 10 times,only either 'M' or 'W'\n");
    int i;char c;
    for (i=0;n<10;i++){
        printf("Enter M or W:");
        scanf("%s",&c);
        if (c=='M' || c=='W'){
        	arr[n]=c;
        	n++;
		}
		else
			printf("Please read the note carefully\n");
    }
    printf("Original array:\n");
    for (i=0;i<n;i++)
        printf("%c  ",arr[i]);
    printf("\n");
    even_odd();
}
void even_odd()
{
    int i,e=0,o=0;
    printf("Even indices of M:");
    for (i=0;i<n;i++){
        if (arr[i]=='M' && i%2==0){	
            printf("%d  ",i);
            e++;
		}
	}
	if (e==0)
		printf("\nM's are not present in even indices");
    printf("\nOdd indices of W:");
    for (i=0;i<n;i++){
        if (arr[i]=='W' && i%2!=0){
            printf("%d  ",i);
            o++;
        }
    }
    if (o==0)
		printf("\nW's are not present in odd indices");
	printf("\n");
	arrange();
}
void arrange()
{
	int i;
	for (i=0;i<n;i++){
		if (arr[i]=='M'){
			arr1[n1]=arr[i];
			n1++;
		}
	}
	for (i=0;i<n;i++){
		if (arr[i]=='W'){
			arr1[n1]=arr[i];
			n1++;
		}
	}
	printf("After arranging:\n");
	for (i=0;i<n1;i++)
        printf("%c  ",arr1[i]);
    printf("\n");
    insert();
}
void insert()
{
	int i,j,n0=n;
	for (i=0;i<n;i++)
		arr1[i]=arr[i];
	for (j=1;j<n0-1;j++){
		if(arr[j-1]!='W' && arr[j+1]!='W'){
	 		for (i=n0;i>j;i--){
	 			arr[i+1]=arr[i];
			}
			arr[i]='M';
			n++;
		}
	}
	printf("After insertion:\n");
	for (i=0;i<n;i++){
        printf("%c  ",arr[i]);
	}
    printf("\n");
    delete();
}
void delete()
{
	int i,j;
	for (i=1;i<n-1;i++){
		if (arr[i]=='W' && arr[i-1]=='M' && arr[i+1]=='M'){
			for (j=i;j<n;j++)
				arr1[j]=arr1[j+1];
		n--;
		}
	}
	printf("After deletion:\n");
	for (i=0;i<n;i++){
        printf("%c  ",arr1[i]);
    }
    printf("\n");
}
