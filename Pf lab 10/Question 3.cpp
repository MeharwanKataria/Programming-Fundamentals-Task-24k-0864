#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#define MAX_CARS 100 // Maximum number of cars

// Structure to store car details
struct Car {
    char make[50];
    char model[50];
    int year;
    float price;
    float mileage;
}; 

void addCar(Car cars[], int *carCount);
void displayCars(const Car cars[], int carCount);
void searchCars(const Car cars[], int carCount);

int main() {
    Car cars[MAX_CARS];
    int carCount = 0; 
    int choice;

    do {
        printf("\n--- Car Dealership Menu ---\n");
        printf("1. Add a new car\n");
        printf("2. Display all cars\n");
        printf("3. Search for cars by make or model\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
		
        switch (choice) {
            case 1:
                addCar(cars, &carCount);
                break;
            case 2:
                displayCars(cars, carCount);
                break;
            case 3:
                searchCars(cars, carCount);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
void addCar(Car cars[], int *carCount) {
    if (*carCount >= MAX_CARS) {
        printf("Car dealership is full! Cannot add more cars.\n");
        return;
    }

    printf("Enter car make: ");
    scanf("%s", cars[*carCount].make);
    printf("Enter car model: ");
    scanf("%s", cars[*carCount].model);
    printf("Enter car year: ");
    scanf("%d", &cars[*carCount].year);
    printf("Enter car price: ");
    scanf("%f", &cars[*carCount].price);
    printf("Enter car mileage: ");
    scanf("%f", &cars[*carCount].mileage);

    (*carCount)++;
    printf("Car added successfully!\n");
}

// Function to display all cars
void displayCars(const Car cars[], int carCount) {
    if (carCount == 0) {
        printf("No cars available in the dealership.\n");
        return;
    }

    printf("\n--- List of Available Cars ---\n");
    for (int i = 0; i < carCount; i++) {
        printf("Car %d:\n", i + 1);
        printf("  Make: %s\n", cars[i].make);
        printf("  Model: %s\n", cars[i].model);
        printf("  Year: %d\n", cars[i].year);
        printf("  Price: $%.2f\n", cars[i].price);
        printf("  Mileage: %.2f miles\n", cars[i].mileage);
        printf("----------------------\n");
    }
}
void searchCars(const Car cars[], int carCount) {
    char searchTerm[50];
    int found = 0;

    if (carCount == 0) {
        printf("No cars available in the dealership.\n");
        return;
    }

    printf("Enter make or model to search for: ");
    scanf("%s", searchTerm);

    printf("\n--- Search Results ---\n");
    for (int i = 0; i < carCount; i++) {
        if (strstr(cars[i].make, searchTerm) || strstr(cars[i].model, searchTerm)) {
            printf("Car %d:\n", i + 1);
            printf("  Make: %s\n", cars[i].make);
            printf("  Model: %s\n", cars[i].model);
            printf("  Year: %d\n", cars[i].year);
            printf("  Price: $%.2f\n", cars[i].price);
            printf("  Mileage: %.2f miles\n", cars[i].mileage);
            printf("----------------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No cars found matching '%s'.\n", searchTerm);
    }
}

