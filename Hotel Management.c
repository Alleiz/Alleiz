/*
Name:Alex Maingi
Reg No:CT101/G/26482/25
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void weeklyRevenueTracker();
void roomOccupancyTracker();
void multipleBranchesOccupancy();

int main() {
    // Seed the random number generator for occupancy simulation
    srand(time(0)); 

    printf("--- Hotel Management System Using Arrays ---\n\n");

    weeklyRevenueTracker();
    printf("\n"); // Add a newline for separation
    
    roomOccupancyTracker();
    printf("\n");
    
    multipleBranchesOccupancy();
    
    return 0;
}

// --- 1D Array - Weekly Revenue Tracker ---
void weeklyRevenueTracker() {
    printf("## 1D Array - Weekly Revenue Tracker\n");
    // 1. Use a 1D array revenue[7]
    float revenue[7]; 
    float total_revenue = 0.0;
    float average_daily_revenue;
    char *days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    // 2. Input the revenue for each day
    for (int i = 0; i < 7; i++) {
        printf("Enter revenue for %s: $", days[i]);
        // Note: Using %f for float input
        if (scanf("%f", &revenue[i]) != 1) { 
            printf("Invalid input. Exiting revenue tracker.\n");
            // Clear input buffer for robustness
            while (getchar() != '\n'); 
            return;
        }
        // Calculate the total weekly revenue
        total_revenue += revenue[i]; 
    }

    // 3. Calculate and display:
    
    // The average daily revenue
    average_daily_revenue = total_revenue / 7.0;

    printf("\n--- Weekly Revenue Summary ---\n");
    // The total weekly revenue
    printf("Total Weekly Revenue: $%.2f\n", total_revenue); 
    printf("Average Daily Revenue: $%.2f\n", average_daily_revenue);
}

// --- 2D Array - Room Occupancy (One Branch) ---
void roomOccupancyTracker() {
    printf("## 2D Array - Room Occupancy (One Branch)\n");
    const int FLOORS = 5;
    const int ROOMS_PER_FLOOR = 10;
    // 1. Use a 2D array occupancy[5][10]
    int occupancy[FLOORS][ROOMS_PER_FLOOR]; 
    int occupied_count, vacant_count;

    // 2. Input random occupancy data (simulate input)
    printf("Simulating random occupancy data (1=occupied, 0=vacant)...\n");
    for (int i = 0; i < FLOORS; i++) {
        for (int j = 0; j < ROOMS_PER_FLOOR; j++) {
            // Assign random occupancy (1 or 0)
            occupancy[i][j] = rand() % 2; 
        }
    }
    
    // Display the simulated occupancy matrix for reference
    printf("\n--- Occupancy Matrix (Floor x Room) ---\n");
    printf("Rooms -> 0 1 2 3 4 5 6 7 8 9\n");
    for (int i = 0; i < FLOORS; i++) {
        printf("Floor %d: ", i + 1);
        for (int j = 0; j < ROOMS_PER_FLOOR; j++) {
            printf("%d ", occupancy[i][j]);
        }
        printf("\n");
    }

    // 3. Display the number of occupied and vacant rooms per floor
    printf("\n--- Occupancy by Floor ---\n");
    for (int i = 0; i < FLOORS; i++) {
        occupied_count = 0;
        vacant_count = 0;
        for (int j = 0; j < ROOMS_PER_FLOOR; j++) {
            if (occupancy[i][j] == 1) {
                occupied_count++;
            } else {
                vacant_count++;
            }
        }
        printf("Floor %d: Occupied = %d, Vacant = %d\n", i + 1, occupied_count, vacant_count);
    }
}

// --- 3D Array - Multiple Branches ---
void multipleBranchesOccupancy() {
    printf("## 3D Array - Multiple Branches\n");
    const int BRANCHES = 3;
    const int FLOORS = 5;
    const int ROOMS_PER_FLOOR = 10;
    // 1. Use a 3D array chain[3][5][10]
    int chain[BRANCHES][FLOORS][ROOMS_PER_FLOOR]; 
    int total_occupied_rooms = 0;

    // 2. Assign random occupancy (1 or 0) to each room.
    printf("Simulating random occupancy for 3 branches...\n");
    for (int b = 0; b < BRANCHES; b++) { // Branches
        for (int f = 0; f < FLOORS; f++) { // Floors
            for (int r = 0; r < ROOMS_PER_FLOOR; r++) { // Rooms
                // Assign random occupancy (1 or 0)
                chain[b][f][r] = rand() % 2; 
            }
        }
    }

    // 3. Calculate and display the total number of occupied rooms across all branches.
    for (int b = 0; b < BRANCHES; b++) {
        int occupied_in_branch = 0;
        for (int f = 0; f < FLOORS; f++) {
            for (int r = 0; r < ROOMS_PER_FLOOR; r++) {
                if (chain[b][f][r] == 1) {
                    // Accumulate total occupied rooms
                    total_occupied_rooms++; 
                    occupied_in_branch++;
                }
            }
        }
        printf("Branch %d Occupied Rooms: %d\n", b + 1, occupied_in_branch);
    }

    printf("\n--- Final Summary ---\n");
    printf("**Total number of occupied rooms across all branches: %d**\n", total_occupied_rooms);
}
//
