#include<stdio.h>
int sum(int n){
	if (n==0) return 0;
	int s= n%10+sum(n/10);
	return s;
}
int main(){
	int n;
	scanf("%d",&n);
	int result=sum(n);
	printf("%d",result);
}
