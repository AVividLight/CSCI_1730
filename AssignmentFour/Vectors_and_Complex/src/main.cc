#include <iostream>
#include <cmath>
#include <cstdlib>


static const unsigned int MAXIMUM_INPUT = 256;
static const char *MENU_OPTIONS[4] = {"Store an Expression" , "Display an Expression", "Display a Scalar", "Perform Arithmatic or Equality Check"};


class Pairs
{

public:
	Pairs (float a = 0.0, float b = 0.0);
	~Pairs ();
	
	Pairs operator+ (const Pairs &number_two);
	Pairs operator- (const Pairs &number_two);
	bool operator== (const Pairs &number_two);
	
	friend std::ostream &operator<< (std::ostream &os, const Pairs number);
	
	const float get_leading () const {return leading_number;}
	const float get_trailing () const {return trailing_number;}
	
	const void set_leading (const float i) {leading_number = i;}
	const void set_trailing (const float i) {trailing_number = i;}
	
private:
	float leading_number;
	float trailing_number;
};


Pairs::Pairs (float a, float b)
{
	
	leading_number = a;
	trailing_number = b;
	
	//std::cout << "Construct!" << std::endl;
}


Pairs::~Pairs ()
{
	
	//std::cout << "Destruct!" << std::endl;
}


Pairs Pairs::operator+ (const Pairs &number_two)
{
	
	return Pairs ((leading_number + number_two.leading_number), (trailing_number + number_two.trailing_number));
}


Pairs Pairs::operator- (const Pairs &number_two)
{
	
	return Pairs ((leading_number - number_two.leading_number), (trailing_number - number_two.trailing_number));
}


bool Pairs::operator== (const Pairs &number_two)
{
	
	return ((leading_number == number_two.leading_number && trailing_number == number_two.trailing_number) ? true : false);
}


std::ostream &operator<< (std::ostream &os, const Pairs number)
{
	
	os << '(' << number.get_leading () << ", " << number.get_trailing () << ')';
	return os;
}


float divide_input (const char *input, unsigned int &start_index, const bool complex)
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
				
				if (input[i] == (complex ? '+' : ',') || input[i] == (complex ? '-' : ','))
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


class Complex_Number : public Pairs
{
	
public:
	Complex_Number (float a = 0, float b = 0);
	
	void operator= (const Pairs &parent);
	
	friend Complex_Number operator* (const Complex_Number &number_one, const Complex_Number &number_two);
	friend Complex_Number operator/ (const Complex_Number &number_one, const Complex_Number &number_two);
	
	friend std::ostream &operator<< (std::ostream &os, const Complex_Number number);
	
	//friend std::istream &operator>> (std::istream &is, Complex_Number &number);
};


Complex_Number::Complex_Number (float a, float b)
{
	
	set_leading (a);
	set_trailing (b);
}


void Complex_Number::operator= (const Pairs &parent)
{
	
	set_leading (parent.get_leading ());
	set_trailing (parent.get_trailing ());
}


Complex_Number operator* (const Complex_Number &number_one, const Complex_Number &number_two)
{

	return Complex_Number (((number_one.get_leading () * number_two.get_leading ()) - (number_one.get_trailing () * number_two.get_trailing ())), (number_one.get_trailing () * number_two.get_leading ()) + (number_two.get_trailing () * number_one.get_leading ()));
}


Complex_Number operator/ (const Complex_Number &number_one, const Complex_Number &number_two)
{
	
	float denominator = ((number_two.get_leading () * number_two.get_leading ()) + (number_two.get_trailing () * number_two.get_trailing ()));
	
	return Complex_Number (((number_one.get_leading () * number_two.get_leading ()) + (number_one.get_trailing () * number_two.get_trailing ()))/denominator, ((number_one.get_trailing () * number_two.get_leading ()) - (number_one.get_leading () * number_two.get_trailing ()))/denominator);;
}


std::ostream &operator<< (std::ostream &os, const Complex_Number number)
{
	
	os << number.get_leading ();
	if (number.get_trailing () >= 0)
		os << '+';
	
	os << number.get_trailing () << 'i';
	return os;
}


class Vector : public Pairs
{
	
public:
	Vector (float a = 0, float b = 0);
	
	friend Vector operator* (const Vector &number_one, const Vector &number_two);
	friend Vector operator* (const float scalar, const Vector &number_one);
	friend Vector operator/ (const Vector &number_one, const Vector &number_two);
	
	friend std::ostream &operator<< (std::ostream &os, const Vector number);
	
	//friend std::istream &operator>> (std::istream &is, Vector &number);
};


Vector::Vector (float a, float b)
{
	
	set_leading (a);
	set_trailing (b);
}


std::ostream &operator<< (std::ostream &os, const Vector number)
{
	
	os << '<' << number.get_leading () << ", " << number.get_trailing () << '>';
	return os;
}


void set_number (Pairs *store, Pairs *numbers[], bool complex)
{
	
	char *input = new char [MAXIMUM_INPUT];
	do
	{
		
		std::cout << "Where do you want to store this (a-z): ";
	
		std::cin.getline (input, MAXIMUM_INPUT);
		input[0] = tolower (input[0]);
		
	} while (input[0] < 'a' || input[0] > 'z');
	
	*numbers[input[0] - 'a'] = *store;
}


