#include <iostream>


struct Point
{
	
	float x;
	float y;
	
	float dist ();
	float slope ();
	char *midpoint ();
	char *equation ();
	char *colinear ();
};


float Point::dist ()
{
	
	return 0.0;
}


float Point::slope ()
{
	
	return 0.0;
}


char *Point::midpoint ()
{
	
	
}


char *Point::equation ()
{
	
	
}


char *Point::colinear ()
{
	
	
}


void get_input (unsigned short int &input)
{
	
	do
	{
		
		std::cout << "Select an operation: ";
		std::cin >> input;
		
		std::cin.clear ();
		std::cin.ignore (1000, '\n');
		
	} while (input < 0 && input > 7);
}


int main (int argc, char const *argv[])
{
	
	std::cout << std::endl << "Project 5 from Assignment 2" << std::endl << "Point Structure" << std::endl << std::endl << "This program will provide a menu for various functions relating to points in a Cartesian coordinate system." << std::endl << std::endl;
	
	bool loop = true;
	unsigned short int menu = 0;
	while (loop == true)
	{
	
		std::cout << "Possible Operations" << std::endl << "1. Find Distance Between Two Points" << std::endl << "2. Find Slope" << std::endl << "3. Find Midpoint" << std::endl << "4. Find Equation of Line" << std::endl << "5. Determine if Points are Colinear" << std::endl << "6. Exit" << std::endl << std::endl;
		
		get_input (menu);
		switch (menu)
		{
			
			case 1:
			break;
			
			case 2:
			break;
			
			case 3:
			break;
			
			case 4:
			break;
			
			case 5:
			break;
			
			default:
			loop = false;
			break;
		}
	}
	
	return 0;
}