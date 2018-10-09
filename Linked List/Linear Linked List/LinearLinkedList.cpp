#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};

struct node *start=(struct node*)malloc(sizeof(struct node));
int flag=1;
void insert_end(){
	struct node *p=start,*temp;
	int item;
	printf("Please enter the data item to be inserted:");
	scanf("%d",&item);
	while(p->next!=NULL){
		p=p->next;
	}
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=item;
	p->next=temp;
	temp->next=NULL;
}
void create(){
 int i,node,item;
 printf("Please enter the no. of node:");
 scanf("%d",&node);
 printf("Please enter the data item to be inserted:");
 scanf("%d",&item);
 start->data=item;
 start->next=NULL;
 for(i=0;i<node-1;i++){
 	insert_end();
 }
 
}
void insert_at_loc(){
	struct node *p=start,*temp;
	int i,item,loc;
	printf("Please enter the item tobe inserted:");
	scanf("%d",&item);
	printf("Please enter the location to be inserted at:");
	for(i=0;i<loc && p!=NULL;i++)
	p=p->next;
	if(loc=i+1){
		temp=(struct node *)malloc(sizeof(struct node));
		temp->data=item;
		temp->next=p->next;
		p->next=temp;
		
	}
	else{
		printf("Location is not present in the List!");
	}
}
void insert_bet_val(){
	struct node *p=start,*temp;
	int val,item;
	printf("The value to be inserted:");
	scanf("%d",&item);
	printf("The value after which to be inserted:");
	scanf("%d",&val);
	while(p->data!=val && p->next!=NULL)
	p=p->next;
	if(p->data==val){
		temp=(struct node*)malloc(sizeof(struct node));
		temp->data=item;
		temp->next=p->next;
		p->next=temp->next;
	}
	else{
		printf("Value not found in the list!");
		
	}
}

void delete_item(){
	int ch;
	struct node *p=start;
	printf("Please enter you choice:\n1>delete at beginning.\n2>delete after value.\n3>delete at end\n:");
	scanf("%d",&ch);
	switch(ch){
		case 1:start=p->next;
			   free(p);
			   break;
		case 2:int item;
				printf("The value after which deletion occurs:");
				scanf("%d",&item);
				
				while(p->data!=item && p->next!=NULL)
				p=p->next;
				if(p->data==item){
					p->next=p->next->next;
				}
				else{
					printf("No such value found!");
				}
				break;
		case 3:while(p->next->next!=NULL){
					p=p->next;
				}
				p->next=NULL;
				break;
		default:printf("Wrong Choice!");
			
	}
}
void search(){
	int item,i;
	struct node *p=start;
	printf("Please enter the item to be seached:");
	scanf("%d",&item);
	for(i=0;p!=NULL;i++){
		if(p->data==item){
			printf("%d found at %d",item,i);
			return;
		}
	}
	printf("No Such Element Found!");
}
void sort(){
	struct node *i=start,*j;
	while(i!=NULL){
		j=i->next;
		while(j!=NULL){
			if(i->data>j->data){
				int tem=i->data;
				i->data=j->data;
				j->data=tem;
			}
		}
		i=i->next;
	}
}


main(){
	int ch;
	printf("Please enter your choice:");
	scanf("%d",&ch);
	while(1){
		
	}
}
