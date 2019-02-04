#include <iostream>


const int find_gcd (int remainder, int smaller_number)
{
	
	if (remainder == 0)
		return smaller_number;
	else
		return find_gcd (smaller_number % remainder, remainder);
}


const int ask_for_input (int input)
{
	
	std::cout << "Enter a positive integer: ";
	std::cin >> input;
	
	return input;
}


int main (int argc, char const *argv[])
{
	
	std::cout << std::endl << "Project 6 from Assignment 1" << std::endl << "Euclid's GCD Method" << std::endl << std::endl << "This program will prompt the user for two integers, then return their greatest common divisor." << std::endl << std::endl;
	
	int number_one = ask_for_input (number_one);
	int number_two = ask_for_input (number_two);
	
	std::cout << "GCD: " << find_gcd (number_one, number_two) << std::endl;
	
	return 0;
}