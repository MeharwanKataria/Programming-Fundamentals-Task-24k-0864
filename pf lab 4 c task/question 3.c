#include<stdio.h>
int main(){
	int cost,discount,finalamount;
	printf("Enter the cost of shopping");
	scanf("%d",&cost);
	printf("the cost of the shopping before the discount:%d\n",cost);
	if (cost<1500){
		discount=cost*0.07;
	}
	else if(cost>=1500&&cost<=3000)
	{
		discount=cost*0.12;
	}
	else if(cost>3000 && cost<=5000){
		discount=cost*0.22;
	}
	else if (cost>5000){
		discount=cost*0.3;
	}
	else {
		printf("enter the correct cost of the shopping");
}
	printf( "the amount you saved: %d\n",discount);
	finalamount=cost-discount;
	printf("the amount after discount:%d\n",finalamount);
return 0;
}
	
