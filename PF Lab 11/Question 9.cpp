#include <stdio.h>
#include <string.h>

#define MAX_DEPARTMENTS 5
#define MAX_COURSES 3
#define MAX_STUDENTS 10

struct Student {
    int studentID;
    char name[100];
    int age;
};

struct Instructor {
    int instructorID;
    char name[100];
    char department[50];
};

struct Course {
    int courseID;
    char courseName[100];
    struct Instructor instructor;
    struct Student students[MAX_STUDENTS];
    int numStudents;
};

struct Department {
    int departmentID;
    char departmentName[100];
    struct Course courses[MAX_COURSES];
    int numCourses;
};

void inputStudent(struct Student *student) {
    printf("Enter Student ID: ");
    scanf("%d", &student->studentID);
    printf("Enter Student Name: ");
    getchar();
    fgets(student->name, sizeof(student->name), stdin);
    student->name[strcspn(student->name, "\n")] = 0;
    printf("Enter Student Age: ");
    scanf("%d", &student->age);
}

void inputInstructor(struct Instructor *instructor) {
    printf("Enter Instructor ID: ");
    scanf("%d", &instructor->instructorID);
    printf("Enter Instructor Name: ");
    getchar();
    fgets(instructor->name, sizeof(instructor->name), stdin);
    instructor->name[strcspn(instructor->name, "\n")] = 0;
    printf("Enter Instructor Department: ");
    fgets(instructor->department, sizeof(instructor->department), stdin);
    instructor->department[strcspn(instructor->department, "\n")] = 0;
}

void inputCourse(struct Course *course) {
    printf("Enter Course ID: ");
    scanf("%d", &course->courseID);
    printf("Enter Course Name: ");
    getchar();
    fgets(course->courseName, sizeof(course->courseName), stdin);
    course->courseName[strcspn(course->courseName, "\n")] = 0;
    inputInstructor(&course->instructor);
    printf("Enter number of students enrolled in this course: ");
    scanf("%d", &course->numStudents);
    for (int i = 0; i < course->numStudents; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);
        inputStudent(&course->students[i]);
    }
}

void inputDepartment(struct Department *department) {
    printf("Enter Department ID: ");
    scanf("%d", &department->departmentID);
    printf("Enter Department Name: ");
    getchar();
    fgets(department->departmentName, sizeof(department->departmentName), stdin);
    department->departmentName[strcspn(department->departmentName, "\n")] = 0;
    printf("Enter number of courses offered by the department: ");
    scanf("%d", &department->numCourses);
    for (int i = 0; i < department->numCourses; i++) {
        printf("\nEnter details for Course %d:\n", i + 1);
        inputCourse(&department->courses[i]);
    }
}

void displayStudent(struct Student student) {
    printf("Student ID: %d\n", student.studentID);
    printf("Student Name: %s\n", student.name);
    printf("Student Age: %d\n", student.age);
}

void displayInstructor(struct Instructor instructor) {
    printf("Instructor ID: %d\n", instructor.instructorID);
    printf("Instructor Name: %s\n", instructor.name);
    printf("Instructor Department: %s\n", instructor.department);
}

void displayCourse(struct Course course) {
    printf("\nCourse ID: %d\n", course.courseID);
    printf("Course Name: %s\n", course.courseName);
    displayInstructor(course.instructor);
    printf("Number of Students Enrolled: %d\n", course.numStudents);
    for (int i = 0; i < course.numStudents; i++) {
        printf("\nDetails of Student %d:\n", i + 1);
        displayStudent(course.students[i]);
    }
}

void displayDepartment(struct Department department) {
    printf("\nDepartment ID: %d\n", department.departmentID);
    printf("Department Name: %s\n", department.departmentName);
    printf("Number of Courses Offered: %d\n", department.numCourses);
    for (int i = 0; i < department.numCourses; i++) {
        printf("\nDetails of Course %d:\n", i + 1);
        displayCourse(department.courses[i]);
    }
}

int main() {
    struct Department departments[MAX_DEPARTMENTS];
    int numDepartments;

    printf("Enter number of departments: ");
    scanf("%d", &numDepartments);

    for (int i = 0; i < numDepartments; i++) {
        printf("\nEnter details for Department %d:\n", i + 1);
        inputDepartment(&departments[i]);
    }

    printf("\nUniversity Information:\n");
    for (int i = 0; i < numDepartments; i++) {
        printf("\nDetails of Department %d:\n", i + 1);
        displayDepartment(departments[i]);
    }

    return 0;
}

