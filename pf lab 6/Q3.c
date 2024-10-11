#include<stdio.h>
int main(){
	int x;
	do{
		printf("enter the number:");
		scanf("%d",&x);
		if(x<0)printf("NO\n");
	}while(x<0);
	printf("Hell yeah~<_%d_>~",x);
}
