#include<stdio.h>
int main(){
	float percent;
	printf("Enter the percentage:");
	scanf("%f",&percent);
	(percent>=90) ? printf("your grade is A"):
	(percent>=80 && percent<90) ? printf("your grade is B"):
	(percent>=70 && percent<80) ? printf("your grade is C"):
	(percent>=60 && percent<70) ? printf("your grade is D"):printf("Your grade is F");
}
