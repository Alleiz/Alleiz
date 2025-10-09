/*
Name:Alex Maingi
Reg No:CT101/G/26482/25
Description:program to use do while loop for the correct guess
*/
#include <stdio.h> // For rand() and srand()
#include <time.h> // For time() to seed the random number generator

int main(){
	//Variables
	int secret_number;
	int guess;
	int attempts = 0; //Initialize the counter for the number of attempts
	int max_range = 20;
	int min_range = 1;
	
	// 1. Seed the random number generator
	srand (time(0));
	// 2. Generate the random secret number between 1 and 20 (inlusive)
	// (rand() %20) gives 0-19. Adding 1 shifts the range to 1-20.
	secret_number = (rand() % max_range) + min_range;
	printf("**NUMBER GUESSING GAME !**\n");
	printf("Ihave picked a secret number between %d and %d.\n", min_range, max_range);
	printf("Guess the number\n");
	printf("---------------------------\n");
	
	//The do while loop executes until the guess is correct
	do {
		printf("enter your guess");
		// Get the player's guess
		if (scanf("%d", &guess) !=1){
			printf("Invalid input. Please enter a number.\n");
			//Clear the input buffer to prevent an infinite loop on bad input
			while(getchar() !='\n');
			continue; 
		}
	// Increase the attempt counter for every valid guess made inside the loop attempts++;
	// 3. Respond with the appropriate message
	if (guess > secret_number) {
		printf("Too high!\n");
	} else if (guess < secret_number){
		printf("Too low\n");
	}
	// if guess == secret_number, the loop terminates
	while(guess != secret_number);
	// This message is printed when loop terminates;when guess is correct

	printf("\n***Congratulations! ***\n");
	printf("You guessed the secret number, which was %d.\n", secret_number);	
		
		// Display the total number of attempts
		printf("You made a total of %d attempts to guess correctly.\n", attempts);
		printf("Game over.\n");			
	}		
	
     return 0;
}
