#include <iostream>
#include <cstdlib>


const unsigned long int MAX_RUNS = 100000lu;


int find_quantity_in_array (int match, unsigned int *rolls)
{
	
	int quantity = 0;
	
	for (int i = 0; i < rolls[0]; i += 1)
	{
		
		if (rolls[i] == match)
			quantity += 1;
	}
	
	return quantity;
}


void find_sum (unsigned int *first_die, unsigned int *second_die, unsigned int *results)
{
	
	for (int i = 0; i < 10; i += 1)
	{
		
		/*
			Current issue: each array contains values from 0 to five, but this will look for values up to 12.
		*/
		
		unsigned int sum = find_quantity_in_array ((i + 2), first_die) + find_quantity_in_array ((i + 2), second_die);
		
		results[i] = sum;
	}
}


void display (unsigned int *first_die, unsigned int *second_die)
{
	
	unsigned int results[10];
	find_sum (first_die, second_die, results);
	
	std::cout << "Total Throws: " << first_die[0] << std::endl;
	std::cout << "\tSum\tCount\tProbability" << std::endl;
	
	for (int i = 2; i <= 12; i += 1)
	{
		
		std::cout << '\t' << i << '\t' << results[i-2] << '\t' << std::endl;
	}
}


void roll_dice (unsigned int *rolls)
{
	
	for (int i = 1; i <= rolls[0]; i += 1)
	{

		rolls[i] = static_cast<unsigned short int> (std::rand () % 6);
	}
}


void get_input (unsigned long int &input)
{
	
	do
	{
		
		std::cout << "Enter the number of simulations: ";
		std::cin >> input;
		
		std::cin.clear ();
		std::cin.ignore (1000, '\n');
		
	} while (input > MAX_RUNS);
}


char get_simulate_again ()
{

	std::cout << "Do another simulation? (y/n): ";
	
	char input;
	std::cin >> input;
	
	return input;
}


int main (int argc, char const *argv[])
{
	
	std::cout << std::endl << "Project 4 from Assignment 2" << std::endl << "Fair Dice" << std::endl << std::endl << "This program will prompt for a number of dice-throwing simulations, then calculate and display the total number of each sum produced along with its percentage of the total tosses." << std::endl << std::endl;
	
	std::srand (std::time (NULL));
	
	unsigned long int runs;
	unsigned int *first_die;
	unsigned int *second_die;
	
	char simulate_again;
	
	do {
		
		get_input (runs);
		first_die = new unsigned int [runs + 1];
		first_die[0] = runs;
		
		second_die = new unsigned int [runs + 1];
		second_die[0] = runs;
		
		roll_dice (first_die);
		roll_dice (second_die);
		
		display (first_die, second_die);
		
		delete[] first_die;
		delete[] second_die;
		
		simulate_again = get_simulate_again ();
		
	} while (tolower (simulate_again) == 'y');
	
	
	
	return 0;
}