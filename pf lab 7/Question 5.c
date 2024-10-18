#include <stdio.h>

int main(){

	int array2[20];
int i;
	
	printf("enter the numbers in array");
	for( i=0;i<20;i++){
		scanf("%d",&array2[i]);
	}
	printf("Array elements: \n");
	for( i=0; i<20; i++){
		printf(" %d ",array2[i]);
	}
	
	printf("\nReversed array elements: \n");
	for(i=20-1; i>=0; i--){
		printf(" %d ",array2[i]);}}
