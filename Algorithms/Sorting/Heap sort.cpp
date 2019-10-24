
#include<stdlib.h> 
#include<stdio.h> 


void merge(int a[], int lb,  int ub) 
{ 
	int i,start,m,k,l,b[10];
	start=lb;
	l=lb;
	m=(lb+ub)/2;
	k=m+1;
	while(lb<=m&&k<=ub){
		if(a[lb]>=a[k]){
			b[l]=a[k];
			k++;
		}
		else{
			b[l]=a[lb];
			lb++;
		}
		l++;
	}
	if(lb>m){
		while(k<=ub){
			b[l]=a[k];
			l++;
			k++;
		}
	}
	else{
		while(lb<=m){
			b[l]=a[lb];
			l++;
			lb++;
		}
	}
	for(l=start;l<=ub;l++){
		a[l]=b[l];
	}

}
void mergeSort(int arr[], int l, int u) 
{ 
	if (l < u) 
	{ 
	
		int m = (l+u)/2; 

		// Sort first and second halves 
		mergeSort(arr, l, m); 
		mergeSort(arr, m+1, u); 

		merge(arr, l, u); 
	} 
} 

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", A[i]); 
	printf("\n"); 
} 

/* Driver program to test above functions */
int main() 
{ 
	int arr[] = {1, 11, 13, 5, 6, 7}; 
	int arr_size = sizeof(arr)/sizeof(arr[0]); 
	int lb=0,ub=arr_size-1;
	printf("Given array is \n"); 
	printArray(arr, arr_size); 

	mergeSort(arr, lb,ub); 

	printf("\nSorted array is \n"); 
	printArray(arr, arr_size); 
	return 0; 
} 

