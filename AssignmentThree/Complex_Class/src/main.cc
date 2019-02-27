#include <iostream>


class Complex_Number
{
public:
	Complex_Number ();
	//virtual ~Complex_Number ();
	
	friend std::ostream &operator<< (std::ostream &os, const Complex_Number number);

private:
	float real_part;
	float imaginary_part;
};


Complex_Number::Complex_Number ()
{
	
	std::cout << "Enter a complex number: ";
	char *input = new char [256];
	std::cin >> input;
	
	real_part = std::atof (std::strtok (input, "+"));
	imaginary_part = std::atof (std::strtok (NULL, "+"));
}


std::ostream &operator<< (std::ostream &os, const Complex_Number number)
{
	
	os << number.real_part << '+' << number.imaginary_part << 'i';
	return os;
}


void arithmetic ()
{
	
	Complex_Number number_one;
	
	std::cout << "Enter an operation (+, -, *, /): ";
	char op;
	std::cin >> op;
	
	Complex_Number number_two;
}


int main (int argc, char const *argv[])
{
	
	std::cout << std::endl << "Project 1 from Assignment 3" << std::endl << "Modeling Complex Numbers" << std::endl << std::endl << "This program will allow simple calculations with complex numbers." << std::endl << std::endl;
	
	
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
			break;
			
			case 3:
			break;
			
			default:
			break;
		}
		
	} while (menu_choice != 3);
	
	
	return 0;
}