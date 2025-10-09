/*
Name:Alex Maingi
Reg No:CT101/G/26482/25
Description:Program to use do while loop to enter the correct password
*/
#include <stdio.h>
#include <string.h> //Required for the strcmp() function

int main(){
	//Define the correct password as a constant string
	const char correct_password[] = "1234";
	//Array to store the password the user enters(must be large enough)
	char entered_password[20];
	printf("**Welcome to System login**\n");
	
	//The do while loop structure:
	//  1. The 'do' block executes the code at least once.
	do {
		printf("Please enter your password: ");
		// Read the password string from the user
		// The %19s limits the input to 19 characters to prevent buffer overflow
		scanf("%19s", entered_password);
		
		// 2. Compare the entered password with the correct one using strcmp()
		// strcmp() return 0 if the strings are identical.
		if (strcmp(entered_password, correct_password) !=0) {
			printf("-- Incorrect password! Try again.--\n");
		}	
	//the while condition continues the loop if the passwords DO NOT match(strcmp result !=0)
	} while(strcmp(entered_password, correct_password) !=0);
	
	//This code executes only after the loop condition becomes FALSE ;passwords match)
	printf("\n***Access Granted***\n");
	printf("You are now logged in.\n");
	
	return 0;
}