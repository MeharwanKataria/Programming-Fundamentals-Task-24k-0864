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
	printf("Original Matrix:\n");
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			printf("%3d ",A[i][j]);
		}printf("\n");
	}
	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				if(A[i][k]>A[j][k]){
					int temp=A[i][k];
					A[i][k]=A[j][k];
					A[j][k]=temp;
				}
			}
		}
	}
	printf("After sorting in ascending order:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%3d ",A[i][j]);
		}printf("\n");
	}
	
}
