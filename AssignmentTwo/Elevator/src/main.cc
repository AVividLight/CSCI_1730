#include <iostream>


int ask_for_elevators ();


class Elevator
{
public:
	Elevator ();
	virtual ~Elevator ();
	
	char get_name () const {return name;}
	void set_name (int i) {name += i;}

private:
	char name;
};


Elevator::Elevator ()
{
	
	name = 'A';
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
		
		std::cout << "Elevator " << elevator->get_name () << std::endl;
	}
}


int main (int argc, char const *argv[])
{
	
	std::cout << std::endl << "Project 6 from Assignment 2" << std::endl << "Elevator" << std::endl << std::endl << "This program will simulate the operation of an elevator." << std::endl << std::endl;
	
	Building building;
	
	display_elevator_status (building);
	
	return 0;
}