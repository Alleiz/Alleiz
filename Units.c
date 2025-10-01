/*
Name:Alex maingi
Reg No:CT101/G/26482/25
Description:Program to display the total_bill for units consumed
units< 30: 20 KES per unit (category1)
between 31 and 60: 25 KES per unit (category2)
Above 60: 30 KES per unit (category3)
*/
#include <stdio.h>
int main() { 
     //declare a variable to store the user's input for units consumed
    int units;
    //use a float for the total_bill to handle the two decimal places
    float total_bill=0.00;
    
    //prompt the user to enter units consumed
    printf("Enter units consumed:");
    
    //read the integer input from the user
        if (scanf("%d",&units)!=1) {
    	printf("Invalid input.Please enter a valid number of units.\n");
    	return 1;//exit with an error code
	}
	//use if-else if-else statements to calculate the total_bill
    if( units <=30){
		// category1:0-30 units @ 20 KES per unit
		total_bill=units*20.0;
	}
	else if( units <=60){
		// category2:31-60 units 
		// calculate the cost for the first 30 units(full first category)
		float category1_cost=30*20.0;
		// calculate the units in the second category(units consumed - 30)
		int category2_units=units - 30;
		// calculate the cost for the second category @ 25 KES per unit
		float category2_cost= category2_units*25.0;
		total_bill = category1_cost + category2_cost;
	}
	else {
		// category3: Above 60 units
		
		// cost for the first 30 units @ 20 KES
		float category1_cost = 30*20.0; 
		// cost for the next 30 units (31 to 60) @ 25 KES
		float category2_cost = 30*25.0; 
		//calculate units in the third category(units consumed - 60)
		int category3_units = units - 60;
		// calculate cost for the third category @ 30 KES per unit
		float category3_cost = category3_units*30.0;
	}	
	    //display the total_bill in KES with two decimal places
	printf("total_bill is %.2f KES\n",total_bill);
	
	return 0;
}