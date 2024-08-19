#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
    char light[10];
    struct node *link;
};
void printLights(struct node *ptr,int n);
int main(){
    int n;
    printf("Enter number of lights to be printed: ");
    scanf("%d",&n);
    char lightsArr[][7]={"RED","ORANGE","GREEN"};

    int i=0;
    struct node* head=(struct node*)malloc(sizeof(struct node));
    strcpy(head->light,lightsArr[i++]);
    head->link=head;
    struct node *ptr=head;

    while(i<3){
        struct node* new=(struct node*)malloc(sizeof(struct node));
        strcpy(new->light,lightsArr[i++]);
        ptr->link=new;
        new->link=head;
        ptr=new;
    }
    printLights(head,n);
}

void printLights(struct node *ptr,int n){
    struct node *head=ptr;int i;
    printf("The %d lights in repetitive manner are: \n",n);
    for(i=0;i<n;i++){
        if(ptr==head){
            printf("The new traffic cycle: \n");
        }
        printf("%s\n",ptr->light);
        ptr=ptr->link;
    }
}
