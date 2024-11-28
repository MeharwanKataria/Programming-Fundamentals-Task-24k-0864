#include<stdio.h>
struct rectangle{
	float lenght;
	float breadth;
};
struct rectangle r;
calculater(struct rectangle r){
	double per=2*(r.lenght + r.breadth);
	double area=r.lenght*r.breadth;
	printf("perimeter =%.2f\n area= %.2f",per,area);
}
check(struct rectangle r){
	if(r.lenght > 0.0 && r.breadth > 0.0 && r.lenght < 20.0 && r.breadth < 20.0){
		printf("The given length and breadth is in Condition\n");
		calculater(r);
	}
	else{
		printf("The given length and breadth is not in condition\n");
		calculater(r);
	}
}
int main(){
	printf("Enter the lenght of rectangle : ");
	scanf("%f",&r.lenght);
	printf("Enter the breadth of rectangle : ");
	scanf("%f",&r.breadth);
	check(r);
	
}
