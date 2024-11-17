#include <stdio.h>
#include <string.h>


#define MAX_EMPLOYEES 100

typedef struct {
    int employeeID;
    char name[50];
    char department[50];
    float salary;
} Employee;

void inputEmployeeDetails(Employee *employee, int index);
void displayAllEmployees(Employee employees[], int count);

int main() {
    int numEmployees;

    printf("How many employees would you like to enter? ");
    scanf("%d", &numEmployees);

    if (numEmployees <= 0 || numEmployees > MAX_EMPLOYEES) {
        printf("Invalid number of employees. Please enter a value between 1 and %d.\n", MAX_EMPLOYEES);
        return 1;
    }

    Employee employees[numEmployees];

    for (int i = 0; i < numEmployees; i++) {
        inputEmployeeDetails(&employees[i], i + 1);
    }

    displayAllEmployees(employees, numEmployees);

    return 0;
}

void inputEmployeeDetails(Employee *employee, int index) {
    printf("\n--- Enter details for Employee %d ---\n", index);

    printf("Employee ID: ");
    scanf("%d", &employee->employeeID);

    getchar();

    printf("Name: ");
    fgets(employee->name, sizeof(employee->name), stdin);
    employee->name[strcspn(employee->name, "\n")] = 0;

    printf("Department: ");
    fgets(employee->department, sizeof(employee->department), stdin);
    employee->department[strcspn(employee->department, "\n")] = 0;

    printf("Salary: ");
    scanf("%f", &employee->salary);
}

void displayAllEmployees(Employee employees[], int count) {
    printf("\n\n--- Employee Details ---\n");

    for (int i = 0; i < count; i++) {
        printf("\nEmployee %d:\n", i + 1);
        printf("  ID         : %d\n", employees[i].employeeID);
        printf("  Name       : %s\n", employees[i].name);
        printf("  Department : %s\n", employees[i].department);
        printf("  Salary     : %.2f\n", employees[i].salary);
    }
    printf("\n");
}

