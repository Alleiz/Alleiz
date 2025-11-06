/*
Name:Alex Maingi
Reg No:CT101/G/26482/25
*/

#include <stdio.h>
#include <string.h>

#define FILENAME "results.dat"
#define NAME_SIZE 50

// i. Defines a structure to hold the student information.
typedef struct {
    char name[NAME_SIZE];
    int reg_number;
    int total_marks;
} Student;

// Function prototypes
void create_sample_file();
void read_and_display_records();

int main() {
    printf("--- University Student Results ---\n");

    // 1. Setup: Create a sample binary file first for testing
    create_sample_file();

    // 2. Main Task: Read and display the records
    read_and_display_records();

    return 0;
}

/**
 * Creates a sample binary file (results.dat) for the program to read.
 * This is necessary since the file does not exist initially.
 */
void create_sample_file() {
    FILE *file;
    // Sample data
    Student students[] = {
        {"Alice Wambui", 1001, 85},
        {"Johnson Kimani", 1002, 72},
        {"Alex Maingi", 1003, 91}
    };
    int num_students = sizeof(students) / sizeof(Student);

    // Open file in write-binary mode ("wb")
    file = fopen(FILENAME, "wb");
    if (file == NULL) {
        perror("Error creating sample file");
        exit(EXIT_FAILURE);
    }

    // Write the entire array of structures to the file
    if (fwrite(students, sizeof(Student), num_students, file) != num_students) {
        fprintf(stderr, "Error writing all records to sample file.\n");
    } else {
        printf("Setup complete: %d sample records written to '%s'.\n\n", num_students, FILENAME);
    }
    
    fclose(file);
}


/**
 * Reads all student records from the binary file and displays them.
 */
void read_and_display_records() {
    FILE *file;
    Student student;
    int records_read = 0;

    // Open file in read-binary mode ("rb")
    file = fopen(FILENAME, "rb");

    if (file == NULL) {
        perror("Error opening binary file for reading");
        return;
    }

    printf("--- Reading Student Records ---\n");
    printf("%-30s | %-15s\n", "Name", "Total Marks");
    printf("--------------------------------------------------\n");

    // ii. Reads all student records from the binary file
    // iii. Displays the name and marks of each student on the screen.
    // Loop until fread fails to read a full Student structure (i.e., reaches EOF)
    while (fread(&student, sizeof(Student), 1, file) == 1) {
        printf("%-30s | %-15d\n", student.name, student.total_marks);
        records_read++;
    }

    // Check for errors other than EOF (feof() is useful here, but not necessary 
    // if we rely on the fread return value)
    if (ferror(file)) {
        perror("\nError reading from binary file");
    } else if (records_read == 0) {
        printf("No records found in the file.\n");
    } else {
        printf("\nSuccessfully read and displayed %d records.\n", records_read);
    }

    // Close the file
    if (fclose(file) == EOF) {
        perror("Error closing file");
    }
}
