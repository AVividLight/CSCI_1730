/*
Bryant Yaurincela
Logan Kreun
Michael Bethke
CSCI 1730-01
Group 7
*/


#include <iostream>
#include <cmath>
#include <cstdlib>


const static unsigned int MAXIMUM_INPUT = 256;


class Complex_Number
{
public:
	Complex_Number ();
	Complex_Number (float real, float imaginary);
	//virtual ~Complex_Number ();
	
	const float get_real () const {return real_part;};
	const float get_imaginary () const {return imaginary_part;};
	
	friend Complex_Number operator+ (const Complex_Number &number_one, const Complex_Number &number_two);
	friend Complex_Number operator- (const Complex_Number &number_one, const Complex_Number &number_two);
	friend Complex_Number operator* (const Complex_Number &number_one, const Complex_Number &number_two);
	friend Complex_Number operator/ (const Complex_Number &number_one, const Complex_Number &number_two);
	friend std::ostream &operator<< (std::ostream &os, const Complex_Number number);
	friend std::istream &operator>> (std::istream &is, Complex_Number &number);

private:
	float real_part;
	float imaginary_part;
};


struct Solution_Set {
	Complex_Number additive_result;
	Complex_Number subtractive_result;
	bool single_result;
};


float divide_input (const char *input, unsigned int &start_index)
{
	
	char *target_array = new char [MAXIMUM_INPUT];
	unsigned int target_index = 0;
	
	bool number_found = false;
	bool number_negative = false;
	
	for (int i = start_index; i < MAXIMUM_INPUT; i += 1)
	{
		
		if (input[i] == '\0')
		{
			
			start_index = i;
			break;
		}
		
		if (std::isdigit (input[i]) == true)
		{
			
			if (number_found == false)
				number_found = true;
			
			if (i > 0 && input[i-1] == '-')
				number_negative = true;
			
			target_array[target_index] = input[i];
			target_index += 1;
		} else {
			
			if (number_found == true)
			{
				
				if (input[i] == '.')
				{
				
					target_array[target_index] = input[i];
					target_index += 1;
				}
				
				if (input[i] == '+' || input[i] == '-')
				{
					
					start_index = i + 1;
					break;
				}
			}
		}
	}
	
	float target = std::atof (target_array);
	delete[] target_array;
	
	if (number_negative == true)
		target *= -1;
		
	return target;
}


Complex_Number::Complex_Number ()
{
	
	std::cout << "Enter a complex number: ";
	std::cin.ignore ();
	
	char *input = new char [MAXIMUM_INPUT];
	std::cin.getline (input, MAXIMUM_INPUT);

	unsigned int index = 0;
	real_part = divide_input (input, index);
	imaginary_part = divide_input (input, index);
}


Complex_Number::Complex_Number (float real, float imaginary)
{
	
	real_part = real;
	imaginary_part = imaginary;
}


Complex_Number operator+ (const Complex_Number &number_one, const Complex_Number &number_two)
{
	
	Complex_Number value ((number_one.get_real () + number_two.get_real ()), (number_one.get_imaginary () + number_two.get_imaginary ()));
	return value;
}


Complex_Number operator- (const Complex_Number &number_one, const Complex_Number &number_two)
{
	
	Complex_Number value ((number_one.get_real () - number_two.get_real ()), (number_one.get_imaginary () - number_two.get_imaginary ()));
	return value;
}


Complex_Number operator* (const Complex_Number &number_one, const Complex_Number &number_two)
{
	
	Complex_Number value (((number_one.get_real () * number_two.get_real ()) - (number_one.get_imaginary () * number_two.get_imaginary ())), (number_one.get_imaginary () * number_two.get_real ()) + (number_two.get_imaginary () * number_one.get_real ()));
	return value;
}


Complex_Number operator/ (const Complex_Number &number_one, const Complex_Number &number_two)
{
	
	float denominator = ((number_two.get_real () * number_two.get_real ()) + (number_two.get_imaginary () * number_two.get_imaginary ()));
	
	Complex_Number value (((number_one.get_real () * number_two.get_real ()) + (number_one.get_imaginary () * number_two.get_imaginary ()))/denominator, ((number_one.get_imaginary () * number_two.get_real ()) - (number_one.get_real () * number_two.get_imaginary ()))/denominator);
	return value;
}


std::ostream &operator<< (std::ostream &os, const Complex_Number number)
{
	
	os << number.get_real ();
	if (!(number.get_imaginary () < 0))
		os << '+';
	
	os << number.get_imaginary () << 'i';
	return os;
}


