#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 50
 struct stack {
   char data[MAX];
   int top;
} s;

void initialize()
{
	s.top=-1;
}
int empty()
{
	if(s.top==-1)
	return 1;
	else
	return 0;
}

int full()
{
	if(s.top>=MAX)
	return 1;
	else
	return 0;
}

void push(char item)
{
	int f;
	f=full();
	if(f!=1)
	{
		s.top=s.top+1;
   s.data[s.top] = item;
		
		
	}
	else
	{
			printf("\nStack Overflow");
	}

}

char pop()
{
	int e,d;
	e=empty();
	if(e!=1)
	{
		d=s.data[s.top];
		s.top--;
		
	}
	else
	{
		printf("\nStack Underflow");
	}
	return d;
}


void display()
{
	int i,e=empty();
	if(e!=1){
	printf("\nStack is \n");
	
		for(i=s.top;i>-1;i--)
		printf("%c\t",s.data[i]);
	}
	else
		printf("\nStack Underflow");
	
}
	
int main()
{
	
	char expr[MAX],t;
	int i,flag=1;
	initialize();

   	printf("\nEnter Expr\n");
	scanf("%s",expr);
	
	for(i=0;i<strlen(expr);i++)
	{
		if(expr[i]=='('|| expr[i]=='{'|| expr[i]=='[' )
		push(expr[i]);
		if(expr[i]==')'|| expr[i]=='}'|| expr[i]==']' )
		if(s.top==-1)
		flag=0;
		else
		{
			t=pop();
			if((expr[i]==')') &&((t=='{')||(t=='[')))
			flag=0;
		else if(((expr[i]==']') &&((t=='{')||(t=='('))))
			flag=0;
			else if(((expr[i]=='}') &&((t=='(')||(t=='['))))
			flag=0;
			else
			flag=1;
		}
	}
	if(s.top>=0)
	flag=0;
	
	if(flag==1)
	printf("\nValid");
	else
	printf("\nInvalid");
		
	return 0;
}
