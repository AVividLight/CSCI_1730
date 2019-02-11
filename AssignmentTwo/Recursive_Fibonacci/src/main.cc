#include <iostream>


int next_fibonacci_number (const unsigned int &input_number, unsigned int &index, unsigned int &target, unsigned int f_0, unsigned int f_1)
{
	
	if (index < input_number)
	{
		target = f_0 + f_1;
		return next_fibonacci_number (input_number, ++index, target, f_1, target);
	} else {

		return target;
	}
}


void get_input (unsigned int &input_number)
{
	
	do
	{
		
		std::cout << std::endl << "Enter a positive integer: ";
		std::cin >> input_number;
		std::cin.clear ();
		std::cin.ignore(10000, '\n');

	} while (input_number < 1);
}


int main (int argc, char const *argv[])
{
	
	std::cout << std::endl << "Project 3 from Assignment 1" << std::endl << "Recursive Fibonacci Sequence" << std::endl << std::endl << "This program will prompt for input and will return the next integer from the Fibonacci Sequence." << std::endl << std::endl;
	
	unsigned int input_number = 0;
	unsigned int index;
	unsigned int target;
	unsigned int f_0;
	unsigned int f_1;
	
	char again = 'y';
	
	do
	{
		
		index = 0;
		target = 0;
		f_0 = 0;
		f_1 = 1;
		
		get_input (input_number);
		std::cout << input_number << "th Fibonacci number: " << next_fibonacci_number ((input_number-2), index, target, f_0, f_1) << std::endl;
		
		std::cout << "Continue? (y/n) ";
		std::cin >> again;
		
	} while (tolower (again) == 'y');
	
	return 0;
}