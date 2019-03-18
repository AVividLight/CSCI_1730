/*
Bryant Yaurincela
Logan Kreun
Michael Bethke
CSCI 1730-01
Group 7
*/


#include <iostream>
#include <string>
#include <cctype>


int main (int argc, char const *argv[])
{
	
	std::cout << std::endl << "Project 4 from Assignment 3" << std::endl << "String Statistics" << std::endl << std::endl << "This program will receive a string as an input and provide statistics about the characters." << std::endl;
	
	std::string input;
	std::getline (std::cin, input, '@');
	
	short unsigned int upper_case = 0;
	short unsigned int lower_case = 0;
	short unsigned int digits = 0;
	short unsigned int white_space = 0;
	
	char c;
	for (int i = 0; i < input.length (); i += 1)
	{
		
		c = input[i];
		std::cout << c;
		
		if (isupper (c))
			upper_case += 1;
		else if (islower (c))
			lower_case += 1;
		else if (isdigit (c))
			digits += 1;
		else if (isspace (c))
			white_space += 1;
	}
	
	std::cout << std::endl << std::endl << "Of the " << input.length () << " characters that were entered:" << std::endl << upper_case << " are upper-case;" << std::endl << lower_case << " are lower-case;" << std::endl << digits << " are digits;" << std::endl << white_space << " are white space;" << std::endl << "and " << (input.length () - (upper_case + lower_case + digits + white_space)) << " are other characters." << std::endl;
	
	return 0;
}