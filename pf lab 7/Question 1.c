#include<stdio.h>
int main(){
	int x;
	int i,n;

	printf("Enter the size of array");
	scanf("%d",&n);
		int A[n];
	for(i=0;i<n;i++){
		printf("Enter the numbers in array: ");	
		 scanf("%d",&A[i]);
	}printf("Given Array:\n ");
	for(i=0;i<n;i++){
		printf("%d ",A[i]);
	}
	printf("\nEnter the integer to search: ");
	scanf("%d",&x);
	for (i=0;i<10;i++){
		if(x==A[i])
		printf("%d found at index %d\n",x,i);
	}
}
