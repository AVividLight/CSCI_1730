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


class Pairs
{

public:
	Pairs (float a = 0.0, float b = 0.0);
	
	friend Pairs operator+ (const Pairs &number_one, const Pairs &number_two);
	friend Pairs operator- (const Pairs &number_one, const Pairs &number_two);
	friend bool operator== (const Pairs &number_one, const Pairs &number_two);
	
	friend std::ostream &operator<< (std::ostream &os, const Pairs number);
	
protected:
	float leading_number;
	float trailing_number;
};


Pairs::Pairs (float a, float b)
{
	
	leading_number = a;
	trailing_number = b;
}


Pairs operator+ (const Pairs &number_one, const Pairs &number_two)
{
	
	return Pairs ((number_one.leading_number + number_two.leading_number), (number_one.trailing_number + number_two.trailing_number));
}


Pairs operator- (const Pairs &number_one, const Pairs &number_two)
{
	
	return Pairs ((number_one.leading_number - number_two.leading_number), (number_one.trailing_number - number_two.trailing_number));
}


bool operator== (const Pairs &number_one, const Pairs &number_two)
{
	
	return ((number_one.leading_number == number_two.leading_number && number_one.trailing_number == number_two.trailing_number) ? true : false);
}


std::ostream &operator<< (std::ostream &os, const Pairs number)
{
	
	os << number.leading_number;
	if (!(number.trailing_number < 0))
		os << '+';
	
	os << number.trailing_number << 'i';
	return os;
}


class Complex_Number : public Pairs
{
	
public:
	
	Complex_Number ();
	Complex_Number (float a, float b);
	
	const float get_real () const {return leading_number;}
	const float get_imaginary () const {return trailing_number;}
	
	friend Complex_Number operator* (const Complex_Number &number_one, const Complex_Number &number_two);
	friend Complex_Number operator/ (const Complex_Number &number_one, const Complex_Number &number_two);
	
	friend std::istream &operator>> (std::istream &is, Complex_Number &number);
private:
	
	float divide_input (const char *input, unsigned int &start_index);
	void operations ();
};


Complex_Number::Complex_Number ()
{
	
	std::cout << "Enter a complex number: ";
	std::cin.ignore ();
	
	char *input = new char [MAXIMUM_INPUT];
	std::cin.getline (input, MAXIMUM_INPUT);

	unsigned int index = 0;
	leading_number = divide_input (input, index);
	trailing_number = divide_input (input, index);
}


Complex_Number::Complex_Number (float a, float b)
{
	
	leading_number = a;
	trailing_number = b;
}


Complex_Number operator* (const Complex_Number &number_one, const Complex_Number &number_two)
{

	return Complex_Number (((number_one.get_real () * number_two.get_real ()) - (number_one.get_imaginary () * number_two.get_imaginary ())), (number_one.get_imaginary () * number_two.get_real ()) + (number_two.get_imaginary () * number_one.get_real ()));
}


Complex_Number operator/ (const Complex_Number &number_one, const Complex_Number &number_two)
{
	
	float denominator = ((number_two.get_real () * number_two.get_real ()) + (number_two.get_imaginary () * number_two.get_imaginary ()));
	
	return Complex_Number (((number_one.get_real () * number_two.get_real ()) + (number_one.get_imaginary () * number_two.get_imaginary ()))/denominator, ((number_one.get_imaginary () * number_two.get_real ()) - (number_one.get_real () * number_two.get_imaginary ()))/denominator);;
}



struct Solution_Set {
	Complex_Number additive_result;
	Complex_Number subtractive_result;
	bool single_result;
};


float Complex_Number::divide_input (const char *input, unsigned int &start_index)
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


