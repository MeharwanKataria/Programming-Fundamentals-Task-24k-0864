#include<stdio.h>
int sum(int n){
	if (n==0) return 0;
	int s= n%10+sum(n/10);
	return s;
}
int main(){
	int n;
	printf("Enter the numbers: ");
	scanf("%d",&n);
	int result=sum(n);
	printf("sum of digits = %d",result);
}
