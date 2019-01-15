#include <iostream>
#include <string>
#include <regex>


//20 shillings to a pound, and 12 pence to a shilling

class old_pounds
{
public:
	std::string To_String ();
	
	void set_pounds (int x);
	void set_shillings (int x);
	void set_pence (int x);

private:
	int pounds;
	int shillings;
	int pence;
};


std::string old_pounds::To_String ()
{
	
	return "£" + std::to_string (pounds) + '.' + std::to_string (shillings) + '.' + std::to_string (pence);
}


bool validate_input (std::string input)
{
	
	std::smatch result;
	if (std::regex_match (input, result, std::regex ("\\d+.\\d+.\\d+")))
	{
		std::cout << "Result: " << result[0] << std::endl;
		return true;
	} else {
		std::cout << "Match failed." << std::endl;
		return false;
	}
}


old_pounds ask_for_input ()
{
	
	old_pounds value;
	
	std::string input_value;
	std::cout << "Enter a value in old-pounds (matching pattern #.#.#): ";
	std::cin >> input_value;
	
	if (validate_input (input_value) != true)
	{
	
		value = ask_for_input ();
	}
	
	return value;
}


int main (int argc, char const *argv[])
{
	
	std::cout << std::endl << "Project 1 from Assignment 1" << std::endl << "Pound Conversion" << std::endl << std::endl << "This program will sum two old-pound values and display the result in old-pounds and new-pounds." << std::endl << std::endl;
	
	old_pounds value_one = ask_for_input ();
	old_pounds value_two = ask_for_input ();
	
	return 0;
}