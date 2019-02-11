#include <iostream>
#include <cstdlib>


const unsigned long int MAX_RUNS = 100000lu;


void roll_dice (unsigned int *rolls)
{
	
	for (int i = 0; i < sizeof(rolls)/sizeof(rolls[0]); i += 1)
	{
		
		rolls[i] = static_cast<unsigned short int> (std::rand () % 6);
	}
}


void get_input (unsigned long int &input)
{
	
	//do
	//{
		
		std::cout << "Enter the number of simulations: ";
		std::cin >> input;
		
		std::cin.clear ();
		std::cin.ignore (1000, '\n');
		
	//} while (input < MAX_RUNS);
}


int main (int argc, char const *argv[])
{
	
	std::cout << std::endl << "Project 4 from Assignment 2" << std::endl << "Fair Dice" << std::endl << std::endl << "This program will prompt for a number of dice-throwing simulations, then calculate and display the total number of each sum produced along with its percentage of the total tosses." << std::endl << std::endl;
	
	std::srand (std::time (NULL));
	
	unsigned long int runs;
	unsigned int *rolls;
	
	do {
		
		
		get_input (runs);
		rolls = new unsigned int [runs];
		
		roll_dice (rolls);
		std::cout << rolls[4] << std::endl;
		
		delete[] rolls;
		
	} while (true);
	
	
	
	return 0;
}