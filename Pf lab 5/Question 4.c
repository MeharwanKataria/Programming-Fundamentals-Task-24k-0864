#include<stdio.h>
int main(){
	int tp; //membership
	char mship;	 //total purchase
	printf("Enter the total purchase amount$:");
	scanf("%d",&tp);
	getchar();
	printf("Check status of membership (Y for yes, N for NO):");
	scanf("%c",&mship);
	(tp>100 && mship=='Y') ?printf("you are eligible for discount,discount is applied."):printf("You are not eligible for discount");
}
