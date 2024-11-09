#include<stdio.h>
int main(){
	int i,j;
	int m,n;
	printf("Enter the number of rows and column");
	scanf("%d %d",&m,&n);
	
	int A[m][n];
	printf("Enter the element of Matrix A\n");
	for (i=0;i<m;i++){
		for (j=0;j<n;j++){
			printf("enter the element of matrix:[%d][%d]: ",i+1,j+1);
			scanf("%d",&A[i][j]);
		}
	}
		int B[m][n];
		printf("Enter the element of Matrix B\n");
	for (i=0;i<m;i++){
		for (j=0;j<n;j++){
			printf("enter the element of matrix:[%d][%d]: ",i+1,j+1);
			scanf("%d",&B[i][j]);
		}
	}
	printf("Given Matrix:\n");
		for (i=0;i<m;i++){
		for (j=0;j<n;j++){
			printf("%d " ,A[i][j]);
		}printf("\n");
	}
	
		printf("Given Matrix:\n");
		for (i=0;i<m;i++){
		for (j=0;j<n;j++){
			printf("%d ",B[i][j]);
		}printf("\n");
	}
	int C[m][n];
	printf("Resultant Vector\n");
	for (i=0;i<m;i++){
		for (j=0;j<n;j++){
			C[i][j]=A[i][j]+B[i][j];
			printf("%3d ",C[i][j]);
		}printf("\n");
	}}	
