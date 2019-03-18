/*
Bryant Yaurincela
Logan Kreun
Michael Bethke
CSCI 1730-01
Group 7
*/


#include <iostream>
#include <string>


static std::string invalid_reason = "";


const bool prompt_continue ()
{
	
	std::cout << "Enter another address (y/n): ";
	
	char input = '\n';
	std::cin.get (input);
	std::cin.clear ();
	std::cin.ignore (1000, '\n');
	
	tolower (input);
	
	if (std::cin.fail () || (input != 'y' && input != 'n'))
	{
			
		std::cout << "Invalid input." << std::endl;
		return prompt_continue ();	
	}
	
	return (input == 'y' ? true : false);
}


bool check_for_white_space (const std::string::const_iterator &i)
{
	
	if (isspace (*i))
	{
		
		invalid_reason.append (" - contains white space");
		return false;
	}
	
	return true;
}


bool check_at_sign (const std::string::const_iterator &i, const std::string &input, int &at_index)
{
	
	if (*i == '@')
	{
		
		if (at_index != -1)
		{

			invalid_reason.append (" - contains multiple @ symbols");
			return false;
		} else {
			
			at_index = std::distance (input.begin (), i);
			
			if (i == input.begin ())
			{
				
				invalid_reason.append (" - is missing local mailbox identifier");
				return false;
			} else if (i == input.end () - 1)
			{
				
				invalid_reason.append (" - is missing domain");
				return false;
			}
		}
	}
	
	return true;
}


bool check_periods (const std::string::const_iterator &i, const std::string &input, bool &period_found)
{
	
	if (*i == '.')
	{
		
		if (i == input.begin ())
		{
			
			invalid_reason.append (" - cannot begin with a period");
			return false;
		}
		
		if (i == input.end () - 1)
		{
			
			invalid_reason.append (" - cannot end with a period");
			return false;
		}
		
		if (period_found == true)
		{
			
			invalid_reason.append (" - cannot contain two periods next to eachother");
			return false;
		}
		
		period_found = true;
	} else {
		
		period_found = false;
	}
	
	return true;
}


const bool validate_address (std::string &input)
{
	
	invalid_reason = "";
	bool valid = true;
	
	int at_index = -1;
	bool period_found = false;

	for (std::string::const_iterator i = input.begin (); i < input.end (); i += 1)
	{
	
		if (!check_for_white_space (i)) valid = false;
		if (!check_at_sign (i, input, at_index)) valid = false;
		if (!check_periods (i, input, period_found)) valid = false;
	}
		
	if (at_index == -1)
	{
		
		valid = false;
		invalid_reason.append (" - is missing complete local mailbox identifier");
	} else {
		
		if (input [at_index - 1] == '.')
		{
			
			valid = false;
			invalid_reason.append (" - local mailbox identifier cannot end with a period");
		} else if (input[at_index + 1] == '.')
		{
			
			valid = false;
			invalid_reason.append (" - domain cannot start with a period");
		}
	}
	
	return valid;
}


int get_address (std::string &input)
{
	
	input.clear ();
	
	std::cout << "Enter an email address to be validated: ";
	if (getline (std::cin, input))
	{
		
		if (input.empty ())
			get_address (input);
	} else {
		
		std::cout << "ERROR: Failed to open stream!" << std::endl;
		return 1;
	}
	
	return 0;
}


int main (int argc, char const *argv[])
{
	
	std::cout << std::endl << "Project 5 from Assignment 3" << std::endl << "Email Validation" << std::endl << std::endl << "This program will validate entered email addresses." << std::endl;
	
	std::string address;
	
	do
	{
		
		if (get_address (address)) return 1;
		
		std::cout << "You entered: '" << address << "'." << std::endl;
		
		if (validate_address (address) == true)
			std::cout << "Valid - " << address << " is a valid email address." << std::endl;
		else
			std::cout << "Invalid - " << address << " is invalid because:" << invalid_reason << '.' << std::endl;
		
	} while (prompt_continue ());
	
	return 0;
}
