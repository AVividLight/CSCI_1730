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
	friend void operator-= (IntSet &set, unsigned short int nbr);
	friend IntSet operator+ (IntSet &set_one, IntSet &set_two);
	friend IntSet operator* (IntSet &set_one, IntSet &set_two);
	friend IntSet operator- (IntSet &set_one, IntSet &set_two);
	friend bool operator== (const IntSet &set_one, const IntSet &set_two);
	friend IntSet operator! (const IntSet &set_one);
	friend bool operator<= (const IntSet &set_one, const IntSet &set_two);
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


void operator-= (IntSet &set, unsigned short int nbr)
{
	
	set.integers[nbr] = false;
}


IntSet operator+ (IntSet &set_one, IntSet &set_two)
{
	
	IntSet new_set;
	
	for (int i = 0; i < SET_SIZE; i += 1)
	{
		
		if (set_one.integers[i] == true || set_two.integers[i] == true)
			new_set.integers[i] = true;
	}
	
	return new_set;
}


IntSet operator* (IntSet &set_one, IntSet &set_two)
{
	
	IntSet new_set;
	
	for (int i = 0; i < SET_SIZE; i += 1)
	{
		
		if (set_one.integers[i] == true && set_two.integers[i] == true)
			new_set.integers[i] = true;
	}
	
	return new_set;
}


IntSet operator- (IntSet &set_one, IntSet &set_two)
{
	
	IntSet new_set;
	
	for (int i = 0; i < SET_SIZE; i += 1)
	{
		
		if (set_one.integers[i] == true && set_two.integers[i] == false)
			new_set.integers[i] = true;
	}
	
	return new_set;
}


bool operator== (const IntSet &set_one, const IntSet &set_two)
{
	
	for (int i = 0; i < SET_SIZE; i += 1)
	{
		
		if (set_one.integers[i] != set_two.integers[i])
			return false;
	}
	
	return true;
}


IntSet operator! (const IntSet &set_one)
{
	
	IntSet new_set;
	
	for (int i = 0; i < SET_SIZE; i += 1)
	{
		
		new_set.integers[i] = !set_one.integers[i];
	}
	
	return new_set;
}


bool operator<= (const IntSet &set_one, const IntSet &set_two)
{
	
	for (int i = 0; i < SET_SIZE; i += 1)
	{
		
		if ((set_two.integers[i] == true) && (set_one.integers[i] != true))
			return false;
	}
	
	return true;
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
		{
			
			std::cout << "Please enter a valid input." << std::endl;
			std::cin.clear ();
			std::cin.ignore (1000, '\n');
		} else
			break;
		
	}
	
	return std::toupper (input);
}


bool repeat_action ()
{
	
	char input;
	while (true)
	{
		
		std::cout << "Modify set again (y/n)? ";
		std::cin >> input;
		if (std::cin.fail ())
			std::cout << "Enter y for yes or n for no." << std::endl;
		else
			break;
		
		std::cin.clear ();
		std::cin.ignore (1000, '\n');
	}
	
	return (std::toupper (input) == 'Y' ? true : false);
}


