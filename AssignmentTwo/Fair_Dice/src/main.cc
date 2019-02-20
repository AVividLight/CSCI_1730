#include <iostream>
#include <cstdlib>


const unsigned long int MAX_RUNS = 100000lu;


void find_sum (unsigned int *first_die, unsigned int *second_die, unsigned int *results)
{
	
	for (int i = 1; i <= first_die[0]; i += 1)
	{

		results[first_die[i] + second_die[i] - 2] += 1;
	}
}


void display (unsigned int *first_die, unsigned int *second_die)
{
	
	unsigned int results[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	find_sum (first_die, second_die, results);
	
	std::cout << "Total Throws: " << first_die[0] << std::endl;
	std::cout << "\tSum\tCount\tProbability" << std::endl;
	
	float probability = 0.0;
	
	for (int i = 0; i <= 10; i += 1)
	{
		
		probability = (results[i] / static_cast<float> (first_die[0])) * 100;
		std::cout << '\t' << i + 2 << '\t' << results[i] << '\t' << probability << '%' << std::endl;
	}
}


void roll_dice (unsigned int *rolls)
{
	
	for (int i = 1; i <= rolls[0]; i += 1)
	{

		rolls[i] = static_cast<unsigned short int> (std::rand () % 6) + 1;
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