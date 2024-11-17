#include<stdio.h>
void percentageprint(int n,int p){
	if(p>100) return;
	printf("%d percent of %d = %.2f\n",p,n,((n*p)/100.0));
	percentageprint(n,p+1);
}
int main(){
	int n;
	printf("Enter the number: ");
	scanf("%d",&n);
	percentageprint(n,1);
}
