#include <stdio.h>
#define MAX 10



void selection(int a[] ,int n){
	int i,j,min,temp;
	for(i=0;i<n-1;i++){
		min=i;
		for(j=i+1;i<n;i++){
			if(a[j]<a[min]){
				min=j;
			}
		}
		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	}
	}
void bubble(int a[],int n){
	int i,j,temp;
	for(i=0;i<n-1;i++){
		for(j=0;j<=n-i-1;j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]+=a[j+1];
				a[j+1]=temp;
			}
			}
		}		
	}
void insertion(int a[],int n)
{
	int i,k,j;
	for (i = 1 ; i <= n - 1; i++) {
    		k = i;
    	while ( k > 0 && a[k-1] > a[k]) {
     	 temp= a[k];
     	 a[k]   = a[k-1];
     	 a[k-1] = temp;
 	k--
}
int main(){
	int i,a[MAX],n,c;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	for(i=0;i<n;i++){	
	
	scanf("%d",&a[i]);
	}
	
	
	printf("\n          Menu\n1.Selection 2.bubble 3.insertion");
	printf("\n\nEnter Sorting type: ");
	scanf("%d",&c);
	switch(c){
		case 1: selection(a,n);
				break;
		case 2: bubble(a,n);
				break;
		case 3: insertion(a,n);
				break;
	}
	printf("Sorted array is:");
	for(i=0;i<n;i++){
	
	printf("%d ",a[i]);
	}
}

