#include<stdio.h>
int main(){
	int i,num,result=1;
	printf("Enter  the number:");
	scanf("%d",&num);
	for (i=1;i<=num;i++){
		result*=i;
	}
	printf("%d!=%d",num,result);
}
