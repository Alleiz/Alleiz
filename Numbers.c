/*
Name:Alex maingi
Reg No:CT101/G/26482/25
Description:Program to use a for loop to print all numbers from 100 to 50 in descending order
*/
#include <stdio.h>
int main(){
//write a C program	that uses a for loop to print all the numbers fro 100 down to 50 in descending order
//Each number should be printed on a new line.

int i;// declare the loop control variable
// The for loop structure:
// 1.Initialization: i = 100(start at 100)
// 2.Condition: i>=50(continue as long as i integer is greater than or equal to 50);
// 3.Update: i--(decrease i by 1 in each step)
for (i = 100 ;i >= 50; i--) { 
	//print the current value of i.
	printf("%d\n", i);
}
	return 0;
}
