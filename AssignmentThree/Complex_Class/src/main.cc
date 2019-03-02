#include <iostream>


const static unsigned int MAXIMUM_INPUT = 256;


class Complex_Number
{
public:
	Complex_Number ();
	//virtual ~Complex_Number ();
	
	const float get_real () const {return real_part;};
	const float get_imaginary () const {return imaginary_part;};
	
	friend std::ostream &operator<< (std::ostream &os, const Complex_Number number);

private:
	float real_part;
	float imaginary_part;
};


//		-23.5+-8i
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
	
	std::cout << "real part: " << real_part << std::endl;
	std::cout << "imaginary part: " << imaginary_part << std::endl;
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
	
	switch (op)
	{
		
		case '+':
		std::cout << number_one << " + " << number_two << " = " << (number_one.get_real () + number_two.get_real ()) << '+' << (number_one.get_imaginary () + number_two.get_imaginary ()) << 'i' << std::endl;
		break;
	}
	
	
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