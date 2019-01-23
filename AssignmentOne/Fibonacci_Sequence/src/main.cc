#include <iostream>


int next_fibonacci_number (const int &input)
{
	
	int target = 0;
	int f_0 = 0;
	int f_1 = 1;
	for (int i = 0; i < input - 2; i++)
	{
		
		target = f_0 + f_1;
		f_0 = f_1;
		f_1 = target;
	}
	
	return target;
}


bool get_input (int &input)
{
	
	do
	{
		
		std::cout << std::endl << "Enter a positive integer: ";
		std::cin >> input;

	} while (input < 0);
	
	return true;
}


int main (int argc, char const *argv[])
{
	
	std::cout << std::endl << "Project 2 from Assignment 1" << std::endl << "Fibonacci Sequence" << std::endl << std::endl << "This program will prompt for input and will return the next integer from the Fibonacci Sequence." << std::endl << std::endl;
	
	int input = 0;
	char again = 'y';
	
	do
	{
		
		get_input (input);
		std::cout << input << "th Fibonacci number: " << next_fibonacci_number (input) << std::endl;
		
		std::cout << "Continue? (y/n) ";
		std::cin >> again;
		
	} while (again == 'y' || again == 'Y');
	
	return 0;
}