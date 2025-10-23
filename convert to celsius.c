/*
Name:
Reg No:
*/
#include <stdio.h>

/**
 * @brief Converts a temperature from Fahrenheit to Celsius.
 * *Uses the formula: C = (F - 32) * 5/9
 * 
 * @param fahrenheit_temp The temperature in Fahrenheit (double).
 * @return The temperature in Celsius (double).
 */
double convertToCelsius(double fahrenheit_temp){
	// The conversion formula: C = (F - 32) * 5/9
	// Using 5.0 / 9.0 ensures floating-point division.
	double celsius_temp = (fahrenheit_temp - 32.0) * (5.0/9.0);
	return celsius_temp;
}
//--- Example Usage ----
int main() {
	//Example 1: Convert the freezing point of water(32°F)
	double f1 = 32.0;
	double c1 = convertToCelsius(f1); 
	printf("%.2f degrees Fahrenheit is %.2f degrees Celsius.\n",f1, c1);
	
	
	//Example 2: Convert a common room temperature(68°F)
	double f2 = 68.0;
	double c2 = convertToCelsius(f2);
	printf("%.2f degrees Fahrenheit is %.2f degrees Celsius.\n",f2, c2);
	
	return 0;
	
}