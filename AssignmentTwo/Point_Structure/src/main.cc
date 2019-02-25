#include <iostream>
#include <cmath>


struct Point
{
	
	float x;
	float y;
	
	float distance (const Point other_point) const;
	float slope (const Point other_point) const;
	Point midpoint (const Point other_point) const;
	char *equation () const;
	
	Point ();
	Point (float assign_x, float assign_y);
	~Point ();
	
	friend std::ostream &operator<< (std::ostream &os, const Point &pt);
};


Point::Point ()
{
	
	x = 0.0;
	y = 0.0;
}


Point::Point (float assign_x, float assign_y)
{
	
	x = assign_x;
	y = assign_y;
}


Point::~Point () {}


std::ostream &operator<< (std::ostream &os, const Point &pt)
{
	
    os << '(' << pt.x << ", " << pt.y << ')';
    return os;
}


float Point::distance (const Point other_point) const
{
	
	return sqrt (pow ((other_point.x - x), 2) + pow ((other_point.y - y), 2));
}


float Point::slope (const Point other_point) const
{
	
	return ((other_point.y - y)/(other_point.x - x));
}


Point Point::midpoint (const Point other_point) const
{
	
	Point midpoint (((x + other_point.x)/2), ((y + other_point.y)/2));
	
	return midpoint;
}


char *Point::equation () const
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


void get_input (Point &p)
{
	
	std::cout << "\tEnter a value for X: ";
	std::cin >> p.x;
	std::cin.clear ();
	std::cin.ignore (1000, '\n');
	
	std::cout << "\tEnter a value for Y: ";
	std::cin >> p.y;
	std::cin.clear ();
	std::cin.ignore (1000, '\n');
}


void menu_distance (Point &p_1, Point &p_2)
{
	
	std::cout << std::endl << "1. Distance Between Two Points" << std::endl << "Point One" << std::endl;
	get_input (p_1);
	std::cout << "Point Two" << std::endl;
	get_input (p_2);
	std::cout << std::endl << "Distance between " << p_1 << " & " << p_2 << ": " << p_1.distance (p_2) << std::endl << std::endl;
}


void menu_slope (Point &p_1, Point &p_2)
{
	
	std::cout << std::endl << "2. Find Slope" << std::endl;
	std::cout << "Point One" << std::endl;
	get_input (p_1);
	std::cout << "Point Two" << std::endl;
	get_input (p_2);
	
	std::cout << std::endl << "Slope between " << p_1 << " & " << p_2 << ": ";
	
	if (p_1.x != p_2.x)
		std::cout << p_1.slope (p_2) << std::endl << std::endl;
	else
		std::cout << "Undefined" << std::endl << std::endl;
}


void menu_midpoint (Point &p_1, Point &p_2)
{
	
	std::cout << std::endl << "3. Midpoint Between Two Points" << std::endl << "Point One" << std::endl;
	get_input (p_1);
	std::cout << "Point Two" << std::endl;
	get_input (p_2);
	std::cout << std::endl << "Midpoint between " << p_1 << " & " << p_2 << ": " << p_1.midpoint (p_2) << std::endl << std::endl;
}


void menu_equation (Point &p_1, Point &p_2)
{
	
	
}


void menu_collinear (Point &p_1, Point &p_2)
{
	
	Point p_3;
	
	std::cout << std::endl << "5. Determine if Points are Collinear" << std::endl;
	std::cout << "Point One" << std::endl;
	get_input (p_1);
	std::cout << "Point Two" << std::endl;
	get_input (p_2);
	std::cout << "Point Three" << std::endl;
	get_input (p_3);
	
	std::cout << std::endl << "Points " << p_1 << ", " << p_2 << ", and " << p_3 << " are ";
	
	if (p_1.slope (p_2) == p_2.slope (p_3))
		std::cout << "collinear" << std::endl << std::endl;
	else
		std::cout << "not collinear" << std::endl << std::endl;
}


int main (int argc, char const *argv[])
{
	
	std::cout << std::endl << "Project 5 from Assignment 2" << std::endl << "Point Structure" << std::endl << std::endl << "This program will provide a menu for various functions relating to points in a Cartesian coordinate system." << std::endl << std::endl;
	
	Point p_1;
	Point p_2;
	
	unsigned short int menu = 0;
	bool loop = true;

	while (loop == true)
	{
	
		std::cout << "Possible Operations" << std::endl << "1. Find Distance Between Two Points" << std::endl << "2. Find Slope" << std::endl << "3. Find Midpoint" << std::endl << "4. Find Equation of Line" << std::endl << "5. Determine if Points are Colinear" << std::endl << "6. Exit" << std::endl << std::endl;
		
		get_input (menu);
		switch (menu)
		{
			
			case 1:
			menu_distance (p_1, p_2);
			break;
			
			case 2:
			menu_slope (p_1, p_2);
			break;
			
			case 3:
			menu_midpoint (p_1, p_2);
			break;
			
			case 4:
			menu_equation (p_1, p_2);
			break;
			
			case 5:
			menu_collinear (p_1, p_2);
			break;
			
			default:
			loop = false;
			break;
		}
	}
	
	return 0;
}