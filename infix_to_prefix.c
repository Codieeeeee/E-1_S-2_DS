#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 100
char s[N],top=-1;double eval[N];
char infExp[100];
char preExp[100];
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
void convertToPrefix()
{
	int i,p,t,j=0;
	char rev_preExp[strlen(infExp)];
	for (i=strlen(infExp)-1;i>=0;i--){
		char ch=infExp[i]; 
		if (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^' || ch=='(' || ch==')'){
			p=precedence(ch);
			t=precedence(s[top]);
			if (top==-1 || ch==')' || s[top]==')' || p>t || (p==t&&associativity(ch)==0))
				push(ch);
			else if (ch=='('){
				while(s[top]!=')')
					rev_preExp[j++]=pop();
				pop();//for ')'
			}
			else{
				while(p<t){
					rev_preExp[j++]=pop();
					t=precedence(s[top]);
					if (top==-1)
						break;
				}
				push(ch);
			}
		}
		else
			rev_preExp[j++]=ch;
	}
	while(top!=-1)
		rev_preExp[j++]=pop();
	rev_preExp[j]='\0';
	j=0;
	for (i=strlen(rev_preExp)-1;i>=0;i--)
		preExp[j++]=rev_preExp[i];
}
void pushEval(int x)
{
	eval[++top]=x;
}
double popEval()
{
	return eval[top--];
}
double preEval()
{
	int i,a,b;
	for (i=strlen(preExp);i>=0;i--){
		char ch=preExp[i];
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
					pushEval(a+b);
					break;
				case '-':
					pushEval(a-b);
					break;
				case '*':
					pushEval(a*b);
					break;
				case '/':
					pushEval(a/b);
					break;
				case '^':
					pushEval(pow(a,b));
			}
		}
	}
	return eval[top];
}
int main()
{
	printf("Enter the infix expression:");
	scanf("%s",&infExp);
	convertToPrefix();
	printf("Prefix expression is:");
	puts(preExp);
	printf("Answer to the above expression is:%.2lf",preEval());
	return 0;
}

