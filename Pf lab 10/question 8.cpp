#include<stdio.h>
int main(){
	int A[6];
	for(int i=0;i<6;i++){
		scanf("%d",&A[i]);
	} printf("Original Matrix: \n");
	for (int i=0;i<6;i++){
		printf("%d ",A[i]);
	}
	printf("Sorted aray\n");
	for(int i=0;i<6;i++){
		if(A[i]%2==0 && A[i+1]%2!=0){
			int temp=A[i];
			A[i]=A[i+1];
			A[i+1]=temp;
		}
	}
		for(int i=0;i<6;i++){
		printf("%d ",A[i]);
	}}
	

