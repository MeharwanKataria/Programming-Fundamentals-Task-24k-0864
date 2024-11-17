#include <stdio.h>
#include <stdlib.h>

struct Flight {
    int number; 
    char departureCity[100];
    char arrivalCity[100];
    int departureTime;
    int arrivalTime;  
    int availableSeats;
};

int main() {
    struct Flight flights[3]; 
    int totalFlights = 3;  

    // Input flight details
    for (int i = 0; i < totalFlights; i++) {
        printf("---------------------------- Flight Entry %d ----------------------------\n", i + 1);
        printf("Enter flight number: ");
        scanf("%d", &flights[i].number);
        printf("Departure city: ");
        scanf(" %s", flights[i].departureCity);
        printf("Arrival city: ");
        scanf(" %s", flights[i].arrivalCity); 
        printf("Departure Time (24-hour format): ");
        scanf("%d", &flights[i].departureTime); 
        printf("Arrival Time (24-hour format): ");
        scanf("%d", &flights[i].arrivalTime); 
        printf("Enter the number of available seats: ");
        scanf("%d", &flights[i].availableSeats);
    }

    // Main booking logic
    int continueBooking = 1;
    printf("Enter 0 to exit or any other number to continue: ");
    scanf("%d", &continueBooking);

    while (continueBooking != 0) {
        // Display available flights
        printf("------------------------------- Available Flights -------------------------------\n");
        printf("Flight Number\tDeparture City\tDeparture Time\tArrival City\tArrival Time\tAvailable Seats\n");
        
        for (int i = 0; i < totalFlights; i++) {
            printf("%d\t\t%s\t\t%d\t\t%s\t\t%d\t\t%d\n",
                   flights[i].number,
                   flights[i].departureCity,
                   flights[i].departureTime,
                   flights[i].arrivalCity,
                   flights[i].arrivalTime,
                   flights[i].availableSeats);
        }

        int selectedFlightNumber;
        printf("Enter the Flight Number to book a seat: ");
        scanf("%d", &selectedFlightNumber);

        // Check if the flight number is valid and seats are available
        int flightFound = 0;
        for (int i = 0; i < totalFlights; i++) {
            if (flights[i].number == selectedFlightNumber) {
                flightFound = 1;
                if (flights[i].availableSeats > 0) {
                    flights[i].availableSeats--;
                    printf("Seat booked successfully on flight %d. Available seats now: %d\n", selectedFlightNumber, flights[i].availableSeats);
                } else {
                    printf("No available seats on flight %d.\n", selectedFlightNumber);
                }
                break;
            }
        }
        
        if (!flightFound) {
            printf("Flight number %d not found.\n", selectedFlightNumber);
        }

        printf("Enter 0 to exit or any other number to continue: ");
        scanf("%d", &continueBooking);
    }

    return 0;
}

