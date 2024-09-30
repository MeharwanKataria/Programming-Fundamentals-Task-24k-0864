#include<stdio.h>
int main(){
	char citizen;
	int age;
	printf("Enter the citizenship If pakistani Press Y if Not press N:");
	scanf("%c",&citizen);
	printf("Enter the age:");
	scanf("%d",&age);
	if (citizen=='Y'){
		if(age>=18){
			printf("you are eligible for vote");
		} 
	}
	else{
		printf("You are not eligible for vote");
	}
}
