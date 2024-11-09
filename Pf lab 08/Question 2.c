#include<stdio.h>
int main(){
	int i,j,k;
	int n=4;
	int A[n][n];
	printf("Enter the matrix of 4x4 :\n");
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			printf("enter the element of matrix:[%d][%d]: ",i+1,j+1);
			scanf("%d",&A[i][j]);
		}
	}
	printf("Before :\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%2d ",A[i][j]);
		}printf("\n");
	}
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
		if(A[i][j]<0){
			A[i][j]=0;}
		}
	}
	printf("After:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%2d ",A[i][j]);
		}printf("\n");
	}
}
