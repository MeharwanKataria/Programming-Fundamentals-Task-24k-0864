int main() {
    int x;
    printf("Enter your marks\n");
    scanf("%d", &x);
    if (x < 0 && x > 100) {
        printf("wrong marks entry");
    } else if (x >= 90) {
        printf("your grade is A");
    } else if (x >= 80) {
        printf("your grade is B");
    } else if (x >= 70) {
        printf("your grade is C");
    } else if (x >= 60) {
        printf("your grade is D");
    } else {
        printf("your grade is F");
    }

    return 0;
}