int main (int argc, char const *argv[])
{
	
	std::cout << std::endl << "Project 3 from Assignment 3" << std::endl << "Integer Sets" << std::endl << std::endl << "This program will allow operations on sets of integers." << std::endl;
	
	Sets sets;
	IntSet *set_one;
	IntSet *set_two;
	IntSet *result_set;
	char result_id;
	
	unsigned short int menu_choice;
	
	do
	{
		
		std::cout << std::endl << "Menu of Available Options:" << std::endl << "1\tAdd numbers to a set" << std::endl << "2\tRemove numbers from a set" << std::endl << "3\tForm the union of two sets" << std::endl << "4\tForm the intersection of two sets" << std::endl << "5\tForm the difference of two sets" << std::endl << "6\tDetermine if two sets are equal" << std::endl << "7\tForm the complement of an set" << std::endl << "8\tDetermine if one set is a subset of another set" << std::endl << "9\tDisplay a set" << std::endl << "10\tExit" << std::endl << std::endl;
		
		menu_choice = get_input (1, 10);
		
		switch (menu_choice)
		{
			
			case 1:
				std::cout << "Add numbers to a set" << std::endl << "Which set do you want to modify (" << sets << "): ";
				set_one = sets.get_set (get_input () - 'A');
				
				do
				{
					
					*set_one += get_input (0, 99);
				} while (repeat_action ());
			break;
			
			case 2:
				std::cout << "Remove numbers from a set" << std::endl << "Which set do you want to modify (" << sets << "): ";
				set_one = sets.get_set (get_input () - 'A');
				
				do
				{
					
					*set_one -= get_input (0, 99);
				} while (repeat_action ());
			break;
			
			case 3:
				std::cout << "Form union of two sets" << std::endl << "Select first set (" << sets << "): ";
				set_one = sets.get_set (get_input () - 'A');
				std::cout << "Select second set (" << sets << "): ";
				set_two = sets.get_set (get_input () - 'A');
				std::cout << "Select result set - WILL OVERWRITE (" << sets << "): ";
				result_set = sets.get_set (get_input () - 'A');
				
				result_id = result_set->get_name () - 'A';
				/*if (set_one->get_name () != result_set->get_name () && set_two->get_name () != result_set->get_name ())
					delete[] result_set;*/
				
				*result_set = *set_one + *set_two;
				result_set->set_name (result_id);
			break;
			
			case 4:
				std::cout << "Intersection of two sets" << std::endl << "Select first set (" << sets << "): ";
				set_one = sets.get_set (get_input () - 'A');
				std::cout << "Select second set (" << sets << "): ";
				set_two = sets.get_set (get_input () - 'A');
				std::cout << "Select result set - WILL OVERWRITE (" << sets << "): ";
				result_set = sets.get_set (get_input () - 'A');
				
				result_id = result_set->get_name () - 'A';
				/*if (set_one->get_name () != result_set->get_name () && set_two->get_name () != result_set->get_name ())
					delete[] result_set;*/
				
				*result_set = *set_one * *set_two;
				result_set->set_name (result_id);
			break;
			
			case 5:
				std::cout << "Difference of two sets" << std::endl << "Select first set (" << sets << "): ";
				set_one = sets.get_set (get_input () - 'A');
				std::cout << "Select second set (" << sets << "): ";
				set_two = sets.get_set (get_input () - 'A');
				std::cout << "Select result set - WILL OVERWRITE (" << sets << "): ";
				result_set = sets.get_set (get_input () - 'A');
				
				result_id = result_set->get_name () - 'A';
				/*if (set_one->get_name () != result_set->get_name () && set_two->get_name () != result_set->get_name ())
					delete[] result_set;*/
				
				*result_set = *set_one - *set_two;
				result_set->set_name (result_id);
			break;
			
			case 6:
				std::cout << "Check set equality" << std::endl << "Select first set (" << sets << "): ";
				set_one = sets.get_set (get_input () - 'A');
				std::cout << "Select second set (" << sets << "): ";
				set_two = sets.get_set (get_input () - 'A');
				
				std::cout << "Sets are" << (*set_one == *set_two ? "" : " not") << " equal" << std::endl;
			break;
			
			case 7:
				std::cout << "Complement of set" << std::endl << "Select set (" << sets << "): ";
				set_one = sets.get_set (get_input () - 'A');
				std::cout << "Select result set - WILL OVERWRITE (" << sets << "): ";
				result_set = sets.get_set (get_input () - 'A');
				
				result_id = result_set->get_name () - 'A';
				/*if (set_one->get_name () != result_set->get_name () && set_two->get_name () != result_set->get_name ())
					delete[] result_set;*/

				*result_set = !*set_one;
				result_set->set_name (result_id);

			break;
			
			case 8:
				std::cout << "Check subset" << std::endl << "Select first set (" << sets << "): ";
				set_one = sets.get_set (get_input () - 'A');
				std::cout << "Select second set (" << sets << "): ";
				set_two = sets.get_set (get_input () - 'A');
				
				std::cout << "The second set is" << (*set_one <= *set_two ? "" : " not") << " a subset of the first" << std::endl;
			break;
			
			case 9:
				std::cout << std::endl << "Display a set" << std::endl << "Which set do you want to display (" << sets << "): ";
				std::cout << *sets.get_set (get_input () - 'A') << std::endl;
			break;
			
			case 10:
			//exit
			break;
			
			default:
			break;
		}
		
		std::cout << std::endl;
		
		
	} while (menu_choice != 10);
	
	return 0;
}