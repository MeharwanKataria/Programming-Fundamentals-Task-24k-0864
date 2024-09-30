#include<stdio.h>
int main(){
	int num;
	printf("Enter number:");
	scanf("%d",&num);
	((num&1)==0)?printf("%d is the even number",num):printf("%d is the odd number",num);
}
