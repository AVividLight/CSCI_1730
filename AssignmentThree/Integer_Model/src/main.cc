#include <iostream>


const unsigned short int SET_SIZE = 100;


unsigned short int get_input (unsigned short int min, unsigned short int max);


class IntSet
{
public:
	IntSet ();
	//virtual ~IntSet ();
	
	const char get_name () const {return id;};
	void set_name (unsigned short int i) {id = 'A' + i;};
	
	friend void operator+= (IntSet &set, unsigned short int nbr);
	friend std::ostream &operator<< (std::ostream &os, const IntSet set);

private:
	bool integers[SET_SIZE];
	char id;
};


IntSet::IntSet ()
{
	
	id = 'A';
	for (int i = 0; i < SET_SIZE; i += 1)
	{
		
		integers[i] = false;
	}
}


void operator+= (IntSet &set, unsigned short int nbr)
{
	
	set.integers[nbr] = true;
}


std::ostream &operator<< (std::ostream &os, const IntSet set)
{
	
	bool first_run = true;
	
	os << '{';
	for (int i = 0; i < SET_SIZE; i += 1)
	{
		
		if (set.integers [i] == true)
		{
			
			if (first_run == true)
				first_run = false;
			else
				os << ", ";
			
			os << i;
		}
	}
	
	os << '}';
	
	return os;
}


struct Sets
{
	
	Sets ();
	
	const unsigned short int get_quantity () const {return quantity;};
	IntSet *get_set (const int index) {return &sets[index];};
	
	friend std::ostream &operator<< (std::ostream &os, Sets &sets);
	
private:
	unsigned short int quantity;
	IntSet *sets;
	
	void name_sets ();
};


Sets::Sets ()
{
	
	std::cout << "Enter number of sets to model between 2 and 26 (J = 10): ";
	quantity = get_input (2, 26);
	
	delete[] sets;
	sets = new IntSet [quantity];
	name_sets ();
}


void Sets::name_sets ()
{
	
	for (int i = 0; i < quantity; i += 1)
	{
		
		sets[i].set_name (i);
	}
}


std::ostream &operator<< (std::ostream &os, Sets &sets)
{
	
	for (int i = 0; i < sets.get_quantity (); i += 1)
	{
		
		os << sets.get_set (i)->get_name ();
		if (i < sets.get_quantity () - 1)
			os << ", ";
	}
	
	return os;
}


unsigned short int get_input (unsigned short int min, unsigned short int max)
{
	
	unsigned short int input;
	while (true)
	{
		
		std::cout << "Provide an input (" << min << ", " << max << "): ";
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


char get_input ()
{
	
	char input;
	while (true)
	{
		
		std::cout << "Enter a set: ";
		std::cin >> input;
		if (std::cin.fail ())
			std::cout << "Please enter a valid input." << std::endl;
		else
			break;
		
		std::cin.clear ();
		std::cin.ignore (1000, '\n');
	}
	
	std::cout << std::endl;
	
	return std::toupper (input);
}


int main (int argc, char const *argv[])
{
	
	std::cout << std::endl << "Project 3 from Assignment 3" << std::endl << "Integer Sets" << std::endl << std::endl << "This program will allow operations on sets of integers." << std::endl << std::endl;
	
	Sets sets;
	IntSet *set_one;
	IntSet *set_two;
	
	unsigned short int menu_choice;
	
	do
	{
		
		std::cout << "Menu of Available Options:" << std::endl << "1\tAdd numbers to a set" << std::endl << "2\tRemove numbers from a set" << std::endl << "3\tForm the union of two sets" << std::endl << "4\tForm the intersection of two sets" << std::endl << "5\tForm the difference of two sets" << std::endl << "6\tDetermine if two sets are equal" << std::endl << "7\tForm the complement of an set" << std::endl << "8\tDetermine if one set is a subset of another set" << std::endl << "9\tDisplay a set" << std::endl << "10\tExit" << std::endl << std::endl;
		
		menu_choice = get_input (1, 10);
		
		switch (menu_choice)
		{
			
			case 1:
				std::cout << std::endl << "Add numbers to a set" << std::endl << "Which set do you want to modify (" << sets << "): ";
				set_one = sets.get_set (get_input () - 'A');
				*set_one += get_input (0, 99);
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
				std::cout << std::endl << "Display a set" << std::endl << "Which set do you want to display (" << sets << "): ";
				std::cout << *sets.get_set (get_input () - 'A') << std::endl;
			break;
			
			case 10:
			break;
			
			default:
			break;
		}
		
		
	} while (menu_choice != 10);
	
	return 0;
}