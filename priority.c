#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int i, PQ[MAX];
int count = 0;
void acdq();
void dcdq();
void main()
{
    int m;
    printf("Menu:\n");
    printf("1. Insertion in ascending priority queue\n");
    printf("2. Deletion in ascending priority queue\n");
    printf("3. Exit\n\n");
    do
    {
        printf("Enter your choice: ");
        scanf("%d", &m);
        switch (m)
        {
        case 1:
            acdq();
            for (i=count-1;i>=0;i--)
                printf("%d\n", PQ[i]);
            break;
        case 2:
            dcdq();
            for (i=count-1;i>=0;i--)
                printf("%d\n", PQ[i]);
            break;
        case 3:
            exit(0);
        }
    } while (1);
}
void acdq()
{
    if (count < MAX)
    {
        int x, i;
        printf("Enter the data: ");
        scanf("%d", &x);
        if (count == 0)
            PQ[count++] = x;
        else
        {
            for (i = count - 1; i >= 0; i--)
            {
                if (x > PQ[i])
                    PQ[i + 1] = PQ[i];
                else
                    break;
            }
            PQ[i + 1] = x;
            count = count + 1;
        }
    }
    else
        printf("Queue is full\n");
}
void dcdq()
{
    if (count != 0)
        printf(" deleted:%d\n", PQ[--count]);
    else
        printf("Queue is empty\n");
}
