#include <iostream>
#include <cmath>


const float calculate_approx (const float &n, const float &approx)
{
	
	float new_approx = ((n/approx) + approx)/2;
	
	if (fabs(new_approx - approx) > 0.00001)
		new_approx = calculate_approx (n, new_approx);
	
	return new_approx;
}


const float ask_for_input (const char *var)
{
	
	float input;
	
	std::cout << "Enter a value for " << var << ": ";
	std::cin >> input;
	
	return input;
}


int main (int argc, char const *argv[])
{
	
	std::cout << std::endl << "Project 5 from Assignment 1" << std::endl << "Square Root Approximator" << std::endl << std::endl << "This program will prompt for a real number, n, and an approximation, approx, for its square root, then the program will output a new approximation accurate to 0.00001." << std::endl << std::endl;
	
	const float n = ask_for_input ("n");
	const float user_approx = ask_for_input ("approx");
	
	std::cout << std::endl << "The square root of " << n << " is " << calculate_approx (n, user_approx) << std::endl;
	
	return 0;
}