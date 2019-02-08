#include <iostream>
#include <cstdlib>

#include "fibonacci_sequence.h"


class player
{
public:
	player ();
	
	void won () {
		wins += 1;
		consecutive_wins += 1;
		consecutive_losses = 0;
		
		experience += (fib_num.next_fibonacci_number (level)/level);
		check_for_levelup ();
	}
	void lost () {
		losses += 1;
		consecutive_losses += 1;
		consecutive_wins = 0;
	}

private:
	char *name;
	
	int wins;
	int consecutive_wins;
	int losses;
	int consecutive_losses;
	
	Fibonacci_Number fib_num;
	int experience;
	int level;
	int level_exp;
	static const int MAX_LEVEL = 20;
	
	int hand;
	int detect_chance () {return (level);};
	
	void ask_for_name (char *name);
	
	void check_for_levelup ();
	void levelup ();
};


player::player (void)
{
	
	name = new char[512];
	ask_for_name (name);

	wins = 0;
	consecutive_wins = 0;
	losses = 0;
	consecutive_losses = 0;
	
	experience = 0;
	level = 1;
	level_exp = fib_num.next_fibonacci_number (level);
}


void player::ask_for_name (char *name)
{
	
	char confirm;
	
	do
	{

		std::cout << "What is your name?" << std::endl;
		std::cin >> name;
		std::cout << std::endl;
		std::cout << "Hello, " << name << "! Is this the name that you want to use (y/n)?" << std::endl;
		std::cin >> confirm;
		std::cout << std::endl;
	} while (confirm != tolower ('y'));
}


void player::check_for_levelup ()
{
	
	if (experience >= level_exp)
	{
		
		levelup ();
	} else {
		
		std::cout << "Only " << (level_exp - experience) << " experience points to level " << (level + 1) << '!' << std::endl;
	}
}


void player::levelup ()
{
	
	level += 1;
	level_exp = fib_num.next_fibonacci_number (level);
	
	std::cout << std::endl << std::endl << "Congratulations, " << name << "! You have reached level " << level << '!' << std::endl << "Due to your newly earned skill, you have a " << detect_chance () << '/' << MAX_LEVEL << " chance to correctly predict your opponent's hand." << std::endl;
}


int main (int argc, char const *argv[])
{
	
	std::cout << std::endl << "Project 2 from Assignment 2" << std::endl << "Rock Paper Scissors" << std::endl << std::endl << "This is a random-chance game of rock paper scissors." << std::endl << std::endl;
	
	std::srand (std::time (NULL));
	//std::cout << std::rand() % 3 << std::endl << std::endl;
	
	player human;
	
	return 0;
}