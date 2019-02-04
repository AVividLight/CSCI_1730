#include <iostream>
#include <cmath>

void calculate_and_print (const float &a, const float &b, const float &c)
{
	
	float radicand = ((b*b) - 4*a*c);
	
	if (radicand == 0)
	{
		//Case: (b^2 - 4ac = 0) : REPEATED
		std::cout << (((-1)*b + sqrt(radicand))/(a*2)) << std::endl;
	} else if (radicand > 0) {
		//Case: (b^2 - 4ac > 0) : TWO REAL
		std::cout << (((-1)*b + sqrt(radicand))/(a*2)) << " and ";
		std::cout << (((-1)*b - sqrt(radicand))/(a*2)) << std::endl;
	} else {
		//Case: (b^2 - 4ac < 0) : IMAGINARY (*(-1) + 'i')
		std::cout << (((-1)*b)/2*a) << '+' << sqrt((-1)*radicand)/(2*a) << "i and ";
		std::cout << (((-1)*b)/2*a) << '-' << sqrt((-1)*radicand)/(2*a) << 'i' << std::endl;
	}
}


float get_input (const char &coefficient, const bool &nonzero = false)
{
	
	float value;
	
	while (true)
	{
		
		std::cout << "Enter a value for " << coefficient << ": ";
		std::cin >> value;
		
		if (value != 0)
			break;
		else if (nonzero == true)
		{
			
			std::cout << coefficient << " may not be 0." << std::endl;
		} else
			break;
	}
	
	return value;
}


int main (int argc, char const *argv[])
{
	
	std::cout << std::endl << "Project 4 from Assignment 1" << std::endl << "Quadratic Formula" << std::endl << std::endl << "This program will prompt for three inputs A, B, and C, then return the solution from the quadratic formula." << std::endl << std::endl;
	
	const float a = get_input ('A', true);
	const float b = get_input ('B');
	const float c = get_input ('C');
	
	std::cout << "The solution(s) are: ";
	calculate_and_print (a, b, c);
	
	return 0;
}
