#include<stdio.h>
int main(){
	FILE *p1=fopen("ABC.txt","r");
	char a[100];
	int count=1;
	while(fgets(a,100,p1)!=NULL){
		printf("%d:%s",count,a);
		 count++;
	}
}
