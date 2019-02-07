#include <iostream>
#include <cmath>


const char *ascii_menu = "    x  x         +---------+  	     /\\\n x        x      |         |  	    /  \\\nx          x	 |         |  	   /    \\\nx          x     |         |  	  /      \\\n x        x      |         |  	 /        \\\n    x  x         +---------+  	/__________\\\n (c) Circle	(r) Rectangle    (t) Triangle";
const float pi = 3.141592654;


struct circle
{
	
	float radius;
	
	circle (): radius (0) {}
};


struct rectangle
{

	float length;
	float width;
	
	rectangle (): length (0), width (0) {}
};


struct triangle
{

	float side_one;
	float side_two;
	float side_three;
	
	triangle (): side_one (0), side_two (0), side_three (0) {}
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


const float area (const circle &circ)
{
	
	return (pi * circ.radius * circ.radius);
}


const float area (const rectangle &rect)
{
	
	return (rect.length * rect.width);
}

const float area (const triangle &tri)
{
	
	float half_sides = ((tri.side_one + tri.side_two + tri.side_three)/2);
	return (sqrt (half_sides * (half_sides - tri.side_one) * (half_sides - tri.side_two) * (half_sides - tri.side_three)));
}


const float perimeter (const circle &circ)
{
	
	return (2 * pi * circ.radius);
}


const float perimeter (const rectangle &rect)
{
	
	return ((2 * rect.length) + (2 * rect.width));
}


const float perimeter (const triangle &tri)
{
	
	return (tri.side_one + tri.side_two + tri.side_three);
}


const void display (const char *menu, const float found_area, const float found_perimeter)
{
	
	std::cout << std::endl << menu << " Area: " << found_area << ", " << menu << " Perimeter: " << found_perimeter << std::endl << std::endl << std::endl;;
}


int main (int argc, char const *argv[])
{
	
	std::cout << std::endl << "Project 1 from Assignment 2" << std::endl << "Geometry Calculations" << std::endl << std::endl << "This program will prompt for a shape and dimensions, then return its area and perimeter." << std::endl << std::endl;
	
	char menu;
	
	circle circ;
	rectangle rect;
	triangle tri;
	
	do {
		std::cout << "AREA/PERIMETER CALCULATOR" << std::endl;
		std::cout << ascii_menu << std::endl << std::endl;
		std::cout << " (e) Exit" << std::endl << std::endl;
		
		std::cout << "Enter selection: ";
		std::cin >> menu;
		menu = tolower (menu);
		
		std::cout << std::endl;
		
		switch (menu)
		{
			
			case 'c':
			case '1':
			get_dimensions (circ);
			display ("Circle", area (circ), perimeter (circ));
			break;
			
			case 'r':
			case '2':
			get_dimensions (rect);
			display ("Rectangle", area (rect), perimeter (rect));
			break;
			
			case 't':
			case '3':
			get_dimensions (tri);
			display ("Triangle", area (tri), perimeter (tri));
			break;
			
			default:
			break;
		}
		
	} while (menu != 'e' && menu != '4');
	
	std::cout << "Bye..." << std::endl;
	
	return 0;
}