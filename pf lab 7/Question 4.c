#include<stdio.h>
int main(){
	int A[15];
	int i,sum=0;
	printf("enter the numbers in array:");
	for( i=0;i<15;i++){
		scanf("%d",&A[i]);
	}
	printf("Array elements: \n");
	for( i=0; i<15; i++){
		printf(" %d ",A[i]);
	}			
	for(i=0; i<15;i++){
		sum+=A[i];
	}
	printf("\n sum of array = %d",sum);}