void store_number (Pairs *numbers[], bool complex)
{
	
	std::cout << "Enter an expression: ";
	
	char *input = new char [MAXIMUM_INPUT];
	std::cin.getline (input, MAXIMUM_INPUT);
	
	unsigned int split_index = 0;
	Pairs *new_expression;
	if (complex)
		new_expression = new Complex_Number (divide_input (input, split_index, true), divide_input (input, split_index, true));
	else
		new_expression = new Vector (divide_input (input, split_index, false), divide_input (input, split_index, false));
	
	set_number (new_expression, numbers, complex);
}


Pairs *get_number (Pairs *numbers [])
{
	
	char *index = new char [MAXIMUM_INPUT];
	
	do
	{
		
		std::cout << "Which complex number do you want to access (a-z): ";
		
		std::cin.getline (index, MAXIMUM_INPUT);
		index[0] = tolower (index[0]);
		
	} while (index[0] < 'a' || index[0] > 'z');
	
	return numbers[index[0] - 'a'];
}


void display_number (Pairs *numbers [], bool complex = false)
{
	
	if (complex)
		std::cout << *static_cast<Complex_Number*> (get_number(numbers)) << std::endl;
	else
		std::cout << *static_cast<Vector*> (get_number(numbers)) << std::endl;
}


float get_equation_input (const char coefficient, const bool &nonzero = false)
{
	
	float value;
	
	while (true)
	{
		
		std::cout << "Enter a value for " << coefficient << ": ";
		std::cin >> value;
		
		if (value == 0 && nonzero == true)
			std::cout << coefficient << " may not be 0." << std::endl;
		else
			break;
	}
	
	return value;
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


void complex_equation (Pairs *numbers[])
{
	
	std::cout << "Quadratic Cofficients:" << std::endl;
	const float a = get_equation_input ('A', true);
	const float b = get_equation_input ('B');
	const float c = get_equation_input ('C');
	
	std::cin.clear ();
	std::cin.ignore ();
	
	std::cout << std::endl << "Complex Solution:" << std::endl;
	Complex_Number *user_number = static_cast<Complex_Number*> (get_number(numbers));
	
	bool is_addition_solution = (abs (user_number->get_leading () - calculate_equation (a, b, c, true).get_leading ()) < 0.000001 && abs (user_number->get_trailing () - calculate_equation (a, b, c, true).get_trailing ()) < 0.000001);
	bool is_subtraction_solution = (abs (user_number->get_leading () - calculate_equation (a, b, c, false).get_leading ()) < 0.000001 && abs (user_number->get_trailing () - calculate_equation (a, b, c, false).get_trailing ()) < 0.000001);
	
	if (is_addition_solution == true || is_subtraction_solution == true)
		std::cout << user_number << " is a solution to the quadratic equation." << std::endl;
	else
		std::cout << user_number << " is not a solution to the quadratic equation." << std::endl;
}


void complex_arithmatic (Pairs *numbers[])
{
	
	std::cout << "Enter an operation (+, -, *, /, =, q [quadratic equality]): ";
	char *op = new char [2];
	std::cin.getline (op, 2);
	
	if (op[0] == 'q')
	{
		
		complex_equation (numbers);
	} else {
	
		Complex_Number *number_one = static_cast<Complex_Number*> (get_number (numbers));
	
		std::cout << "Second number:" << std::endl;
		Complex_Number *number_two = static_cast<Complex_Number*> (get_number (numbers));
	
		Complex_Number result;
	
		switch (op[0])
		{
		
			case '+':
			result = *number_one + *number_two;
			set_number (&result, numbers, true);
			break;
		
			case '-':
			result = *number_one - *number_two;
			set_number (&result, numbers, true);
			break;
		
			case '*':
			case 'x':
			case 'X':
			result = *number_one * *number_two;
			set_number (&result, numbers, true);
			break;
		
			case '/':
			result = *number_one / *number_two;
			set_number (&result, numbers, true);
			break;
		
			case '=':
			std::cout << number_one << " & " << number_two << (number_one == number_two ? " are " : " are not ") << "equal.";
			break;
		
			default:
			std::cout << op[0] << " is an unknown operation";
			break;
		}
	}
	
	std::cout << std::endl << std::endl;
}


#define cActions() menu(true)
#define vActions() menu(false)
void menu (bool complex)
{
	
	unsigned short int menu_choice;
	
	Pairs *numbers[26];
	for (int i = 0; i < 26; i += 1)
		numbers[i] = new Pairs ();
	
	do
	{
	
		std::cout << "Select an operation:" << std::endl;
		
		unsigned short int count = 1;
		for (int i = 0; i < 4; i += 1)
		{
			
			if (complex && i == 2)
				continue;
			
			std::cout << "\t" << count << " - " << MENU_OPTIONS[i] << std::endl;
			count += 1;
		}
		
		std::cout << "\t0 - Exit" << std::endl;
		
		std::cin >> menu_choice;
		std::cin.clear ();
		std::cin.ignore ();
		
		switch (menu_choice)
		{
			
			case 1:
			store_number (numbers, complex);
			break;
			
			case 2:
			display_number (numbers, complex);
			break;
			
			case 3:
			if (complex)
				complex_arithmatic (numbers);
			else
				break;//display_scalar
			break;
			
			case 4:
			if(!complex)
				break;//vector_arithmatic
			break;
			
			default:
			break;
		}
		
	} while (menu_choice != 0);
	
	std::cout << std::endl;
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
