#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
int queue[MAXSIZE],front=-1,rear=-1,f=0;
int size;
void qInsert(){
	if((front==0 && rear==size) || front==rear+1){
		printf("\nCIRCULAR QUEUE Overflow!");
		return;
	}
	if(front==-1 && rear==-1)
	{
		front=0;
		rear=0;
	}
	else if(front!=0 && rear==size)
	rear=0;
	else
	rear++;

	printf("\nPlease enter the item to be inserted:");
	scanf("%d",&queue[rear]);
	
	
}
void qDelete(){
	int item;
	if(front==-1){
	printf("CIRCULAR QUEUE Underflow!");
	return;
	}
	 item=queue[front];
	 if(front==rear)
	 {
	 	front=-1;
	 	rear=-1;
	 }
	 if(front==size)
	 front=0;
	 else
	 front++;
	 printf("%d has been deleted from Queue!\n",item);
}

void qView(){
	if(front==-1){
		printf("\nCIRCULAR QUEUE Underflow!");
	}
	if(front<=rear){
		int i;
		printf("\nCIRCULAR QUEUE1 is:\n");
		for (i=front;i<=rear;i++){
			printf("%d\n",queue[i]);
		}		
	}
	else{
		int i;
		printf("%d %d",front,rear);
		printf("\nCIRCULAR QUEUE2 is:\n");
		for(i=front;i<size;i++){
			printf("%d\n",queue[i]);
		}
		for(i=0;i<rear;i++){
			printf("%d\n");
		}
		
	}
}
void qCreate(){
	int i,s;
	printf("Please enter the size of the CIRCULAR QUEUE.\n(Please note that the MAXSIZE is 100):");
	scanf("%d",&s);
	size=s;
	qInsert();
	f=1;
	qView();
}

main(){
	int ch;
	printf("This is an Implementation of CIRCULAR QUEUE. Please note that the MAXSIZE is 100.");
	while(1){
		if(f==0){
			printf("CIRCULAR QUEUE does not exist or is empty!");
			qCreate();			
		}
		printf("Please enter your choice:\n1>INSERT\n2>DELETE\n3>VIEW\n4>Search\n5>EXIT\n:");
		scanf("%d",&ch);
		switch(ch){
			case 1:qInsert();break;
			case 2:qDelete();break;
			case 3:qView();break;
			case 4:break;
			case 5:exit(0);
			default:printf("Wrong Choice!");
		}
	
	
	}
	
}

