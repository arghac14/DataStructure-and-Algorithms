#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 20
int top=-1;
char stack[MAX];

int main()
{
	char infix[MAX],postfix[MAX];
	printf("Enter your infix expression(containing only single digit vairable and constant) : ");
	scanf("%s",&infix);
    infix_to_postfix(infix,postfix);
	printf("\nThe postfix epression is : ");
	puts(postfix);
}
void infix_to_postfix(char infix[],char postfix[])
{
	int i=0,j=0;
	char item,x;
	
	push('(');
	strcat(infix,')');
	item=infix[i];
	
	while(item!=NULL)
	{ 
			if(item=='(')
				{
					push(item);
				}
			else if(isalnum(item))
				{
					stack[j]=item;
					j++;
				}
			else if(is_operator(item))
				{	
				    char x;
				    x=pop();
					while(is_operator(item)==1 && precedance(x) >= precedance(item))
						{
							stack[j]=x;
							j++;
							x=pop();
						}
						push(x);
						push(item);
				}
			else if(item==')')
				{
					x=pop();
					while(x!='(')
						{
							stack[j]=x;
							x=pop();
						}
				}
			else
				{
					print("Invalid infix expression!");
					exit(1);
				}
		
		
	i++;
	item=infix[i];
	}
	postfix[j]=NULL;
}


void push(char item)
{
	if(top >= MAX-1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		top = top+1;
		stack[top] = item;
	}
}


void pop()
{
	char item ;

	if(top <0)
	{
		printf("stack under flow: invalid infix expression");
		exit(1);
	}
	else
	{
		item = stack[top];
		top = top-1;
		return(item);
	}
}

void is_operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}


void precedance(char symbol)
{
	if(symbol == '^')
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')          
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

