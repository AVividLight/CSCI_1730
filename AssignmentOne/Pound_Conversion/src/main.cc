#include <iostream>


int main (int argc, char const *argv[])
{
	
	std::cout << std::endl << "Project 1 from Assignment 1" << std::endl << "Pound Conversion" << std::endl << std::endl << "This program will sum two old-pound values and display the result in old-pounds and new-pounds." << std::endl << std::endl;


	char period;

	int user_pounds_one;
	int user_shillings_one;
	int user_pence_one;
	std::cout << "Enter a value in old-pounds (matching pattern #.#.#): ";
	std::cin >> user_pounds_one >> period >> user_shillings_one >> period >> user_pence_one;
	
	int user_pounds_two;
	int user_shillings_two;
	int user_pence_two;
	std::cout << "Enter a second value in old-pounds (matching pattern #.#.#): ";
	std::cin >> user_pounds_two >> period >> user_shillings_two >> period >> user_pence_two;
	
	
	int sum_old_pence = user_pence_one + user_pence_two;
	int sum_old_shillings = user_shillings_one + user_shillings_two;
	int sum_old_pounds = user_pounds_one + user_pounds_two;
	
	sum_old_shillings += sum_old_pence / 12;
	sum_old_pence = sum_old_pence % 12;
	
	sum_old_pounds += sum_old_shillings / 20;
	sum_old_shillings = sum_old_shillings % 20;
	
	std::cout << "Sum in old-pounds: " << sum_old_pounds << '.' << sum_old_shillings << '.' << sum_old_pence << std::endl;
	
	
	int pence_sum = user_pence_one + user_pence_two;
	int shilling_sum = (user_shillings_one + user_shillings_two) * 12;
	int pounds_sum = ((user_pounds_one + user_pounds_two) * 20) * 12;

	int sum_in_pence = (pence_sum + shilling_sum + pounds_sum);
	int sum_new_pounds = (sum_in_pence / 240);
	int sum_new_pence = ((sum_in_pence % 240)*10)/24;
	
	std::cout << "Sum in new-pounds: " << sum_new_pounds << '.' << sum_new_pence << std::endl;
	
	
	return 0;
}