#include<stdio.h>
int main(){
	int i;
	int j;
	int A[12];
	for (i=0;i<12;i++){
		printf("Enter the number in array");
		scanf("%d",&A[i]);}
		printf("Input numbers array:{ ");
	for(i=0;i<12;i++){
		printf("%d ",A[i]);
	}printf("}");
	printf("\npaired sum array:{ ");
	int ps[12/2];
	for(i=0,j=0;j<12,i<12/2;j=j+2,i++){
		ps[i]=A[j]+A[j+1];
		printf("%d ",ps[i]);}
		printf("}");}
