#include<stdio.h>
int main()
{
	int a=0 , b=1 , c , n , i;
	int count=0;
	printf("enter the value of N :");
	scanf("%d",&n);
	for(i=2;i<n;i++){
    	if (n%i==0){
    		count++;
		}}
		if(count!=0){
			printf("The number is not prime:%d",n);
		}
		else{
		printf("The number is prime\n");
		printf("The fibanocci series:");
		for(i=1;i<=n;i++){
		c=a+b;
		printf("%d ",a);
		a=b;
		b=c;
	}
		}}
			

