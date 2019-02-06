#include <iostream>


//const char *ascii_circle = "    x  x\n x        x\nx          x\nx          x\n x        x\n    x  x";
//const char *ascii_rectangle = "+---------+\n|         |\n|         |\n|         |\n|         |\n+---------+";
//const char *ascii_triangle = "     /\\\n    /  \\\n   /    \\\n  /      \\\n /        \\\n/__________\\";

const char *ascii_menu = "    x  x         +---------+  	     /\\\n x        x      |         |  	    /  \\\nx          x	 |         |  	   /    \\\nx          x     |         |  	  /      \\\n x        x      |         |  	 /        \\\n    x  x         +---------+  	/__________\\\n (c) Circle	(r) Rectangle    (t) Triangle";
const float pi = 3.141592654;


void get_dimensions ()
{
	
	std::cout << "Enter ";
}


int main (int argc, char const *argv[])
{
	
	std::cout << std::endl << "Project 1 from Assignment 2" << std::endl << "Geometry Calculations" << std::endl << std::endl << "This program will prompt for a shape and dimensions, then return its area and perimeter." << std::endl << std::endl;
	
	char menu;
	
	do {
		std::cout << ascii_menu << std::endl << std::endl;
		std::cout << " (e) Exit" << std::endl;
		
		std::cin >> menu;
		menu = tolower (menu);
		
		switch (menu)
		{
			
			case 'c':
			get_dimensions ();
			break;
			
			case 'r':
			get_dimensions ();
			break;
			
			case 't':
			get_dimensions ();
			break;
			
			default:
			break;
		}
		
	} while (menu != 'e');
	
	return 0;
}