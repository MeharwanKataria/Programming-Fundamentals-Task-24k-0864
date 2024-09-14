#include<stdio.h>
int main(){
	int n;
	printf("enter time\n");
	scanf("%d",&n);
	if(n>=0&&n<=5){
		printf("Good night");
	}
	else if (n>=6 && n<=11){
		printf("Good Morning");
	}
	else if (n>=12 && n<=17){
		printf("Good After noon");
	}
	else if (n>=18 && n<=23){
		printf("Good Morning");
	}
	else {
		printf("invalid time");
	}
}
