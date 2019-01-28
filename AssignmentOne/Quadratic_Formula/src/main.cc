#include <iostream>
#include <cmath>


//i = sqrt(-1)
//(-b +- sqrt(b^2 - 4ac))/2a

/*

Case: (b^2 - 4ac = 0) : REPEATED
Case: (b^2 - 4ac > 0) : TWO REAL
Case: (b^2 - 4ac < 0) : IMAGINARY (*(-1) + 'i')

*/


char calculate (const float &a, const float &b, const float &c)
{
	
	//float radicand = ()
}


float get_input (const char &coefficient, const bool &nonzero = false)
{
	
	float value;
	
	while (true)
	{
		
		std::cout << "Enter a value for " << coefficient << ": ";
		std::cin >> value;
		
		if (nonzero == true)
		{
			
			if (value != 0)
				break;
			
		} else
			std::cout << coefficient << " may not be 0." << std::endl;
	}
	
	return value;
}


int main (int argc, char const *argv[])
{
	
	std::cout << std::endl << "Project 4 from Assignment 1" << std::endl << "Quadratic Formula" << std::endl << std::endl << "This program will prompt for three inputs A, B, and C, then return the solution from the quadratic formula." << std::endl << std::endl;
	
	float a = get_input ('A', true);
	float b = get_input ('B');
	float c = get_input ('C');
	
	char *result;
	
	std::cout << "The solution(s) are: ";
	for (int i = 0; i < 2; i += 1)
	{
		
		std::cout << calculate (a, b, c) << std::endl;
	}
	
	return 0;
}
