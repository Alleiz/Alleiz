/*
Name:Alex maingi
Reg No:CT101/G/26482/25
*/
#include <stdio.h>
//Function to display the menu
void display_menu() {
	
printf("Mobile Data Bundle Purchase Menu\n");
printf("|Option | Bundle | Cost(KES) |\n");
printf("|-------| -------|  ---------|\n");
printf("|  1    |  100 MB|      50   |\n");
printf("|  2    |  500 MB|      200  |\n");
printf("|  3    |  1 GB  |      350  |\n");
printf("|  4    |  2 GB  |      600  |\n");
}
int main() {
    int choice;
	// 1. Displays the menu above.
	display_menu();
	// 2.Asks the user to enter their choice (1-4).
	printf("Enter your choice (1-4): ");
	//Ensure the input is an integer
	if (scanf("%d", &choice) !=1) {
		printf("invalid input.please enter a number.\n");
		return 1; //Exit with an error code
}

    // 3.Uses a switch statement to display bundle selected and printf("\n);
    switch (choice) {
		case 1:
			printf("You selected Option 1: **100 MB** for KES 50");
			break;
		case 2:
			printf("You selected Option 2: **500 MB** for KES 200");
			break;
		case 3:
			printf("You selected Option 3: **1 GB** for KES 350");
			break;
		case 4:
			printf("You selected Option 4: **2 GB** for KES 600");
			break;
		default:
			//Handles any integer input outside the range 1-4
			printf("Invalid choice.Please select an option between 1-4");
			break;
			
	}
		return 0; 
}