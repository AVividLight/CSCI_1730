#include <iostream>


int main (int argc, char const *argv[])
{
	
	std::cout << std::endl << "Project 1 from Assignment 1" << std::endl << "Pound Conversion" << std::endl << std::endl << "This program will sum two old-pound values and display the result in old-pounds and new-pounds." << std::endl << std::endl;
	
	char *value_one_pounds;
	char *value_two;
	char dot;

	std::cout << "Enter a value in old-pounds (matching pattern #.#.#): ";
	std::cin >> value_one_pounds; //value_one.pounds >> dot >> old_pounds_value.shillings >> dot >> old_pounds_value.pence;

	return value_one_pounds; //old_pounds_value;
	
	//std::cout << "Old-pound total: " << sum_old_pounds (value_one, value_two) << std::endl;
	//std::cout << "New-pound total: " << sum_new_pounds (value_one, value_two) << std::endl;
	
	return 0;
}