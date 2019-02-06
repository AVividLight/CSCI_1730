#include <iostream>


const char *ascii_menu = "    x  x         +---------+  	     /\\\n x        x      |         |  	    /  \\\nx          x	 |         |  	   /    \\\nx          x     |         |  	  /      \\\n x        x      |         |  	 /        \\\n    x  x         +---------+  	/__________\\\n (c) Circle	(r) Rectangle    (t) Triangle";
const float pi = 3.141592654;


struct circle
{
	
	float radius;
};


struct rectangle
{

	float s;
};


void get_dimensions (circle &new_circle)
{
	
	std::cout << "Enter circle radius: ";
	std::cin >> new_circle.radius;
}


void get_dimensions (float length, float width)
{
	
	
}


void get_dimensions (float side_one, float side_two, float side_three)
{
	
	
}


int main (int argc, char const *argv[])
{
	
	std::cout << std::endl << "Project 1 from Assignment 2" << std::endl << "Geometry Calculations" << std::endl << std::endl << "This program will prompt for a shape and dimensions, then return its area and perimeter." << std::endl << std::endl;
	
	char menu;
	
	do {
		std::cout << ascii_menu << std::endl << std::endl;
		std::cout << " (e) Exit" << std::endl << std::endl;
		
		std::cout << "Enter selection: ";
		std::cin >> menu;
		menu = tolower (menu);
		
		switch (menu)
		{
			
			case 'c':
			circle new_circle;
			get_dimensions (new_circle);
			break;
			
			case 'r':
			//get_dimensions ();
			break;
			
			case 't':
			//get_dimensions ();
			break;
			
			default:
			break;
		}
		
	} while (menu != 'e');
	
	return 0;
}