std::istream &operator>> (std::istream &is, Complex_Number &number)
{
	
	char *input = new char [MAXIMUM_INPUT];
	is.getline (input, MAXIMUM_INPUT);

	unsigned int index = 0;
	number.leading_number = number.divide_input (input, index);
	number.trailing_number = number.divide_input (input, index);
	
	return is;
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


void complex_equation ()
{
	
	std::cout << "Quadratic Cofficients:" << std::endl;
	const float a = get_equation_input ('A', true);
	const float b = get_equation_input ('B');
	const float c = get_equation_input ('C');
	
	std::cout << std::endl << "Complex Solution:" << std::endl;
	Complex_Number user_number;
	
	bool is_addition_solution = (abs (user_number.get_real () - calculate_equation (a, b, c, true).get_real ()) < 0.000001 && abs (user_number.get_imaginary () - calculate_equation (a, b, c, true).get_imaginary ()) < 0.000001);
	bool is_subtraction_solution = (abs (user_number.get_real () - calculate_equation (a, b, c, false).get_real ()) < 0.000001 && abs (user_number.get_imaginary () - calculate_equation (a, b, c, false).get_imaginary ()) < 0.000001);
	
	if (is_addition_solution == true || is_subtraction_solution == true)
		std::cout << user_number << " is a solution to the quadratic equation." << std::endl;
	else
		std::cout << user_number << " is not a solution to the quadratic equation." << std::endl;
}


void complex ()
{
	
	Complex_Number number_one;
	Complex_Number number_two;
	
	std::cout << "Enter an operation (+, -, *, /, =): ";
	char op;
	std::cin >> op;
	
	switch (op)
	{
		
		case '+':
		std::cout << std::endl << number_one << ' ' << op << ' ' << number_two << " = " << number_one + number_two;
		break;
		
		case '-':
		std::cout << std::endl << number_one << ' ' << op << ' ' << number_two << " = " << number_one - number_two;
		break;
		
		case '*':
		case 'x':
		case 'X':
		std::cout << std::endl << number_one << ' ' << op << ' ' << number_two << " = " << number_one * number_two;
		break;
		
		case '/':
		std::cout << std::endl << number_one << ' ' << op << ' ' << number_two << " = " << number_one / number_two;
		break;
		
		case '=':
		complex_equation ();
		break;
		
		default:
		std::cout << "unknown operation";
		break;
	}
	
	std::cout << std::endl << std::endl;
}


class Vector : public Pairs
{

public:
	
	Vector (float a = 0.0, float b = 0.0);
	
	friend Vector operator* (const Vector &number_one, const Vector &number_two);
	friend Vector operator* (const Vector &number_one, const float number_two);
	
private:

};


void cActions ()
{	
	
	unsigned short int menu_choice;
	Complex_Number numbers[26];
	
	do
	{
			
		std::cout << "Select an operation:" << std::endl << "\t1 - Store a Complex Number" << std::endl << "\t2 - Display a Complex Number" << std::endl << "\t3 - Perform Complex Number Arithmatic or Equality Check" << std::endl << "\t4 - Return" << std::endl;
		
		std::cin >> menu_choice;
		std::cin.clear ();
		std::cin.ignore (1000, '\n');
		
		switch (menu_choice)
		{
			
			case 1:
			break;
			
			case 2:
			break;
			
			case 3:
			complex ();
			//operations ();
			break;
			
			default:
			break;
		}
		
	} while (menu_choice != 4);
	
	std::cout << std::endl;
}


Vector::Vector (float a, float b)
{
	
	leading_number = a;
	trailing_number = b;
}


Vector operator* (const Vector &number_one, const Vector &number_two)
{

	return Vector ((number_one.leading_number * number_two.leading_number), (number_one.trailing_number * number_two.trailing_number));
}


Vector operator* (const Vector &number_one, const float number_two)
{

	return Vector ((number_one.leading_number * number_two), (number_one.trailing_number * number_two));
}


void vActions ()
{
	
	
}


/* *** FOLLOWING IS CODE PROMPT FROM PROFESSOR *** */
using namespace std;

int main()
{
   int sel;
   do {
      cout << "Select an option - (1) perform complex number actions\n";
      cout << "                   (2) perform vector actions\n";
      cout << "                   (3) exit\n";
      cin >> sel;
      if(sel == 1)
         cActions();
      else if(sel == 2)
         vActions();
      else if (sel == 3)
         cout << "Bye...\n";
      else
         cout << "Invalid input - try again\n";
   } while (sel != 3);
   //char ch; cin >> ch; //Comment out to exit on macOS
   return 0;
}
/* *** END CODE PROMPT FROM PROFESSOR *** */
