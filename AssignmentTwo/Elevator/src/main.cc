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
	virtual ~Elevator ();
	
	char get_name () const {return name;}
	void set_name (int i) {name += i;}
	
	int get_level () const {return level;}

private:
	char name;
	int level;
};


Elevator::Elevator ()
{
	
	name = 'A';
	level = 0;
}


Elevator::~Elevator () {}


class Building
{
public:
	Building ();
	virtual ~Building ();
	
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


Building::~Building () {}


void Building::name_elevators ()
{
	
	for (int i = 0; i < elevators_quantity; i += 1)
	{
		
		elevators[i].set_name (i);
	}
}


int ask_for_elevators ()
{
	
	std::cout << "How many elevators should be simulated? ";
	
	unsigned short int input;
	std::cin >> input;
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
}


int main (int argc, char const *argv[])
{
	
	std::cout << std::endl << "Project 6 from Assignment 2" << std::endl << "Elevator" << std::endl << std::endl << "This program will simulate the operation of an elevator." << std::endl << std::endl;
	
	Building building;
	
	char input;
	int elevator_choice;
	bool loop = true;
	while (loop == true)
	{
		
		display_elevator_status (building);
		std::cout << "Which elevator do you want to use?";
		std::cin >> input;
		
		if (isalpha (input) && input < building.elevators_in_building ())
		{
			
			//std::cout << // convert char to int
		} else {
			
			std::cout << input << " is not a known elevator." << std::endl;
		}
	}
	
	return 0;
}