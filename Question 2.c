#include<stdio.h>
int main(){
	int units;
	float  unitscost,billamount;
	printf("Enter the total number of units consumed\n");
	scanf("%d",&units);
	if(units<=30){
		unitscost=units*0.6;
	}
	else if(units>30 && units<=110){
		unitscost=(30*0.6)+((units-30)*0.85);
	}
	else if (units>110 && units<=210){
		unitscost=(30*0.6)+(80*0.85)+((units-110)*1.30);
	}
	else{
		unitscost=(30*0.6)+(80*0.85)+(110*1.30)+((units-210)*1.60);
	}
	billamount=unitscost+ (unitscost*0.15);
	printf("Total bill amount of electricity bill:%.2f\n",billamount);
	return 0;}
