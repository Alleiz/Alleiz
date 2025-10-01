/*
Name:Alex maingi
Reg No:CT101/G/26482/25
Description:Program to check student's eligibility for final exams
*/
#include <stdio.h>
/*
checks a student's eligibility for final exams
The student is eligible if:
1.Attendance is >=75%, AND
2.Average marks are >= 40.
Otherwise the program prints "Not Eligible."
*/
int main() {
//variable declaration
float attendance_percentage;//To store student's attendance
float average_marks;        // To store student's average marks	
// 1. Get input from the user

//Prompt for and read the attendance percentage
printf("Enter student attendance percentage:");
if (scanf("%f", &attendance_percentage) !=1) {
	//Handle input error for attendance
	printf("Invalid input for attendance.exit.\n");
	return 1; //indicate an error
}
//prompt for and read the average marks
printf("Enter student average marks:");
if (scanf("%f", &average_marks) !=1) {
	
	//Handle input error for average marks
	printf("Invalid input for average marks.exit.\n");
	return 1; //indicate an error
}
// 2.Check the eligibility criteria
//The student is eligible only if both conditions are met
//Condition 1: attendance_percentage >=75.0
//Condition 2: average_marks >=40.0
//Use logical AND operator (&&) is used to combine the two conditions.
if (attendance_percentage>=75.0 && average_marks>=40.0){
	//This block executes if the student is eligible
	printf("\nResult: Eligible for final exams.\n");
} else {
	//This block executes if at least one of the conditions is FALSE
	//(i.e.,the student is not eligible)
	printf("\nResult: Not eligible.\n");
}	
	return 0;
} 