std::istream &operator>> (std::istream &is, Complex_Number &number)
{
	
	char *input = new char [MAXIMUM_INPUT];
	is.getline (input, MAXIMUM_INPUT);

	unsigned int index = 0;
	number.real_part = divide_input (input, index);
	number.imaginary_part = divide_input (input, index);
	
	return is;
}


void arithmetic ()
{
	
	Complex_Number number_one;
	
	std::cout << "Enter an operation (+, -, *, /): ";
	char op;
	std::cin >> op;
	
	Complex_Number number_two;
	
	std::cout << std::endl << number_one << ' ' << op << ' ' << number_two << " = ";
	
	switch (op)
	{
		
		case '+':
		std::cout << number_one + number_two;
		break;
		
		case '-':
		std::cout << number_one - number_two;
		break;
		
		case '*':
		case 'x':
		case 'X':
		std::cout << number_one * number_two;
		break;
		
		case '/':
		std::cout << number_one / number_two;
		break;
		
		default:
		std::cout << "unknown operation";
		break;
	}
	
	std::cout << std::endl << std::endl;
}


Complex_Number calculate_equation (const float a, const float b, const float c, bool add)
{

	const float radicand = ((b*b) - 4*a*c);
	
	if (radicand == 0) //Case: (b^2 - 4ac = 0) : REPEATED
	{
		
		return (*new Complex_Number ((((-1)*b + sqrt(radicand))/(a*2)), 0));
	} else if (radicand > 0) { //Case: (b^2 - 4ac > 0) : TWO REAL
		
		if (add)
			return (*new Complex_Number ((((-1)*b + sqrt(radicand))/(a*2)), 0));
		else
			return (*new Complex_Number ((((-1)*b - sqrt(radicand))/(a*2)), 0));
		
	} else { //Case: (b^2 - 4ac < 0) : IMAGINARY (*(-1) + 'i')
		
		if (add)
			return (*new Complex_Number ((((-1)*b)/2*a), sqrt((-1)*radicand)/(2*a)));
		else
			return (*new Complex_Number ((((-1)*b)/2*a), (-1)*sqrt((-1)*radicand)/(2*a)));
	}
}


float get_equation_input (const char coefficient, const bool &nonzero = false)
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


void equation ()
{
	
	std::cout << "Quadratic Cofficients:" << std::endl;
	const float a = get_equation_input ('a', true);
	const float b = get_equation_input ('b');
	const float c = get_equation_input ('c');
	
	std::cout << std::endl << "Complex Solution:" << std::endl;
	Complex_Number user_number;
	
	bool is_addition_solution = (abs (user_number.get_real () - calculate_equation (a, b, c, true).get_real ()) < 0.000001 && abs (user_number.get_imaginary () - calculate_equation (a, b, c, true).get_imaginary ()) < 0.000001);
	bool is_subtraction_solution = (abs (user_number.get_real () - calculate_equation (a, b, c, false).get_real ()) < 0.000001 && abs (user_number.get_imaginary () - calculate_equation (a, b, c, false).get_imaginary ()) < 0.000001);
	
	if (is_addition_solution == true || is_subtraction_solution == true)
		std::cout << user_number << " is a solution to the quadratic equation." << std::endl;
	else
		std::cout << user_number << " is not a solution to the quadratic equation." << std::endl;
}


int main (int argc, char const *argv[])
{
	
	std::cout << std::endl << "Project 2 from Assignment 3" << std::endl << "Modeling Complex Numbers" << std::endl << std::endl << "This program will allow simple calculations with complex numbers." << std::endl << std::endl;
	
	
	unsigned short int menu_choice;
	bool valid_input = false;
	
	do
	{
		
		std::cout << "Select an operation:" << std::endl << "\t1 - Perform Complex Number Arithmatic" << std::endl << "\t2 - Check for Quadratic Equation Solution" << std::endl << "\t3 - Exit" << std::endl;
		
		do
		{
			
			std::cin >> menu_choice;
			if (!std::cin.fail () && menu_choice > 0 && menu_choice < 4)
				valid_input = true;
			else {
				
				std::cin.clear ();
				std::cin.ignore (1000, '\n');
				
				std::cout << "Please enter 1, 2, or 3." << std::endl;
				valid_input = false;
			}
		} while (valid_input != true);
		
		switch (menu_choice)
		{
			
			case 1:
			arithmetic ();
			break;
			
			case 2:
			equation ();
			break;
			
			default:
			break;
		}
		
	} while (menu_choice != 3);
	
	
	return 0;
}