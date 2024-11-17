#include<stdio.h>
#include<string.h>
char revstr(char str[],int a,int b){
	if (a>=b) return 0;
	int temp=str[a];
	str[a]=str[b];
	str[b]=temp;
	revstr(str,a+1,b-1);
}
int main(){
	char str[100];
	printf("Enter the string: \n");
	fgets(str,100,stdin);
	int b=strlen(str)-1;
	revstr(str,0,b);
	printf("Reverse string : \n");
	puts(str);
}
