/*
Name:Alex Maingi
Reg No:CT101/G/26482/25
*/
#include <stdio.h>
#define FILENAME "sales.txt"

// Function prototypes
void create_sample_sales_file();
void process_sales_transactions();

int main() {
    printf("--- Retail Shop Daily Sales ---\n");

    // 1. Setup: Create a sample sales file first for testing
    create_sample_sales_file();

    // 2. Main Task: Read and calculate the total
    process_sales_transactions();

    return 0;
}

/**
 * Creates a sample text file (sales.txt) for the program to read.
 * This is necessary since the file does not exist initially.
 */
void create_sample_sales_file() {
    FILE *file;
    
    // Open file in write mode ("w") - this will overwrite if it exists
    file = fopen(FILENAME, "w");
    if (file == NULL) {
        perror("Error creating sample file");
        exit(EXIT_FAILURE);
    }

    // Write sample transaction amounts, one per line
    fprintf(file, "150.75\n");
    fprintf(file, "22.50\n");
    fprintf(file, "450.00\n");
    fprintf(file, "99.99\n");
    
    fclose(file);
    printf("Setup complete: Sample sales data written to '%s'.\n\n", FILENAME);
}


/**
 * Reads all transaction amounts from the file, calculates the total, and displays it.
 */
void process_sales_transactions() {
    FILE *file;
    double transaction_amount;
    double total_sales = 0.0;
    int transaction_count = 0;

    // Open file in read mode ("r")
    file = fopen(FILENAME, "r");

    if (file == NULL) {
        perror("Error opening sales file for reading");
        return;
    }

    // i. Reads all transactions from the file.
    // Use a loop with fscanf to read one double value at a time.
    // fscanf returns 1 if it successfully read one item, or EOF otherwise.
    printf("--- Processing Sales Transactions ---\n");
    printf("Transactions Read:\n");

    while (fscanf(file, "%lf", &transaction_amount) == 1) {
        // ii. Calculates and displays the total sales for the day.
        total_sales += transaction_amount;
        transaction_count++;
        printf("  - $%.2lf\n", transaction_amount);
    }

    // iii. Ensures the file is properly closed after reading.
    if (fclose(file) == EOF) {
        perror("\nError closing file");
    } else {
        printf("\nFile '%s' successfully closed.\n", FILENAME);
    }
    
    // Check if the loop terminated due to an error other than EOF
    if (transaction_count == 0 && !feof(file)) {
        fprintf(stderr, "\nAn error occurred while reading the file (e.g., non-numeric data).\n");
    }
    
    // Display final result
    printf("\n--- Daily Sales Summary ---\n");
    printf("Total Transactions Processed: %d\n", transaction_count);
    printf("TOTAL SALES FOR THE DAY: $%.2lf\n", total_sales);
}
