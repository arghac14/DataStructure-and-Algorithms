#include <stdio.h>

#define MAX 10

void linear(int a[],int n,int s){
	int i,j;
	for(i=0;i<n;i++){
		if(a[i]==s){
			printf("Element %d found at %d place.",s,i+1);
			break;
		}
		if(i==n)
		{
			printf("Element not found!");
		}
	}
	
	
}
void binary(int a[],int n,int s){
	int i,f,l,m,fl=1;
	f=0;
	l=n-1;
	while(f<=l){	
	m=(f+l)/2;
	

	  if (a[m] == s) {
         printf("\nElement  : %d  : Found :  Position : %d.\n",s,m+1);
         break;
	  }
      else if (a[m]<s)
       f = m + 1;    
      else
         l = m - 1;
   }
   
   if (f > l)
      printf("\nSearch Element : %d  : Not Found \n",s);
}

void interpolation(int a[],int n,int s){
	
	int f,l,pos;
	f=0;
	l=n-1;
	while(f<=l && s>=a[f] && s<=a[l]){
		pos=f + (((double)(l - f) / (a[l] - a[f])) * (s - a[f]));
		
		if(s==a[pos])	{
		
			printf("Element  : %d  : Found :  Position : %d.\n",s,pos+1);
			break;
		}
		else if(s>a[pos])
			f=pos+1;
		else
			l=pos-1;
	}
	
   if (f > l)
      printf("\nSearch Element : %d  : Not Found \n",s);
  }	

int main(){
	int i,a[MAX],n,s,c;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	printf("Enter the array elements: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("Enter the element to be searched: ");
	scanf("%d",&s);

	printf("\n\n1.Linear   2.Binary   3.Interpolation  \n\nEnter the search type: ");
	scanf("%d",&c);
	if(c==1){
			linear(a,n,s);
			
	}
	else if(c==2){
		binary(a,n,s);
			
	}
	else if(c==3){
		interpolation(a,n,s);
			
	}
	else{
		printf("INVALID SEARCH TYPE!");
	}
}



