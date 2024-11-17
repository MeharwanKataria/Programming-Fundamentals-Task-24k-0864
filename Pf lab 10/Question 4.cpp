#include <stdio.h>
#include <string.h>

#define MAX_PACKAGES 5

// Define the structure for a travel package
typedef struct {
    char name[50];
    char destination[50];
    int duration;       
    float cost;         
    int seatsAvailable;  
} TravelPackage;

// Function to display available packages
void displayPackages(TravelPackage packages[], int count) {
    printf("\nAvailable Travel Packages:\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("Package %d:\n", i + 1);
        printf("Name: %s\n", packages[i].name);
        printf("Destination: %s\n", packages[i].destination);
        printf("Duration: %d days\n", packages[i].duration);
        printf("Cost: $%.2f\n", packages[i].cost);
        printf("Seats Available: %d\n", packages[i].seatsAvailable);
        printf("---------------------------------------------------\n");
    }
}

void bookPackage(TravelPackage packages[], int count) {
    int choice;
    printf("\nEnter the package number to book (1-%d): ", count);
    scanf("%d", &choice);

    if (choice < 1 || choice > count) {
        printf("Invalid package number!\n");
        return;
    }

    // Adjust for 0-based indexing
    choice--;

    if (packages[choice].seatsAvailable > 0) {
        packages[choice].seatsAvailable--;
        printf("Booking successful! You have booked '%s'.\n", packages[choice].name);
    } else {
        printf("Sorry, no seats are available for this package.\n");
    }
}

int main() {
    TravelPackage packages[MAX_PACKAGES] = {
    {"Northern Escape", "Hunza Valley", 5, 45000.00, 5},    
    {"Mountain Adventure", "Skardu", 7, 65000.00, 5},          
    {"City Lights", "Karachi", 3, 20000.00, 5},                
    {"Historical Tour", "Lahore", 4, 30000.00, 5},             
    {"Desert Safari", "Cholistan Desert", 6, 40000.00, 5}       
};

    int choice;
    do {
        printf("\nTravel Package System\n");
        printf("1. Display Available Packages\n");
        printf("2. Book a Package\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayPackages(packages, MAX_PACKAGES);
                break;
            case 2:
                bookPackage(packages, MAX_PACKAGES);
                break;
            case 3:
                printf("Thank you for using the Travel Package System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

