#include <iostream>


const unsigned short int SET_SIZE = 100;


struct Sets_Quantity
{
	
	unsigned short int quantity;
	friend std::ostream &operator<< (std::ostream &os, const Sets_Quantity sets);
};


class IntSet
{
public:
	IntSet ();
	//virtual ~IntSet ();

private:
	bool integers[SET_SIZE];
};


IntSet::IntSet ()
{
	
	for (int i = 0; i < SET_SIZE; i += 1)
	{
		
		integers[i] = false;
	}
}


std::ostream print_sets (std::ostream &os, const Sets_Quantity sets)
{
	
	for (char i = 'A'; i <= ('A' + ); i += 1)
	{
		
		os << i;
		
		if (i < 'Z')
			os << ", ";
	}
	
	return os;
}


unsigned short int get_input (unsigned short int min = 1, unsigned short int max = 10)
{
	
	unsigned short int input;
	while (true)
	{
		
		std::cout << "Select an input: ";
		std::cin >> input;
		if (std::cin.fail () || input > max || input < min)
		{
			
			std::cout << "Please enter a valid input." << std::endl;
			std::cin.clear ();
			std::cin.ignore (1000, '\n');
			
		} else
			break;
	}
	
	return input;
}


int main (int argc, char const *argv[])
{
	
	std::cout << std::endl << "Project 3 from Assignment 3" << std::endl << "Integer Sets" << std::endl << std::endl << "This program will allow operations on sets of integers." << std::endl << std::endl;
	
	std::cout << "Enter number of sets to model (J = 10): ";
	unsigned short int sets_quantity = get_input (1, 27);
	IntSet sets[sets_quantity];
	
	unsigned short int menu_choice;
	
	do
	{
		
		std::cout << "Menu of Available Options:" << std::endl << "1\tAdd numbers to a set" << std::endl << "2\tRemove numbers from a set" << std::endl << "3\tForm the union of two sets" << std::endl << "4\tForm the intersection of two sets" << std::endl << "5\tForm the difference of two sets" << std::endl << "6\tDetermine if two sets are equal" << std::endl << "7\tForm the complement of an set" << std::endl << "8\tDetermine if one set is a subset of another set" << std::endl << "9\tDisplay a set" << std::endl << "10\tExit" << std::endl << std::endl;
		
		menu_choice = get_input ();
		
		switch (menu_choice)
		{
			
			case 1:
			std::cout << std::endl << "Add numbers to a set" << std::endl << "Which set do you want to modify (" << print_sets (sets_quantity) << "): ";
			
			break;
			
			case 2:
			break;
			
			case 3:
			break;
			
			case 4:
			break;
			
			case 5:
			break;
			
			case 6:
			break;
			
			case 7:
			break;
			
			case 8:
			break;
			
			case 9:
			break;
			
			case 10:
			break;
			
			default:
			break;
		}
		
		
	} while (menu_choice != 10);
	
	return 0;
}