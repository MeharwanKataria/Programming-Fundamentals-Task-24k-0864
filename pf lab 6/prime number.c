#include<stdio.h>
int main(){
    int n,count=0 ,i;
    printf("Enter the number:");
    scanf("%d",&n);
    for(i=2;i<n;i++){
    	if (n%i==0){
    		count++;
		}}
		if(count!=0){
			printf("The number is not prime:%d",n);
		}
		else{
			printf("The number is prime");
		}}
		
    	
