/*
Name:Alex Maingi
Reg No:CT101/G/26482/25
*/
#include <stdio.h>
/**
 * @brief calculates the total electric bill based on units consumed and a tiered rate structure
 * *Rates:
 * - First 100 units: Ksh. 10 per unit
 * - Next 100 units (101-200): Ksh. 15 per unit
 * -Above 200 units: Ksh. 20 per unit
 * 
 * @param units_consumed The total amount of units consumed(integer).
 * @return The total bill amount (integer).
 */
int calculateElectricBill(int units_consumed) {
	int total_bill = 0;
	
	//Tier 1: First 100 units @ Ksh. 10
	if (units_consumed < 100) {
	total_bill = units_consumed * 10;	
	}
	//Tier 2: Units between 101 and 200
	else if (units_consumed <=200){
		//Bill for the first 100 units(Ksh. 10 * 100 = 1000)
		total_bill = 100*10;
		
		//Bill for the remaining units @ Ksh. 15
		int remaining_units = units_consumed - 100;
		total_bill += remaining_units * 15;
	}
	//Tier 3: Units above 200
	else {
		//Bill for the first 100 units (Ksh. 10 * 100 = 1000)
		total_bill = 100 * 10;
		
		//Bill for the next 100 units (Ksh. 15 * 100 = 1500)
		total_bill += 100 * 15; 
		
		//Bill for the remaining units @Ksh. 20
		int remaining_units = units_consumed - 200;
		total_bill += remaining_units * 20;
	}
	
	return total_bill;
}   
 // Example Usage and Verification
 
 // Main function to use example of 250 units;
  	
int main(){
	int units1=50;
	int units2=150;
	int units3=250; // Example from the prompt
	
	printf("Units consumed: %d, Total bill: Ksh.%d\n",units1,calculateElectricBill(units1));
	// Expected: 50 * 10 = 500	
	printf("Units consumed:%d, Total bill: Ksh.%d\n",units2,calculateElectricBill(units2));
	// Expected: (100 * 10) + (50 *15) = 1000+750 =1750
	printf("Units consumed: %d, Total bill: Ksh.%d\n",units3,calculateElectricBill(units3));
	// Expected: (100 * 10)+(100 * 15)+(50 * 20) =1000 + 1500 + 1000 = 3500(Matches example)
	
	return 0;
}
		