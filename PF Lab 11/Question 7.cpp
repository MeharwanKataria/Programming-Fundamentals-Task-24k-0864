#include <stdio.h>
#include <string.h>

#define MAX_DEPTS 5
#define MAX_COURSES 10

struct Course {
    int id;
    char name[50];
    int credits;
    int enrolledStudents;
};

struct Department {
    char name[50];
    struct Course courses[MAX_COURSES];
    int courseCount;
};

void addCourse(struct Department* dept) {
    if (dept->courseCount < MAX_COURSES) {
        struct Course* newCourse = &dept->courses[dept->courseCount];
        
        printf("\nEnter Course ID: ");
        scanf("%d", &newCourse->id);
        
        printf("Enter Course Name: ");
        getchar(); 
        fgets(newCourse->name, sizeof(newCourse->name), stdin);
        newCourse->name[strcspn(newCourse->name, "\n")] = '\0';

        printf("Enter Credits: ");
        scanf("%d", &newCourse->credits);
        
        printf("Enter Number of Enrolled Students: ");
        scanf("%d", &newCourse->enrolledStudents);

        dept->courseCount++;
    } else {
        printf("Maximum courses reached for this department.\n");
    }
}

void displayDepartment(struct Department dept) {
    printf("\nDepartment: %s\n", dept.name);
    printf("-----------------------------------\n");
    for (int i = 0; i < dept.courseCount; i++) {
        struct Course course = dept.courses[i];
        printf("Course ID: %d\n", course.id);
        printf("Course Name: %s\n", course.name);
        printf("Credits: %d\n", course.credits);
        printf("Enrolled Students: %d\n", course.enrolledStudents);
        printf("-----------------------------------\n");
    }
}

int calculateTotalCredits(struct Department dept) {
    int totalCredits = 0;
    for (int i = 0; i < dept.courseCount; i++) {
        struct Course course = dept.courses[i];
        totalCredits += course.credits * course.enrolledStudents;
    }
    return totalCredits;
}

int main() {
    struct Department departments[MAX_DEPTS];
    int deptCount = 0;
    int choice;

    while (1) {
        printf("\nUniversity Course Enrollment System\n");
        printf("1. Add Department\n");
        printf("2. Add Course to a Department\n");
        printf("3. Display Department Details\n");
        printf("4. Calculate Total Credits in Department\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                if (deptCount < MAX_DEPTS) {
                    printf("\nEnter Department Name: ");
                    getchar();  
                    fgets(departments[deptCount].name, sizeof(departments[deptCount].name), stdin);
                    departments[deptCount].name[strcspn(departments[deptCount].name, "\n")] = '\0';  
                    departments[deptCount].courseCount = 0;
                    deptCount++;
                    printf("Department added successfully.\n");
                } else {
                    printf("Maximum departments reached.\n");
                }
                break;

            case 2:
                if (deptCount > 0) {
                    int deptIndex;
                    printf("\nEnter the department number (0 to %d): ", deptCount - 1);
                    scanf("%d", &deptIndex);
                    if (deptIndex >= 0 && deptIndex < deptCount) {
                        addCourse(&departments[deptIndex]);
                    } else {
                        printf("Invalid department number.\n");
                    }
                } else {
                    printf("No departments available. Please add a department first.\n");
                }
                break;

            case 3:
                if (deptCount > 0) {
                    int deptIndex;
                    printf("\nEnter the department number (0 to %d): ", deptCount - 1);
                    scanf("%d", &deptIndex);
                    if (deptIndex >= 0 && deptIndex < deptCount) {
                        displayDepartment(departments[deptIndex]);
                    } else {
                        printf("Invalid department number.\n");
                    }
                } else {
                    printf("No departments available. Please add a department first.\n");
                }
                break;

            case 4:
                if (deptCount > 0) {
                    int deptIndex;
                    printf("\nEnter the department number (0 to %d): ", deptCount - 1);
                    scanf("%d", &deptIndex);
                    if (deptIndex >= 0 && deptIndex < deptCount) {
                        int totalCredits = calculateTotalCredits(departments[deptIndex]);
                        printf("\nTotal Credits for Students in Department of %s: %d\n", departments[deptIndex].name, totalCredits);
                    } else {
                        printf("Invalid department number.\n");
                    }
                } else {
                    printf("No departments available. Please add a department first.\n");
                }
                break;

            case 5:
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

