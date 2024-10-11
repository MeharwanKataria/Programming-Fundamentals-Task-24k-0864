#include<stdio.h>
int main (){
	int n, sum=0;
	do{
		printf("Enter the number\n");
		scanf("%d",&n);
		sum+=n;
		printf("sum = %d\n", sum);
	}while(n!=0); 
	printf("you have enter the zero so loop is over");
}
