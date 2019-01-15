#include <iostream>
#include <string>


//20 shillings to a pound, and 12 pence to a shilling


struct new_pounds
{

	int pounds;
	int pence;
	
	std::string to_string ();
};

std::string new_pounds::to_string ()
{
	
	return "£" + std::to_string (pounds) + '.' + std::to_string (pence);
}


struct old_pounds
{
	
	int pounds;
	int shillings;
	int pence;
	
	std::string to_string ();
};


std::string old_pounds::to_string ()
{
	
	return "£" + std::to_string (pounds) + '.' + std::to_string (shillings) + '.' + std::to_string (pence);
}


old_pounds ask_for_input ()
{
	char dot;
	
	old_pounds old_pounds_value;
	
	std::string input_value;
	std::cout << "Enter a value in old-pounds (matching pattern #.#.#): ";
	std::cin >> old_pounds_value.pounds >> dot >> old_pounds_value.shillings >> dot >> old_pounds_value.pence;

	//std::cout << "Value: " << old_pounds_value.to_string () << std::endl;

	return old_pounds_value;
}


std::string sum_old_pounds (old_pounds value_one, old_pounds value_two)
{
	
	int pence_sum = value_one.pence + value_two.pence;
	int shillings_sum = value_one.shillings + value_two.shillings;
	int pounds_sum = value_one.pounds + value_two.pounds;
	
	shillings_sum += pence_sum/12;
	pence_sum = pence_sum%12;
	
	pounds_sum += shillings_sum/20;
	shillings_sum = shillings_sum%20;
}


std::string sum_new_pounds ()
{
	
	
}


int main (int argc, char const *argv[])
{
	
	std::cout << std::endl << "Project 1 from Assignment 1" << std::endl << "Pound Conversion" << std::endl << std::endl << "This program will sum two old-pound values and display the result in old-pounds and new-pounds." << std::endl << std::endl;
	
	old_pounds value_one = ask_for_input ();
	old_pounds value_two = ask_for_input ();
	
	std::cout << "Old-pound total: " << sum_old_pounds (value_one, value_two) << std::endl;
	std::cout << "New-pound total: " << sum_new_pounds () << std::endl;
	
	return 0;
}