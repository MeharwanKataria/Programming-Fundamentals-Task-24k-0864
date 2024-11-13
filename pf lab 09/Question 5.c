#include<stdio.h>
#include<string.h>
int main(){//cipher cracker
	int i,j=0;
	char inputword[100];
	char key[100];
	printf("Enter the string:");
	gets(inputword);
	printf("Enter the Key:");
	gets(key);
	char ex_key[strlen(inputword)+1];
	for(i=0;i<strlen(inputword);i++){
		ex_key[i]= key[j];
		j++;
		if(j==strlen(key)){
		j=0;}
	}
	for(i=0; i<strlen(inputword); i++){
		if(inputword[i]!=' '){
		inputword[i] -=64;
		}
		ex_key[i] -=64;
		if(inputword[i]==' '){
			inputword[i]=20;
		}
		int ciph=inputword[i]+ ex_key[i];
		ciph=ciph%26;
		ciph+=64;
		printf("%c",ciph);
	}
	

}
