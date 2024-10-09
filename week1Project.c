#include <stdio.h> //include statment for standard libraries
#include <stdlib.h>  //to use atoi

//prototypes:
/** addition function: computes num1 + num2
*/
int addition(int num1, int num2);
/** subtraction function: computes num1 - num2
*/
int subtraction(int num1, int num2);
/** multiplication function: computes num1 * num2
*/
int multiplication(int num1, int num2);
/** division function: computes num1 / num2
*   - assumes that num2 is not 0: attempt div by 0
*/
float division(int num1, int num2);

/** Project: Basic Text-based Calculator
*   - operations: (1) addition, (2) subtraction, (3) multiplication, (4) division
*   - Use functions for each operation, handle basic input errors (like division by zero)
*   1) Prompt user for two numbers and an operation
*   2) Use `switch` statement to handle selected operation
*   3) Output the result and ask if the user wants to perform another calculation
*/
int main(int args, char *argv[]) {
	int keepGoing = 0; //1 to stop
	while(keepGoing == 0) { //while keeping the program going
		//prompt user for 2 numbers 
		int num1 = 0; //initialize
		int num2 = 0; //initialize
		printf("Please input first number: "); //ask for 1st num input
		scanf("%d", &num1); //get input
		printf("Please input second number: "); //ask for 2nd num input
		scanf("%d", &num2); //get input
	
		//prompt users for an operation
		int operation = 0; //initialize
		printf("\nOperation choices: (1) addition, (2) subtraction, (3) multiplication, (4) division. \n"); //operation choices print
		printf("Please input an operation: "); //ask for operation
		scanf("%d", &operation); //get operation
	
		//use switch statement to handle selected operation
		switch (operation) { //Output the result 
			case 1: {
				int additionOutcome = addition(num1, num2); //call funct
				printf("%d + %d = %d\n", num1, num2, additionOutcome); //print outcome
				break; //get out of switch
			} case 2: {
				int subtractionOutcome = subtraction(num1, num2); //call funct
				printf("%d - %d = %d\n", num1, num2, subtractionOutcome); //print outcome
				break; //get out of switch
			} case 3: {
				int multiplicationOutcome = multiplication(num1, num2); //call funct
				printf("%d * %d = %d\n", num1, num2, multiplicationOutcome); //print outcome
				break; //get out of switch
			} case 4: {
				if (num2 != 0) { //if not divide by 0
					float divisionOutcome = division(num1, num2); //call funct
			    	printf("%d / %d = %.2f\n", num1, num2, divisionOutcome); //print outcome
					break; //get out of switch
				} else { //trying to divide by zero
					printf("error: trying to divide by zero\n"); //print error
					break; //get out of switch
				} //if
			} //cases
		} //switch	
		
		// ask if the user wants to perform another calculation
		int anotherCalcContinue = 0; //1 to stop
		while (anotherCalcContinue == 0) { //while still asking question
			char ifAnotherCalc; //calc to ask for user to input
			printf("\nWould you like to perform another calculation (y/n): "); //ask for user input
			scanf(" %c", &ifAnotherCalc); //add another space to prevent prev input red
		
			//compare characters
			if (ifAnotherCalc == 'n') { //if input is n and to stop
				anotherCalcContinue = 1; //anotherCalcContinue is 1, breaks out of inner while loop
				keepGoing = 1; //keepGoing is 1, breaks out of outer while loop
				printf("\nOk, bye bye! \n"); //message to leave
			} else if (ifAnotherCalc == 'y') { //if input is y and to keepGoing
				anotherCalcContinue  = 1; //breaks out of inner while loop
				printf("\nOk, another calculation starting... \n\n");
			} else { //input is incorrect for if continuing another calculation
				printf("\nInput is incorrect. Please try again.\n"); //asks again in inner while loop
			} //if
		} //while
	} //while

	return 0; //return main on sucess
} //main

//full function implementation
int addition(int num1, int num2) {
	return num1 + num2;
} //addition

int subtraction(int num1, int num2) {
	return num1 - num2;
} //subtraction

int multiplication(int num1, int num2) {
	return num1 * num2;
} //multiplication

float division(int num1, int num2) {
	return (float)num1 / num2; //cast to float to avoid int division
} //division
