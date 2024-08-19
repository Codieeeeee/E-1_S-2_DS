#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 100
int top=-1;
char stack[MAX];
char infix[MAX],postfix[MAX];
int precedence(char symbol)
{
    switch(symbol)
    {
    case'^':
        return 3;
    case'/':
    case'*':
        return 2;
    case'+':
    case'-':
        return 1;
    default:
        return 0;
    }
}
int space(char c)
{
    if(c==' ' || c=='\t')
        return 1;
    else
        return 0;
}
void print()
{
    int i=0;
    printf("the equivalent postfix expression is:");
    while(postfix[i]){
        printf("%c" ,postfix[i++]);
    }
}
void push(int c)
{
    if(top==MAX-1){
        printf("stack overflow\n");
        return;
    }
    //top++;
    stack[++top]=c;
}
char pop()
{
    char c;
    if(top==-1){
        printf("stack underflow\n");
        exit(1);
    }
    c=stack[top];
    top=top-1;
    return c;
}
int isempty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
void intopost()
{
    int i,j=0;
    char next;
    char symbol;
    for(i=0;i<strlen(infix);i++){
        symbol=infix[i];
        if(!space(symbol)){
            switch(symbol)
            {
            case'(':
                push(symbol);
                break;
            case')':
                while((next=pop())!='(')
                        postfix[j++]=next;
                break;
            case'+':
            case'*':
            case'-':
            case'/':
            case'^':
                while(!isempty()&& precedence(stack[top]) >= precedence(symbol))
                    postfix[j++]=pop();
                push(symbol);
                break;
            default:
                postfix[j++]=symbol;
            }
        }
    }
    while(!isempty())
        postfix[j++]=pop();
    postfix[j]='\0';
}
int post_val()
{
    int a,b,i;
    for(i=0;i<strlen(postfix);i++){
        if(postfix[i]>='0' && postfix[i]<='9'){
            push(postfix[i]-'0');
        }
        else{
            a=pop();
            b=pop();
            switch(postfix[i])
            {
            case'+':
                push(b+a);
                break;
            case'-':
                push(b-a);
                break;
            case'*':
                push(b*a);
                break;
            case'/':
                push(b/a);
                break;
            case'^':
                push(pow(b,a));
                break;
            }
        }
    }
    return pop();
}
int main()
{
    int result;
    printf("enter the infix expression:");
    gets(infix);
    intopost();
    print();
    result=post_val();
    printf("\nthe result of the equivalent expression is:");
    printf("%d" ,result);
}
