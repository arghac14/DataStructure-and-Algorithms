#include<stdio.h>
#include<stdlib.h>

struct dnode{
	int data;
	struct dnode *prev;
	struct dnode *next;
};
struct dnode *start=NULL;
void insert(){
int ch;
struct dnode *p=start,*temp;
int item;
printf("Please enter your choice:\n1>Insert End\n2>Insert Value\n3>Insert Beg\n:");
scanf("%d",&ch);
switch(ch){
	case 1:printf("Please enter the item to be inserted:");
		   scanf("%d",&item);
		   while(p->next!=NULL)
		   p=p->next;
		   temp=(struct dnode*)malloc(sizeof(struct dnode));
		   temp->data=item;
		   temp->prev=p;
		   temp->next=NULL;
		   break;
	case 2:int loc,i;
		   printf("Please enter the item to be inserted:");
		   scanf("%d",&item);
		   printf("Please enter the location at which the item is to be inserted:");
		   scanf("%d",&loc);
		   for(i=0;i<loc && p!=NULL;i++,p=p->next);
		   if(p!=NULL){
		   	temp=(struct dnode*)malloc(sizeof(struct dnode));
			   temp->data=item;
			   temp->prev=p;
			   temp->next=p->next;
			   if(p->next!=NULL){
			   	temp->next->prev=temp;
			   	
			   }
			   p->next=temp;		   	
		   }
		   break;
	case 3:printf("Please enter the item to be inserted:");
		   scanf("%d",&item);
		   temp=(struct dnode *)malloc(sizeof(struct dnode));
		   temp->data=item;
		   temp->prev=NULL;
		   temp->next=p;
		   start=temp;
		   break;
	}
}
void delete_node(){
	int item;
	struct dnode *p=start;
	printf("Please enter the data item to be deleted:");
	scanf("%d",&item);
	while(p->data!=item && p->next!=NULL){
		p=p->next;
	}
	if(p->data==item){
		if(p->next==NULL){
			p->prev->next=NULL;
		}
		else{
			p->prev->next=p->next;
		}
		if(p->prev==NULL){
			p->next->prev=NULL;
		}
		else{
			p->next->prev=p->prev;
		}
	
	free(p);}
	else{
		printf("No such Data Found!");
	}
}
void display()
{
	struct dnode *p=start;
	while(p!=NULL){
		printf("%d\n",p->data);
		p=p->next;
	}
}
void create(){
	int item;
	printf("Please enter the initial element:");
	scanf("%d",&item);
	start=(struct dnode*)malloc(sizeof(struct dnode));
	start->data=item;
	start->next=NULL;
	start->prev=NULL;
}
main(){
	create();
	while(1){
		int ch;
		printf("Please enter your choice:\n1>insert\n2>delete\n3>display\n4>EXIT\n:");
		scanf("%d",&ch);
		switch(ch){
			case 1:insert();break;
			case 2:delete_node();break;
			case 3:display;break;
			case 4:exit(0);
			default:printf("Wrong Argument!");
		}
	}
}
