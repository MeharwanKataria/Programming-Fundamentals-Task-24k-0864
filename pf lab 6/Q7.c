#include<stdio.h>
int main(){
	int num,x,digi,sum=0;
	scanf("%d", &num);
	num=x;
	while(x!=0){
		digi=x%10;
		digi=digi*digi*digi;
		sum+=digi;
		x=x/10;
	} 
	if(sum==num){
		printf("The given number is armstrong");
	}
	else{
		printf("the given number is not armstrong");
	}
}
