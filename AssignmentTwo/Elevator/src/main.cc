#include <iostream>
#include <cctype>

#ifdef _WIN32
	#include <windows.h>
	void sleep_seconds (const unsigned int sleepMSs) { Sleep (sleepMSs * 1000); }
#elif defined (__unix__) || (defined (__APPLE__) && defined (__MACH__))
	#include <unistd.h>
	void sleep_seconds (const unsigned int sleepMSs) { usleep (sleepMSs * 1000000); }
#endif


int ask_for_elevators ();


class Elevator
{
public:
	Elevator ();
	
	char get_name () const {return name;}
	void set_name (int i) {name += i;}
	
	int get_level () const {return level;}
	void set_level (int i) {level = i;}
	
	void travel (short int new_floor);

private:
	char name;
	int level;
};


Elevator::Elevator ()
{
	
	name = 'A';
	level = 0;
}


void Elevator::travel (short int new_floor)
{
	
	while (level != new_floor)
	{
		
		if (new_floor > level)
		{
			
			sleep_seconds (1);
			level += 1;
			std::cout << "Going up - now on floor " << level << std::endl;
		} else
		{
		
			sleep_seconds (1);
			level -= 1;
			std::cout << "Going down - now on floor " << level << std::endl;
		}
	}
	
	std::cout << "You have arrived!" << std::endl;
}


class Building
{
public:
	Building ();
	
	int elevators_in_building () const {return elevators_quantity;}
	Elevator *get_elevator (int index) {return &elevators[index];}

private:
	int elevators_quantity;
	Elevator *elevators;
	
	void name_elevators ();
};


Building::Building ()
{
	
	elevators_quantity = ask_for_elevators ();
	elevators = new Elevator [elevators_quantity];
	name_elevators ();
}


void Building::name_elevators ()
{
	
	for (int i = 0; i < elevators_quantity; i += 1)
	{
		
		elevators[i].set_name (i);
	}
}


int ask_for_elevators ()
{
	
	unsigned short int input;
	while (true)
	{
		
		std::cout << "How many elevators should be simulated? ";
		std::cin >> input;
		
		if (std::cin.fail ())
		{
			
			std::cout << "Please enter a positive integer number of elevators." << std::endl << std::endl;
			std::cin.clear ();
			std::cin.ignore (1000, '\n');
		} else break;
	}
	
	return input;
}


void display_elevator_status (Building &building)
{
	
	std::cout << "Elevator Status" << std::endl;
	
	for (int i = 0; i < building.elevators_in_building (); i += 1)
	{
		
		Elevator *elevator = building.get_elevator (i);
		
		std::cout << "Elevator " << elevator->get_name () << " is on level " << elevator->get_level () << std::endl;
	}
	
	std::cout << std::endl;
}


int main (int argc, char const *argv[])
{
	
	std::cout << std::endl << "Project 6 from Assignment 2" << std::endl << "Elevator" << std::endl << std::endl << "This program will simulate the operation of an elevator." << std::endl << std::endl;
	
	Building building;
	
	char input;
	unsigned short int elevator_choice;
	short int level;
	bool loop = true;
	while (loop == true)
	{
		
		display_elevator_status (building);
		std::cout << "Which elevator do you want to use? (enter 0 to quit)" << std::endl << "Elevator: ";
		std::cin >> input;
		std::cout << std::endl;
		
		if (isalpha (input))
		{
			
			elevator_choice = (int) toupper (input) - (int) 'A';
			
			if (elevator_choice < building.elevators_in_building ())
			{
			
				std::cout << "Which floor are you going to?" << std::endl << "Floor: ";
				std::cin >> level;
				
				if (!std::cin.fail ())
				{
					
					building.get_elevator (elevator_choice)->travel (level);
				} else {
					
					std::cout << "Unknown value for building level." << std::endl;
					std::cin.clear ();
					std::cin.ignore (1000, '\n');
				}
			} else {
				std::cout << "That elevator does not exist!" << std::endl;
			}
		} else if (input == '0') {
			loop = false;
		} else {
			
			std::cout << input << " is not a known elevator." << std::endl;
			std::cin.clear ();
			std::cin.ignore (1000, '\n');
		}
		
		std::cout << std::endl;
	}
	
	return 0;
}