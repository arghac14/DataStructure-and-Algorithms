#include<stdio.h>
#include<stdlib.h>

struct term{
	int coef;
	int pow;
	struct term *next;
};
void insert_end(struct term *start){
	struct term *p=start,*temp;
	int co,po;
	printf("Please enter coefficient to be inserted:");
	scanf("%d",&co);
	printf("Please enter power of the coefficient:");
	scanf("%d",&po);
	while(p->next!=NULL){
		p=p->next;
	}
	temp=(struct term*)malloc(sizeof(struct term));
	temp->coef=co;
	temp->pow=po;
	p->next=temp;
	temp->next=NULL;
	
}
void sort(struct term *start){
	struct term *i=start,*j;
	
	while(i!=NULL){
		
		j=i->next;
	
		while(j!=NULL){
			if(i->pow<j->pow){
				int tem1=i->pow;
				int tem2=i->coef;
				i->coef=j->coef;
				i->pow=j->pow;
				j->coef=tem2;
				j->pow=tem1;
			}
			j=j->next;
		}
		i=i->next;
	}
}
struct term* add(struct term *start1,struct term *start2){
	struct term *start3=(struct term*)malloc(sizeof(struct term)),*p1=start1,*p2=start2,*p3=start3,*temp;
	while(p1!=NULL){
		temp=(struct term*)malloc(sizeof(struct term));
		temp->coef=p1->coef;
		temp->pow=p1->pow;
		temp->next=NULL;
		p3->next=temp;
		p3=p3->next;
		p1=p1->next;
	}
	while(p2!=NULL){
		temp=(struct term*)malloc(sizeof(struct term));
		temp->coef=p2->coef;
		temp->pow=p2->pow;
		temp->next=NULL;
		p3->next=temp;
		p3=p3->next;
		p2=p2->next;
	}
	start3=start3->next;
	sort(start3);
	p3=start3;
	while(p3!=NULL){
		if(p3->next->pow==p3->pow){
			p3->coef=p3->coef+p3->next->coef;
			p3->next=p3->next->next;
		}
		
			p3=p3->next;
	}	
	return start3;
}
//displays the polynomials 
void display(struct term *start){
	struct term *p=start;
	while(p!=NULL){
		
		printf("%d x^%d ",p->coef,p->pow);
		p=p->next;
	}
	printf("\n");
}
//Creates the Polynomials Linked List
void createStarts(struct term *start){
	 
	 int i,node,co,po;
	 printf("Please enter the no. of terms in the polynomial:");
	 scanf("%d",&node);
	 if(node==0){
	 	printf("\nThere must be atleast 1 term!");
	 	exit(1);
	 }
	 printf("Please enter coefficient to be inserted:");
	 scanf("%d",&co);
	 printf("Please enter power of the coefficient:");
	 scanf("%d",&po);
	 start->coef=co;
	 start->pow=po;
	 start->next=NULL;
	 for(i=0;i<node-1;i++){
	 	insert_end(start);
	 	} 
	printf("Polynomial Linked List Created:");
	display(start);
}
main(){
	int n,i;
	struct term *poly1=(struct term *)malloc(sizeof(struct term)),*poly2=(struct term *)malloc(sizeof(struct term)),*sum=(struct term *)malloc(sizeof(struct term));
	system("color 0A");
	createStarts(poly1);
	createStarts(poly2);	

	printf("\nTerms to Add:\n");
	display(poly1);
	display(poly2);
	sum=add(poly1,poly2);
    printf("\nResult:\n");
	display(sum);

}
