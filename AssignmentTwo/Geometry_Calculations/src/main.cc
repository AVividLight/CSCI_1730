#include <iostream>
#include <cmath>


const char *ascii_menu = "    x  x         +---------+  	     /\\\n x        x      |         |  	    /  \\\nx          x	 |         |  	   /    \\\nx          x     |         |  	  /      \\\n x        x      |         |  	 /        \\\n    x  x         +---------+  	/__________\\\n (c) Circle	(r) Rectangle    (t) Triangle";
const float pi = 3.141592654;


struct circle
{
	
	float radius;
};


struct rectangle
{

	float length;
	float width;
};


struct triangle
{

	float side_one;
	float side_two;
	float side_three;
};


void get_dimensions (circle &new_circle)
{
	
	std::cout << "Enter circle radius: ";
	std::cin >> new_circle.radius;
}


void get_dimensions (rectangle &new_rectangle)
{
	
	std::cout << "Enter rectangle length: ";
	std::cin >> new_rectangle.length;
	
	std::cout << "Enter rectangle width: ";
	std::cin >> new_rectangle.width;
}


void get_dimensions (triangle &new_triangle)
{
	
	std::cout << "Enter triangle side one: ";
	std::cin >> new_triangle.side_one;
	
	std::cout << "Enter triangle side two: ";
	std::cin >> new_triangle.side_two;
	
	std::cout << "Enter triangle side three: ";
	std::cin >> new_triangle.side_three;
}


float area (const circle &new_circle)
{
	
	return (pi * new_circle.radius * new_circle.radius);
}


float area (const rectangle &new_rectangle)
{
	
	return (new_rectangle.length * new_rectangle.width);
}

float area (const triangle &new_triangle)
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
			rectangle new_rectangle;
			get_dimensions (new_rectangle);
			break;
			
			case 't':
			triangle new_triangle;
			get_dimensions (new_triangle);
			break;
			
			default:
			break;
		}
		
	} while (menu != 'e');
	
	return 0;
}