#include <iostream>
#include <cstdlib>

#include "fibonacci_sequence.h"


class player
{
public:
	player ();
	
	char hand;
	
	void won () {
		wins += 1;
		consecutive_wins += 1;
		consecutive_losses = 0;
		
		experience += (fib_num.fibonacci_number (level)/level);
		check_for_levelup ();
	}
	
	void lost () {
		losses += 1;
		consecutive_losses += 1;
		consecutive_wins = 0;
	}
	
	void tie () {
		ties += 1;
		consecutive_ties += 1;
		consecutive_wins = 0;
		consecutive_losses = 0;
	}
	
	const char *get_name () {return name;};
	const bool predict_hand ();
	void display_current_stats ();

private:
	char *name;
	
	int wins;
	int consecutive_wins;
	int losses;
	int consecutive_losses;
	int ties;
	int consecutive_ties;
	
	Fibonacci_Number fib_num;
	int experience;
	int level;
	int level_exp;
	static const int MAX_LEVEL = 20;
	
	int detect_chance () {return (level/* divided by MAX_LEVEL ? */);};
	
	void ask_for_name (char *name);
	
	void check_for_levelup ();
	void levelup ();
};


player::player (void)
{
	
	name = new char[64];
	ask_for_name (name);

	wins = 0;
	consecutive_wins = 0;
	losses = 0;
	consecutive_losses = 0;
	
	experience = 0;
	level = 1;
	level_exp = fib_num.fibonacci_number (4);
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
	level_exp = fib_num.fibonacci_number (level);
	
	std::cout << std::endl << std::endl << "Congratulations, " << name << "! You have reached level " << level << '!' << std::endl << "Due to your newly earned skill, you have a " << detect_chance () << '/' << MAX_LEVEL << " chance to correctly predict your opponent's hand." << std::endl;
}


void player::display_current_stats ()
{
	
	std::cout << std::endl << "Level: " << level << std::endl;
	std::cout << "Progress Towards Next Level: " << ((level * 10.0)/(level_exp * 10.0))*100 << '%' << std::endl;
	
	std::cout << "Prediction Accuracy: " << detect_chance () << std::endl << std::endl;
}


const bool player::predict_hand ()
{
	
	const int rand_num = std::rand () % MAX_LEVEL;
	
	if (rand_num - detect_chance () <= 0)
		return true;
	else
		return false;
}


void get_rand_hand (char &hand)
{
	
	const int rand_num = std::rand () % 3;
	
	switch (rand_num)
	{
		
		case 0:
		hand = 'r';
		break;
		
		case 1:
		hand = 'p';
		break;
		
		case 2:
		hand = 's';
		break;
		
		default:
		throw std::runtime_error ("Random number out of bounds in `void get_rand_hand (char &hand)`");
		break;
	}
}


void display_guess (player &user, char &comp_hand, char &guess)
{
	
	//std::cout << comp_hand << std::endl;
	
	if (user.predict_hand ())
	{
		guess = comp_hand;
		//std::cout << "success" << std::endl;
	} else {
		get_rand_hand (guess);
		//std::cout << "failure" << std::endl;
	}
	
	std::cout << "You think that your opponent will play ";
	
	switch (guess)
	{
		
		case 'r':
		std::cout << "rock";
		break;
		
		case 'p':
		std::cout << "paper";
		break;
		
		case 's':
		std::cout << "scissors";
		break;
	}
	
	std::cout << '.' << std::endl;
}


void get_user_hand (char &user_hand)
{
	
	char input;
	char confirm;
	
	do
	{
		
		confirm = '\0';
	
		std::cout << "What will you play? (r) Rock, (p) Paper, (s) Scissors: ";
		std::cin >> input;
		
		switch (input)
		{
			
			case 1:
			case 'r':
			std::cout << "You'll play rock!" << std::endl;
			break;
		
			case 2:
			case 'p':
			std::cout << "You'll play paper!" << std::endl;
			break;
		
			case 3:
			case 's':
			std::cout << "You'll play scissors!" << std::endl;
			break;
			
			default:
			confirm = 'n';
			std::cout << "I couldn't understand what you meant by " << input << '.' << std::endl;
			break;
		}
		
		if (confirm != 'n')
		{
			
			std::cout << "Is that right? (y/n): ";
			std::cin >> confirm;
			std::cout << std::endl;
		}
		
	} while (confirm != tolower ('y'));
	
	user_hand = input;
}


void play_results (const char user_hand, const char comp_hand)
{
	
	//compare hands
	//player.won () or player.lost ()
	//cout
}


void final_results (const player &user)
{
	
	//cout user score
}


int main (int argc, char const *argv[])
{
	
	std::cout << std::endl << "Project 2 from Assignment 2" << std::endl << "Rock Paper Scissors" << std::endl << std::endl << "This is a random-chance game of rock paper scissors." << std::endl << "===" << std::endl << std::endl;
	
	std::srand (std::time (NULL));
	
	player user;
	char comp_hand;
	char guess;
	
	std::cout << user.get_name () << ", it's time to play Rock Paper Scissors!" << std::endl;
	
	char play_again;
	do
	{
		
		get_rand_hand (comp_hand);
		display_guess (user, comp_hand, guess);
		get_user_hand (user.hand);
		
		play_results (user.hand, comp_hand);
		
		user.display_current_stats ();
		std::cout << "Continue playing? (y/n)" << std::endl;
		std::cin >> play_again;
	} while (play_again != tolower ('n'));
	
	final_results (user);
	
	return 0;
}