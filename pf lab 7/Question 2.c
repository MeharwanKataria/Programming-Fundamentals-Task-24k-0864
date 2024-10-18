#include<stdio.h>
int main(){
		int j;
	int i,n;
	int x,y;

	printf("Enter the size of array");
	scanf("%d",&n);
		int A[n];
	for(i=0;i<10;i++){
		printf("Enter the numbers in array");	
		 scanf("%d",&A[i]);}
		 printf("Before:{ ");
	for (i=0;i<n;i++){
		printf("%d ",A[i]);
	}
	printf("}");
		for(i=0,j=n-1;i<=j;i++,j--){
		int temp=A[i];
		A[i]=A[j];
		A[j]=temp;
	}
		for(i=0,j=8;i<=j;i++,j--){
		int temp=A[i];
		A[i]=A[j];
		A[j]=temp;
	}printf("\nAfter:{");
	for(i=0;i<n;i++){
		printf("%d ",A[i]);
	}
	printf("}");}

