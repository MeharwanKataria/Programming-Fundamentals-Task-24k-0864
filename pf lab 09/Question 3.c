#include<stdio.h>
#include<string.h>
int main(){
	char username[]="admin";
	char pass[]="1234";
	int a=strlen(username);
	int b=strlen(pass);
	char userin[a];
	char passin[b];
	printf("Enter the username: ");
	scanf("%s",userin);
	printf("Enter the password: ");
	scanf("%s",passin);
	int c=strcmp(username,userin);
	int d=strcmp(pass,passin);
	if(c==0&&d==0) printf("Access Granted");
	else printf("Access denied");
}
