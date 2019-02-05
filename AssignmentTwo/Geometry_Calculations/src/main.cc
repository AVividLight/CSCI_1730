#include <iostream>


const char *ascii_circle = "    x  x\n x        x\nx          x\nx          x\n x        x\n    x  x";
const char *ascii_rectangle = "+---------+\n|         |\n|         |\n|         |\n|         |\n+---------+";
const char *ascii_triangle = "     /\\\n    /  \\\n   /    \\\n  /      \\\n /        \\\n/__________\\";


void get_dimensions ()
{
	
	std::cout << "Enter ";
}


int main (int argc, char const *argv[])
{
	
	std::cout << std::endl << "Project 1 from Assignment 2" << std::endl << "Geometry Calculations" << std::endl << std::endl << "This program will prompt for a shape and dimensions, then return its area and perimeter." << std::endl << std::endl;
	
	std::cout << ascii_circle << std::endl << "(c) Circle" << std::endl;
	
	std::cout << ascii_rectangle << std::endl << "(r) Rectangle" << std::endl;
	
	std::cout << ascii_triangle << std::endl << "(t) Triangle" << std::endl;
	
	return 0;
}