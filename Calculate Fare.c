/*
Name:Alex Maingi
Reg No:CT101/G/26482/25
*/
#include <stdio.h>

/**
 * @brief Calculate the total fare based on distance travelled.
 * 
 * @param distance_km The distance travelled in kilometers.
 * @return The total fare in KSh.
 */
double calculateFare(double distance_km) {
	//Define the constant fare rate:KSh.50 per kilometer
	const int FARE_RATE_PER_KM = 50;
	
	//The total fare is the distance multiplied by the rate.
	//We use a double for the return type to handle fractional fares,
	//though the rate is an integer.
	return distance_km * FARE_RATE_PER_KM;
}
//Example usage of the function
int main() {
	double distance1 = 10.0; // The example from the prompt
	double fare1 = calculateFare(distance1);
	printf("Distance: %.2f km | Fare: KSh.%.2f\n",distance1, fare1);
	
	
	return 0;
}