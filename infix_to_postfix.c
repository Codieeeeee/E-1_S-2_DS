#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 100
char s[N];double eval[N];int top=-1;
char infexp[100];
char postexp[100];
int precedence(char ch)
{
	if (ch=='+' || ch=='-')
		return 1;
	else if (ch=='*' || ch=='/')
		return 2;
	else if (ch=='^')
		return 3;
	else
		return 0;
}
int associativity(char ch)
{
	if (ch=='^')
		return 1;
	else
		return 0;
}
char pop()
{
	return s[top--];
}
void push(char ch)
{
	s[++top]=ch;
}
void convertToPostfix()
{
	int i,p,t,j=0;
	for (i=0;i<strlen(infexp);i++){
		char ch=infexp[i]; 
		if (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^' || ch=='(' || ch==')'){
			p=precedence(ch);
			t=precedence(s[top]);
			if (top==-1 || ch=='(' || s[top]=='(' || p>t || (p==t&&associativity(ch)==1))
				push(ch);
			else if (ch==')'){
				while(s[top]!='(')
					postexp[j++]=pop();
				pop();//for '('
			}
			else{
				while(p<=t){
					postexp[j++]=pop();
					t=precedence(s[top]);
					if (top==-1)
						break;
				}
				push(ch);
			}
		}
		else
			postexp[j++]=ch;
	}
	while(top!=-1)
		postexp[j++]=pop();
	postexp[j]='\0';	
}
void pushEval(int x)
{
	eval[++top]=x;
}
double popEval()
{
	return eval[top--];
}
double posteval()
{
	int i,a,b;
	for (i=0;i<strlen(postexp);i++){
		char ch=postexp[i];
		if (ch>='0' && ch<='9'){
			ch-='0';
			eval[++top]=ch;
		}
		else{
			a=popEval();
			b=popEval();
			switch(ch)
			{
				case '+':
					pushEval(b+a);
					break;
				case '-':
					pushEval(b-a);
					break;
				case '*':
					pushEval(b*a);
					break;
				case '/':
					pushEval(b/a);
					break;
				case '^':
					pushEval(pow(b,a));
			}
		}
	}
	return eval[top];
}
int check_exp(char exp[])
{
	int i,num_open=0,num_close=0;
	for (i=0;i<strlen(exp);i++){
		if (exp[i]=='(')
			num_open++;
		else if(exp[i]==')')
			num_close++;
	}
	if (num_open==num_close)
		return 1;
	else
		return 0;
}
int main()
{
	printf("Enter the infix expression:");
	scanf("%s",&infexp);
	if (!check_exp(infexp))
		printf("Entered expression is invalid\n");
	else{
		convertToPostfix();
		printf("Postfix expression is:");
		puts(postexp);
		printf("Answer to the above expression is:%.2lf",posteval());
	}
	return 0;
}

