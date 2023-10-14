//Chad Huntebrinker
//12567690
//11/19/20
//CS 201L


#include <iostream>
using namespace std;


long factorial_r(long value);
int fibonacci_r(int num);
bool is_prime_r(int userInput, int n);
int sum_r(int list[], int listSize);
void output_reverse_list_r(int list[], int listSize);

int main() {
	long value;
	int userInput;
	int array[5];
	int arraySize = 5;
	
	//First two functions (Factorial and Fibonacci).  If the user enters in a negative number,
	//the program will ask it to enter in a positive number.
	cout << "Enter an integer" << endl;
	do {
		cin >> value;
		cout << endl;
		if (value < 0) {
			cout << "Can not enter a negative number. Please try again.";
		}

	} while (value < 0);
	cout << endl;
	cout << value << "! = " << factorial_r(value) << endl << endl;
	cout << "fibonacci(" << value << ") = " << fibonacci_r(value) << endl << endl;

	//Prime number function.  If the user enters in a negative number, the program will ask it
	//to enter a positive number.
	cout << "Enter a number to see if it is a prime number" << endl;
	do {
		cin >> userInput;
		cout << endl;
		if (userInput < 0) {
			cout << "Can not enter a negative number. Please try again.";
		}

	} while (userInput < 0);
	cout << endl;
	
	//If the prime number function returns true, then the number is a prime number.
	//Else, it is not a prime number.
	if (is_prime_r(userInput, 2)) {
		cout << userInput << " is a prime number." << endl << endl;
	}
	else {
		cout << userInput << " is not a prime number." << endl << endl;
	}

	//The user will now enter in their numbers into an array
	cout << "Next, we will enter 5 values into an array" << endl;
	for (int i = 0; i < 5; ++i) {
		cout << "Enter a value for index " << i << endl;
		cin >> userInput;
		array[i] = userInput;
	}

	//Sum of all the numbers in the list
	cout << "The sum of all the values is " << sum_r(array, arraySize - 1) << endl;

	//Outputs the numbers in reverse
	cout << "The list output in reverse is: " << endl;
	output_reverse_list_r(array, arraySize - 1);


	return 0;
}

//This function finds the factorial of the number inputted.
//The base case is when the value is less than or equal to 1 which will then return 1.
long factorial_r(long value) {
	if (value <= 1) {
		return 1;
	}
	else {
		return value * factorial_r(value - 1);
	}
}

//This function finds the fibonacci of the number inputted in the factorial function
//The base cases are when the number is = 1 or is <= 0. It will then return either 1 or 0.
int fibonacci_r(int num) {
	if (num < 1) {
		return 0;
	}
	else if (num == 1) {
		return 1;
	}
	else {
		return fibonacci_r(num - 1) + fibonacci_r(num - 2);
	}


}

//This function finds if the number inputted is a prime number.  If it is a prime nuumber,
//it will return true. If it is not a prime number, it will return false.
bool is_prime_r(int userInput, int n) {
	int x = sqrt(userInput);

	if (userInput % n != 0 && n > x) {
		return true;
	}
	else if (userInput % 2 == 0 && n < x) {
		return false;
	}
	else {
		is_prime_r(userInput, n + 1);
	}


}

//Adds the sum of the arrays. The base case is when the listSize has decreased to 0, which will
//then return the number in the array at 0.
int sum_r(int list[], int listSize) {
	if (listSize == 0) {
		return list[listSize];
	}
	else {
		return list[listSize] + sum_r(list, listSize - 1);
	}


}

//Outputs the reverse of the list. The base case is when the listSize has decreased to 0, which will
//then return the number in the array at 0.
void output_reverse_list_r(int list[], int listSize) {
	if (listSize == 0) {
		cout << list[listSize];
	}
	else {
		cout << list[listSize] << " ";
		output_reverse_list_r(list, listSize - 1);
	}



}