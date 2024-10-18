#include<stdio.h>
int main(){
	int A[30];
	int i;
	printf("enter the numbers in array:");
	for( i=0;i<30;i++){
		scanf("%d",&A[i]);
	}
	printf("Input Numbers in Array: \n");
	for( i=0; i<30; i++){
		printf(" %d ",A[i]);
	}
	//max number
	int max=A[0];
	for(i=0; i<30; i++){
		if(A[i]>max)
			max= A[i];
	}
	printf("\nMaximum Number : %d ",max);
	//min number
	int min=A[0];
	for(i=0; i<30; i++){
		if(A[i]<min)
			min=A[i];
	}
	printf("\nMinimum Number : %d ", min);}

