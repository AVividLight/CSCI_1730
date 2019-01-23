#include <iostream>
#include <string>


const int SHILLINGS_PER_POUND = 20;
const int PENCE_PER_SHILLING = 12;
const int PENCE_CONVERSION_RATE = 240;


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

	return old_pounds_value;
}


std::string sum_old_pounds (old_pounds value_one, old_pounds value_two)
{
	
	old_pounds sum;
	
	sum.pence = value_one.pence + value_two.pence;
	sum.shillings = value_one.shillings + value_two.shillings;
	sum.pounds = value_one.pounds + value_two.pounds;
	
	sum.shillings += sum.pence / PENCE_PER_SHILLING;
	sum.pence = sum.pence % PENCE_PER_SHILLING;
	
	sum.pounds += sum.shillings / SHILLINGS_PER_POUND;
	sum.shillings = sum.shillings % SHILLINGS_PER_POUND;
	
	return sum.to_string();
}


std::string sum_new_pounds (old_pounds value_one, old_pounds value_two)
{
	
	new_pounds sum;
	
	int pence_sum = value_one.pence + value_two.pence;
	int shilling_sum = (value_one.shillings + value_two.shillings) * PENCE_PER_SHILLING;
	int pounds_sum = ((value_one.pounds + value_two.pounds) * SHILLINGS_PER_POUND) * PENCE_PER_SHILLING;

	int sum_in_pence = (pence_sum + shilling_sum + pounds_sum);
	sum.pounds = (sum_in_pence / PENCE_CONVERSION_RATE);
	sum.pence = (sum_in_pence % PENCE_CONVERSION_RATE)/2.4;
	
	return sum.to_string ();
}


int main (int argc, char const *argv[])
{
	
	std::cout << std::endl << "Project 1 from Assignment 1" << std::endl << "Pound Conversion" << std::endl << std::endl << "This program will sum two old-pound values and display the result in old-pounds and new-pounds." << std::endl << std::endl;
	
	old_pounds value_one = ask_for_input ();
	old_pounds value_two = ask_for_input ();
	
	std::cout << "Old-pound total: " << sum_old_pounds (value_one, value_two) << std::endl;
	std::cout << "New-pound total: " << sum_new_pounds (value_one, value_two) << std::endl;
	
	return 0;
}