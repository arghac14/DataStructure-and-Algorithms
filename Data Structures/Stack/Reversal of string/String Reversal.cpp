#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
int top=-1,item;
char stack[MAX];

void push(char item){
 	if(top==MAX-1){
 		printf("OVERFLOW!\n");
	 }	
	 else{
	 	top=top+1;
	 	stack[top]=item;
	 }
}

char pop(){
	if(top==-1){
		printf("UNDERFLOW!\n");
	}
	else{
		item=stack[top];
		top=top-1;
		return item;
	}
}
int main(){
	int i,l;
	char str[10];
	printf("\nEnter Your sting : ");
	gets(str);
	
	l=strlen(str);
	for(i=0;i<l;i++){
		push(str[i]);
	}
	
	for(i=0;i<l;i++){
		str[i]=pop();
	}
	printf("\nReversed string is: ");
	puts(str);
}
