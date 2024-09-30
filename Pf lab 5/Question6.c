#include<stdio.h>
int main(){
	int num,count;
	printf("Enter the Number:");
	scanf("%d",&num);
	if(num!=0){
		count+=1;
		num=num&(num-1);
	}
		if(num!=0){
		count+=1;
		num=num&(num-1);
	}
		if(num!=0){
		count+=1;
		num=num&(num-1);
	}
		if(num!=0){
		count+=1;
		num=num&(num-1);
	}
		if(num!=0){
		count+=1;
		num=num&(num-1);
	}
		if(num!=0){
		count+=1;
		num=num&(num-1);
	}
		if(num!=0){
		count+=1;
		num=num&(num-1);
	}
		if(num!=0){
		count+=1;
		num=num&(num-1);
	}
		if(num!=0){
		count+=1;
		num=num&(num-1);
	}
		if(num!=0){
		count+=1;
		num=num&(num-1);
	};
	printf("The number of 1s are %d",count);
	return 0;
}
