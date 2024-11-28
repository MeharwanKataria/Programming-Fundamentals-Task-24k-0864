#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "books.txt"

// Structure to hold book information
struct Book {
    int bookID;
    char title[100];
    char author[100];
    int quantity;
    float price;
};

// Function to add a new book to the file
void addBook() {
    struct Book newBook;

    printf("\nEnter Book ID: ");
    scanf("%d", &newBook.bookID);

    // Check if book already exists by ID
    FILE *file = fopen(FILENAME, "r");
    if (file != NULL) {
        struct Book book;
        while (fscanf(file, "%d\n%99[^\n]\n%99[^\n]\n%d\n%f\n", &book.bookID, book.title, book.author, &book.quantity, &book.price) == 5) {
            if (book.bookID == newBook.bookID) {
                printf("Book ID already exists! Try again with a different ID.\n");
                fclose(file);
                return;
            }
        }
        fclose(file);
    }

    // Get book details
    printf("Enter Book Title: ");
    getchar();  // to consume the newline character
    fgets(newBook.title, 100, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0';  // Remove newline

    printf("Enter Book Author: ");
    fgets(newBook.author, 100, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0';  // Remove newline

    printf("Enter Book Quantity: ");
    scanf("%d", &newBook.quantity);
    if (newBook.quantity < 0) {
        printf("Invalid quantity! Setting it to 0.\n");
        newBook.quantity = 0;
    }

    printf("Enter Book Price: ");
    scanf("%f", &newBook.price);
    if (newBook.price < 0) {
        printf("Invalid price! Setting it to 0.\n");
        newBook.price = 0;
    }

    // Write the new book to the file
    file = fopen(FILENAME, "a");
    if (file != NULL) {
        fprintf(file, "%d\n%s\n%s\n%d\n%.2f\n", newBook.bookID, newBook.title, newBook.author, newBook.quantity, newBook.price);
        fclose(file);
        printf("Book added successfully!\n");
    } else {
        printf("Error opening file.\n");
    }
}

// Function to display all books in the library
void viewBooks() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No books available.\n");
        return;
    }

    struct Book book;
    while (fscanf(file, "%d\n%99[^\n]\n%99[^\n]\n%d\n%f\n", &book.bookID, book.title, book.author, &book.quantity, &book.price) == 5) {
        printf("\nBook ID: %d\n", book.bookID);
        printf("Title: %s\n", book.title);
        printf("Author: %s\n", book.author);
        printf("Quantity: %d\n", book.quantity);
        printf("Price: %.2f\n", book.price);
    }
    fclose(file);
}

// Function to search a book by its ID
void searchByID() {
    int searchID;
    printf("\nEnter Book ID to search: ");
    scanf("%d", &searchID);

    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No books available.\n");
        return;
    }

    struct Book book;
    int found = 0;
    while (fscanf(file, "%d\n%99[^\n]\n%99[^\n]\n%d\n%f\n", &book.bookID, book.title, book.author, &book.quantity, &book.price) == 5) {
        if (book.bookID == searchID) {
            printf("\nBook found:\n");
            printf("Book ID: %d\n", book.bookID);
            printf("Title: %s\n", book.title);
            printf("Author: %s\n", book.author);
            printf("Quantity: %d\n", book.quantity);
            printf("Price: %.2f\n", book.price);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Book not found!\n");
    }
    fclose(file);
}

// Function to update a book's quantity or price
void updateBook() {
    int updateID;
    printf("\nEnter Book ID to update: ");
    scanf("%d", &updateID);

    FILE *file = fopen(FILENAME, "r+");
    if (file == NULL) {
        printf("No books available.\n");
        return;
    }

    struct Book book;
    int found = 0;
    while (fscanf(file, "%d\n%99[^\n]\n%99[^\n]\n%d\n%f\n", &book.bookID, book.title, book.author, &book.quantity, &book.price) == 5) {
        if (book.bookID == updateID) {
            found = 1;

            printf("Current Quantity: %d. Enter new Quantity: ", book.quantity);
            scanf("%d", &book.quantity);
            if (book.quantity < 0) {
                printf("Invalid quantity! Setting it to 0.\n");
                book.quantity = 0;
            }

            printf("Current Price: %.2f. Enter new Price: ", book.price);
            scanf("%f", &book.price);
            if (book.price < 0) {
                printf("Invalid price! Setting it to 0.\n");
                book.price = 0;
            }

            fseek(file, -sizeof(book), SEEK_CUR);  // Move the file pointer to the beginning of the current record
            fprintf(file, "%d\n%s\n%s\n%d\n%.2f\n", book.bookID, book.title, book.author, book.quantity, book.price);
            printf("Book updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Book not found!\n");
    }

    fclose(file);
}

// Function to calculate the total inventory value
void calculateTotalValue() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No books available.\n");
        return;
    }

    struct Book book;
    float totalValue = 0;
    while (fscanf(file, "%d\n%99[^\n]\n%99[^\n]\n%d\n%f\n", &book.bookID, book.title, book.author, &book.quantity, &book.price) == 5) {
        totalValue += book.quantity * book.price;
    }

    printf("\nTotal Inventory Value: %.2f\n", totalValue);
    fclose(file);
}

// Function to delete a book record
void deleteBook() {
    int deleteID;
    printf("\nEnter Book ID to delete: ");
    scanf("%d", &deleteID);

    FILE *file = fopen(FILENAME, "r");
    FILE *tempFile = fopen("temp.txt", "w");
    if (file == NULL || tempFile == NULL) {
        printf("Error opening files.\n");
        return;
    }

    struct Book book;
    int found = 0;
    while (fscanf(file, "%d\n%99[^\n]\n%99[^\n]\n%d\n%f\n", &book.bookID, book.title, book.author, &book.quantity, &book.price) == 5) {
        if (book.bookID == deleteID) {
            found = 1;
            continue;  // Skip writing this book to the temp file
        }
        fprintf(tempFile, "%d\n%s\n%s\n%d\n%.2f\n", book.bookID, book.title, book.author, book.quantity, book.price);
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(FILENAME);
        rename("temp.txt", FILENAME);
        printf("Book deleted successfully!\n");
    } else {
        printf("Book not found!\n");
    }
}

// Main function with menu
int main() {
    int choice;

    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Update Book\n");
        printf("5. Delete Book\n");
        printf("6. Calculate Total Inventory Value\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: searchByID(); break;
            case 4: updateBook(); break;
            case 5: deleteBook(); break;
            case 6: calculateTotalValue(); break;
            case 7: printf("Exiting program.\n"); return 0;
            default: printf("Invalid choice, try again.\n");
        }
    }

    return 0;
}

