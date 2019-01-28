#include <iostream>


const class nullptr_t {
public:
   template<class T> operator T*() const {return 0;}
   template<class C, class T> operator T C::*() const {return 0;}   

private:
   void operator &() const;

} nullptr = {};     



struct fraction {
	int numerator;
	int denominator;
	
	const char *as_string ();
};


const char *fraction::as_string ()
{
	
	const static char result[] = {numerator + '/' + denominator};
	
	return result;
}


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
	
	
	
	std::cout << fraction_one->as_string() << std::endl;
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
		
	} while (tolower(again) == 'y');
	
	return 0;
}
