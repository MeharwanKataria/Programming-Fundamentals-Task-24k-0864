#include<stdio.h>
#include<string.h>
#define max 25
struct employee{
	char name[50];
	char dob[15];
	int id;
	char dep[20];
	double salary;
};
struct employee emp[max];
int employee_count=0;
void addemployee() {
	struct employee emp[max];
    if (employee_count < max) {
    	getchar();
        printf("Enter the Name: ");
        gets(emp[employee_count].name);
        printf("Enter the Date of Birth (DD/MM/YYYY): ");
       	gets(emp[employee_count].dob);
        printf("Enter the Employee ID: ");
        scanf("%d", &emp[employee_count].id);
        getchar();
        printf("Enter the Department Name: ");
        gets(emp[employee_count].dep);
        printf("Enter the Employee Salary: ");
        scanf("%lf", &emp[employee_count].salary);
        employee_count++;
        printf("Employee added successfully.\n");
    } else {
        printf("Cannot add more employees. Limit reached.\n");
    }
}

void displayemployee(){
	struct employee emp[max];
	if(employee_count==0) {
	printf("No Employee added.\n");
	return;}
	else{
		printf("Employee list\n");
		for(int i=0;i<employee_count;i++){
			printf("Employee ID: %d\n",emp[i].id);
			printf("Employee Name : %s\n",emp[i].name);
			printf("Employee Birth Date: %s\n",emp[i].dob);
			printf("Employee Department: %s\n",emp[i].dep);
			printf("Employee Salary: %.2f\n",emp[i].salary);
		}
	}
}
void deleteemployee(){
	struct employee emp[max];
	int id;
	int found=0;
	printf("Enter the Employee ID you want to delete.");
	scanf("%d",&id);
	for(int i=0;i<employee_count;i++){
		if(emp[i].id==id){
			found=1;
			for(int j=i;j<employee_count-1;j++){
			emp[j]=emp[j+1];}
		}
		employee_count--;
		printf("Employee Details Deleted Successfully.");
		break;
	}
	
}
int main(){
	int choice;
	while(1){
		printf("============================\n");
		printf("Menu Option \n");
		printf("1.Add Employee\n");
		printf("2.Display Employee\n");
		printf("3.Delete Employee\n");
		printf("4.Exit\n");
		printf("Enter the Option.");
		scanf("%d",&choice);
		if(choice==1) addemployee();
		if(choice==2) displayemployee();
		if(choice==3) deleteemployee();
		if(choice==4) return 0;
	}
}

