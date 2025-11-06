/*
Name:Alex Maingi
Reg No:CT101/G/26482/25
*/
#include <stdio.h>

#define FILENAME "borrowed_books.txt"
#define MAX_TITLE_LENGTH 100

// Function prototypes
void add_book_title();

int main() {
    printf("--- Library Book Tracker ---\n");
    add_book_title();
    return 0;
}

/**
 * Prompts the user for a book title and appends it to FILENAME.
 */
void add_book_title() {
    FILE *file;
    char title[MAX_TITLE_LENGTH];

    // Open the file in append mode ("a")
    // "a" creates the file if it doesn't exist and ensures existing content is preserved.
    file = fopen(FILENAME, "a");

    if (file == NULL) {
        perror("Error opening file for appending");
        return;
    }

    // i. The program should not delete existing records (achieved by using "a" mode)
    
    printf("Enter the title of the book borrowed (max %d chars):\n> ", MAX_TITLE_LENGTH - 2);

    // Use fgets to safely read input, including spaces
    if (fgets(title, MAX_TITLE_LENGTH, stdin) == NULL) {
        fprintf(stderr, "Input error or EOF reached.\n");
        fclose(file);
        return;
    }
    
    // Remove the trailing newline character added by fgets
    title[strcspn(title, "\n")] = 0; 

    // Check if the user entered an empty title
    if (strlen(title) == 0) {
        printf("Title cannot be empty. No record added.\n");
        fclose(file);
        return;
    }

    // Write the title followed by a newline character to the file
    fprintf(file, "%s\n", title);

    // Close the file
    if (fclose(file) == EOF) {
        perror("Error closing file");
        // We still proceed to the confirmation message
    } else {
        // ii. Display a confirmation message
        printf("\nSUCCESS: The title '%s' has been successfully stored in %s.\n", title, FILENAME);
    }
}
