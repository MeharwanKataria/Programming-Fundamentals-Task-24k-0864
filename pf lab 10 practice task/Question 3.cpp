#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 5

struct Book {
    const char* title;  
    const char* author;  
    int ISBN;
    int publicationYear;
    int isAvailable;
};

struct Book library[MAX_BOOKS];
int currentBookCount = 0;  // To keep track of the number of books added

void addBook(int index, const char* title, const char* author, int ISBN, int publicationYear) {
    library[index].title = title;
    library[index].author = author;
    library[index].ISBN = ISBN;
    library[index].publicationYear = publicationYear;
    library[index].isAvailable = 1;
}

void addNewBook() {
    if (currentBookCount < MAX_BOOKS) {
        char title[100];
        char author[100];
        int ISBN, publicationYear;

        printf("Enter book title: ");
        getchar();  // To clear any leftover newline
        fgets(title, sizeof(title), stdin);
        title[strcspn(title, "\n")] = 0;  // Remove newline character

        printf("Enter author: ");
        fgets(author, sizeof(author), stdin);
        author[strcspn(author, "\n")] = 0;  // Remove newline character

        printf("Enter ISBN: ");
        scanf("%d", &ISBN);

        printf("Enter publication year: ");
        scanf("%d", &publicationYear);

        addBook(currentBookCount, title, author, ISBN, publicationYear);
        currentBookCount++;

        printf("Book added successfully!\n");
    } else {
        printf("Library is full, cannot add more books.\n");
    }
}

void searchBook(const char* query) {
    for (int i = 0; i < currentBookCount; i++) {
        if (strstr(library[i].title, query) != NULL || strstr(library[i].author, query) != NULL) {
            printf("Book found: %s by %s\n", library[i].title, library[i].author);
            printf("ISBN: %d, Year: %d, Status: %s\n", library[i].ISBN, library[i].publicationYear,
                   library[i].isAvailable ? "Available" : "Checked out");
            return;
        }
    }
    printf("No books found matching '%s'.\n", query);
}

void updateAvailability(int ISBN, int status) {
    for (int i = 0; i < currentBookCount; i++) {
        if (library[i].ISBN == ISBN) {
            library[i].isAvailable = status;
            printf("Book '%s' is now %s.\n", library[i].title, status ? "available" : "checked out");
            return;
        }
    }
    printf("Book with ISBN %d not found.\n", ISBN);
}

int main() {
    int choice;
    do {
        printf("\nLibrary Menu:\n");
        printf("1. Add a new book\n");
        printf("2. Search for a book\n");
        printf("3. Check-out a book\n");
        printf("4. Return a book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            addNewBook();
        } else if (choice == 2) {
            char query[100];
            printf("Enter book title or author to search: ");
            getchar();  // To consume the newline character after scanf
            fgets(query, sizeof(query), stdin);
            query[strcspn(query, "\n")] = 0;  // Remove newline
            searchBook(query);
        } else if (choice == 3) {
            int ISBN;
            printf("Enter ISBN of the book to check-out: ");
            scanf("%d", &ISBN);
            updateAvailability(ISBN, 0);  // Set to checked out (0)
        } else if (choice == 4) {
            int ISBN;
            printf("Enter ISBN of the book to return: ");
            scanf("%d", &ISBN);
            updateAvailability(ISBN, 1);  // Set to available (1)
        }

    } while (choice != 5);

    return 0;
}

