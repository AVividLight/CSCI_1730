#include <iostream>


struct fraction {
	int numerator;
	int denominator;
};



fraction result (const fraction fraction_one, const char op, const fraction fraction_two)
{
	
	fraction fraction_result;
	
	switch (op)
	{
		
		case '+':
		fraction_result.numerator = (fraction_one.numerator * fraction_two.denominator) + (fraction_two.numerator * fraction_one.denominator);
		fraction_result.denominator = fraction_one.denominator * fraction_two.denominator;
		break;
		
		case '-':
		fraction_result.numerator = (fraction_one.numerator * fraction_two.denominator) - (fraction_two.numerator * fraction_one.denominator);
		fraction_result.denominator = fraction_one.denominator * fraction_two.denominator;
		break;
		
		case '*':
		case 'x':
		fraction_result.numerator = fraction_one.numerator * fraction_two.numerator;
		fraction_result.denominator = fraction_one.denominator * fraction_two.denominator;
		break;
		
		case '/':
		fraction_result.numerator = fraction_one.numerator * fraction_two.denominator;
		fraction_result.denominator = fraction_one.denominator * fraction_two.numerator;
		break;
		
		default:
		break;
	}
	
	return fraction_result;
}


void output (const fraction fraction_one, const char op, const fraction fraction_two)
{
	
	
	
	std::cout << result(fraction_one, op, fraction_two).numerator << '/' << result(fraction_one, op, fraction_two).denominator << std::endl;
}


void prompt_for_input (fraction *fract, char *op = '\0')
{
	
	if (fract != NULL)
	{
		
		char slash;
	
		std::cout << "Enter a fraction (match the pattern x/y): ";
		std::cin >> fract->numerator >> slash >> fract->denominator;
	} else if (op != '\0')
	{
		
		std::cout << "Enter an operation (+ - * /): ";
		std::cin >> op;
	}
}


int main (int argc, char const *argv[])
{
	
	std::cout << std::endl << "Project 3 from Assignment 1" << std::endl << "Simple Fraction Calculator" << std::endl << std::endl << "This program will prompt for three inputs as a fraction, an operation, and a final fraction, then return the result." << std::endl << std::endl;
	
	fraction fraction_one;
	fraction fraction_two;
	char operation;
	
	char again;
	
	do
	{
		
		prompt_for_input (&fraction_one);
		prompt_for_input (NULL, &operation);
		prompt_for_input (&fraction_two);
		
		output (fraction_one, operation, fraction_two);
		
		std::cout << "Continue? (y/n) ";
		std::cin >> again;
		
	} while (tolower(again) == 'y');
	
	return 0;
}
