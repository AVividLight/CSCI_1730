#include <iostream>


struct fraction {
	int numerator;
	int denominator;
};


fraction result (const fraction *fraction_one, const char *op, const fraction *fraction_two)
{
	
	fraction fraction_result;
	
	switch (*op)
	{
		
		case '+':
		break;
		
		case '-':
		break;
		
		case '*':
		case 'x':
		break;
		
		case '/':
		break;
		
		default:
		break;
	}
	
	return fraction_result;
}


void output (const fraction *fraction_one, const char *op, const fraction *fraction_two)
{
	
	
	
	std::cout << "" << std::endl;
}


void prompt_for_input (fraction *fract, char *op = nullptr)
{
	
	if (fract != nullptr)
	{
		
		char slash;
	
		std::cout << "Enter a fraction (match the pattern x/y): ";
		std::cin >> fract->numerator >> slash >> fract->denominator;
	} else if (op != nullptr)
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
		prompt_for_input (nullptr, &operation);
		prompt_for_input (&fraction_two);
		
		output (&fraction_one, &operation, &fraction_two);
		
		std::cout << "Continue? (y/n) ";
		std::cin >> again;
		
	} while (again != 'y' || again != 'Y');
	
	return 0;
}