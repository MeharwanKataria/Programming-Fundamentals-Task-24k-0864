#include <stdio.h>

struct phone {
    int areaCode;
    int exchange;
    int number;
};

void displayPhoneNumber(struct phone p) {
    printf("(%d) %d-%d\n", p.areaCode, p.exchange, p.number);
}

int main() {
    struct phone myNumber = {212, 767, 8900}; 
    struct phone yourNumber;

    // Input the phone number from the user
    printf("Enter area code: ");
    scanf("%d", &yourNumber.areaCode);

    printf("Enter exchange: ");
    scanf("%d", &yourNumber.exchange);

    printf("Enter number: ");
    scanf("%d", &yourNumber.number);

    // Display both phone numbers
    printf("My number is ");
    displayPhoneNumber(myNumber);

    printf("Your number is ");
    displayPhoneNumber(yourNumber);

    return 0;
}

