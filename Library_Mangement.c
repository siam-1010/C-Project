#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 100

typedef struct {
    int id;
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int year;
} Book;

Book library[MAX_BOOKS];
int book_count = 0;

void addBook() {
    if (book_count >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }

    Book newBook;
    newBook.id = book_count + 1;

    printf("Enter book title: ");
    getchar(); // To consume the newline character left by previous input
    fgets(newBook.title, TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // Remove newline character

    printf("Enter book author: ");
    fgets(newBook.author, AUTHOR_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // Remove newline character

    printf("Enter publication year: ");
    scanf("%d", &newBook.year);

    library[book_count] = newBook;
    book_count++;

    printf("Book added successfully!\n");
}

void displayBooks() {
    if (book_count == 0) {
        printf("No books available in the library.\n");
        return;
    }

    printf("\nLibrary Books:\n");
    printf("ID\tTitle\t\tAuthor\t\tYear\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < book_count; i++) {
        printf("%d\t%s\t\t%s\t\t%d\n", library[i].id, library[i].title, library[i].author, library[i].year);
    }
}

void searchBook() {
    if (book_count == 0) {
        printf("No books available in the library.\n");
        return;
    }

    char searchTitle[TITLE_LENGTH];
    printf("Enter the title of the book to search: ");
    getchar(); // To consume the newline character left by previous input
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline character

    for (int i = 0; i < book_count; i++) {
        if (strcmp(library[i].title, searchTitle) == 0) {
            printf("Book found:\n");
            printf("ID: %d\nTitle: %s\nAuthor: %s\nYear: %d\n", library[i].id, library[i].title, library[i].author, library[i].year);
            return;
        }
    }

    printf("Book not found.\n");
}

void deleteBook() {
    if (book_count == 0) {
        printf("No books available in the library.\n");
        return;
    }

    int id;
    printf("Enter the ID of the book to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < book_count; i++) {
        if (library[i].id == id) {
            for (int j = i; j < book_count - 1; j++) {
                library[j] = library[j + 1];
            }
            book_count--;
            printf("Book deleted successfully.\n");
            return;
        }
    }

    printf("Book with ID %d not found.\n", id);
}

int main() {
    int choice;

    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}