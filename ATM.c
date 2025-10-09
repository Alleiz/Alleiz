/*
Name:Alex maingi
Reg No:CT101/G/26482/25
Description:Program to use while loop for user withdrawals
*/
#include <stdio.h>

int main(){
	// 1. Initialize the account balance
	float balance = 800.00; //Start with an initial balance,eg, Kshs 800.00
	float withdrawal_amount;
	
	printf("ATM Simulator!\n");
	printf("Your initial account balance is: Kshs%.2f\n", balance);
	printf("----------------------------\n");
	
	//The while loop continues as long as the balance is greater than 0
	while(balance > 0) {
	   printf("Enter the amount you wish to withdraw\n: Kshs:");
	 
	   // Read the user's input for the withdrawal amount
	   if (scanf("%f", &withdrawal_amount) !=1) {
	    printf("Invalid input.please enter a number.\n");
		// Clear the input buffer to prevent the infinite loop on bad input
		while(getchar() != '\n');
		continue; // Skip the rest of the loop and start the next iteration
    }   
	
	// 2. Check if the withdrawal is possible(amount is positive and less than zero
	if (withdrawal_amount <= 0) {
		printf("withdrawal amount must be positive.\n");
    } else if (withdrawal_amount > balance) {
		printf("-- Insufficient Funds! --\n");
		printf("Current balance:Kshs%.2f. Cannot withdraw Kshs%.2f.\n", balance,withdrawal_amount);
    } else {
		// 3. Process the successful withdrawal
		balance = balance- withdrawal_amount;
		printf("* withdrawal successful *\n");
		// 4. Display the new balance
		printf("Your new balance is: Kshs%.2f\n", balance);
	}
}
// This code runs when the while loop condition (balance > 0) becomes incorrect.
printf("---------------------\n");
printf("Account balance is Kshs%.2f.ATM services terminated.\n", balance);
printf("THANK YOU!\n"); 


	return 0;
}