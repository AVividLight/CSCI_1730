#include <iostream>
#include <cstdlib>

#include "fibonacci_sequence.h"


#ifdef _WIN32
	#include <windows.h>
	void sleep_seconds (const unsigned int sleepMSs) { Sleep (sleepMSs); }
#elif defined (__unix__) || (defined (__APPLE__) && defined (__MACH__))
	#include <unistd.h>
	void sleep_seconds (const unsigned int sleepMSs) { usleep (sleepMSs * 1000000); }
#endif


enum HAND { Rock = 0, Paper = 1, Scissors = 2 };
std::ostream &operator<< (std::ostream &out, const HAND &hand)
{
	
	switch (hand)
	{
		
		case 0:
		std::cout << "Rock";
		break;
		
		case 1:
		std::cout << "Paper";
		break;
		
		case 2:
		std::cout << "Scissors";
		break;
	}
	
	return out;
}
	

class player
{
public:
	player ();
	
	void won () {
		wins += 1;
		consecutive_wins += 1;
		consecutive_losses = 0;
		
		experience += ((1.0/level) + consecutive_wins/4.0);
		check_for_levelup ();
	}
	
	void lost () {
		losses += 1;
		consecutive_losses += 1;
		consecutive_wins = 0;
	}
	
	void tied () {
		ties += 1;
		consecutive_ties += 1;
		consecutive_wins = 0;
		consecutive_losses = 0;
	}
	
	char *get_name () const {return name;};
	int get_level () const {return level;};
	HAND get_hand () const {return hand;};
	void set_hand (HAND new_hand) {hand = new_hand;};
	const bool predict_hand ();
	int get_wins () const {return wins;};
	int get_losses () const {return losses;};
	int get_ties () const {return ties;};
	int games_played () const {return (wins + ties + losses + 1);};
	void display_current_stats () const;

private:
	char *name;
	HAND hand;
	
	int wins;
	int consecutive_wins;
	int losses;
	int consecutive_losses;
	int ties;
	int consecutive_ties;
	
	Fibonacci_Number fib_num;
	float experience;
	int level;
	float level_exp;
	static const int MAX_LEVEL = 20;
	
	int detect_chance () const {return (level/* divided by MAX_LEVEL ? */);};
	
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
	
	experience = 0.0;
	level = 1;
	level_exp = 1;
}


void player::ask_for_name (char *name)
{
	
	char confirm;
	
	do
	{

		std::cout << "What is your name?" << std::endl;
		std::cin >> name;
		std::cout << std::endl;
		std::cout << "Hello, " << name << "! Is this the name that you want to use? (y/n): ";
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
	
	std::cout << std::endl << std::endl << "LEVEL UP!" << std::endl << "Congratulations, " << name << ", you have reached level " << level << '!' << std::endl << "Due to your newly earned skill, you have a " << detect_chance () << '/' << MAX_LEVEL << " chance to correctly predict your opponent's hand." << std::endl;
}


void player::display_current_stats () const
{
	
	std::cout << std::endl << "Level: " << level << std::endl;
	std::cout << "Progress Towards Next Level: " << 100 - ((level_exp - experience)/level_exp * 100) << '%' << std::endl;
	
	std::cout << "Prediction Accuracy: " << detect_chance () << '/' << MAX_LEVEL << std::endl << std::endl;
}


const bool player::predict_hand ()
{
	
	const int rand_num = std::rand () % MAX_LEVEL;
	
	if (rand_num - detect_chance () <= 0)
		return true;
	else
		return false;
}


HAND get_rand_hand ()
{
	
	return static_cast<HAND> (std::rand () % 3);
}


void display_guess (player &user, HAND &comp_hand, HAND &guess)
{
	
	//std::cout << "Computer hand: " << comp_hand << std::endl;
	
	if (user.predict_hand ())
	{
		guess = comp_hand;
		//std::cout << "Guess Succeeded" << std::endl;
	} else {
		guess = get_rand_hand ();
		//std::cout << "Guess Failed, Random Guess:" << std::endl;
	}
	
	std::cout << "You think that your opponent will play ";
	
	switch (guess)
	{
		
		case Rock:
		std::cout << "rock";
		break;
		
		case Paper:
		std::cout << "paper";
		break;
		
		case Scissors:
		std::cout << "scissors";
		break;
	}
	
	std::cout << '.' << std::endl;
}


HAND ask_user_hand ()
{
	
	char input;
	char confirm;
	
	do
	{
		
		confirm = '\0';
	
		std::cout << "What will you play? (r) Rock, (p) Paper, (s) Scissors: ";
		std::cin >> input;
		
		switch (tolower (input))
		{
			
			case '1':
			case 'r':
			std::cout << "You'll play rock!" << std::endl;
			input = 0;
			break;
		
			case '2':
			case 'p':
			std::cout << "You'll play paper!" << std::endl;
			input = 1;
			break;
		
			case '3':
			case 's':
			std::cout << "You'll play scissors!" << std::endl;
			input = 2;
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
	
	return static_cast<HAND> (input);
}


void play_results (player &user, const HAND comp_hand)
{
	
	if ((user.get_hand () == Rock && comp_hand == Scissors) || (user.get_hand () == Scissors && comp_hand == Paper) || (user.get_hand () == Paper && comp_hand == Rock))
	{
		
		std::cout << "You won! " << user.get_hand () << " beats " << comp_hand << std::endl;
		user.won ();
	} else if (user.get_hand () == comp_hand) {
		
		std::cout << "You tied! " << std::endl;
		user.tied ();
	} else {
		
		std::cout << "You lost! " << user.get_hand () << " loses to " << comp_hand << std::endl;
		user.lost ();
	}
}


void final_results (const player &user)
{
	
	std::cout << std::endl << "The final scores are in!" << std::endl << user.get_name () << " played " << user.games_played () << " games, winning " << user.get_wins () << ". " << user.get_name () << " lost " << user.get_losses () << " games, and tied " << user.get_ties () << '.' << std::endl;
	user.display_current_stats ();
}


void countdown ()
{
	
	for (int i = 3; i > 0; i -= 1)
	{
		
		std::cout << i << "..." << std::endl;
		sleep_seconds (1);
	}
	
	std::cout << "Shoot!" << std::endl << std::endl;
}


bool replay (char &play_again)
{
	
	std::cout << "Continue playing? (y/n): ";
	std::cin >> play_again;
	std::cout << std::endl;
	
	if (play_again != tolower ('n'))
		return true;
	else
		return false;
}


int main (int argc, char const *argv[])
{
	
	std::cout << std::endl << "Project 2 from Assignment 2" << std::endl << "Rock Paper Scissors" << std::endl << std::endl << "This is a random-chance game of rock paper scissors." << std::endl << "===" << std::endl << std::endl;
	
	std::srand (std::time (NULL));
	
	player user;
	HAND comp_hand;
	HAND guess;
	
	std::cout << std::endl << user.get_name () << ", it's time to play Rock Paper Scissors!" << std::endl << std::endl;
	
	char play_again;
	do
	{
		
		std::cout << "Round " << user.games_played () << std::endl;
		
		comp_hand = get_rand_hand ();
		
		if (user.get_level () > 1)
			display_guess (user, comp_hand, guess);
		
		user.set_hand (ask_user_hand ());
		
		countdown ();
		
		play_results (user, comp_hand);
		user.display_current_stats ();
		
	} while (replay (play_again));
	
	final_results (user);
	
	return 0;
}