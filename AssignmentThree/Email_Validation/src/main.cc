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
		
	if (input == 'y')
		return true;
	else
		return false;
}


bool check_for_white_space (const std::string::const_iterator &i)
{
	
	if (isspace (*i))
	{
		
		invalid_reason = "contains white space";
		return false;
	}
	
	return true;
}


bool check_at_sign (const std::string::const_iterator &i, const std::string &input, bool &at_found)
{
	
	if (*i == '@')
	{
		
		if (at_found)
		{
			
			invalid_reason = "contains multiple @ symbols";
			return false;
		} else {
			
			at_found = true;
			
			if (i == input.begin ())
			{
				
				invalid_reason = "is missing local mailbox identifier";
				return false;
			} else if (i == input.end () - 1)
			{
				
				invalid_reason = "is missing domain";
				return false;
			}
		}
	}
	
	return true;
}


//Every occurrence of the dot character (.)must have a non-@, non-dot character on both sides. For example, bar@cs. , .ed@comcast.net, and bar@.depaul, joe..smith@bob.com are not valid e-mail addresses.

bool check_periods (const std::string::const_iterator &i, const std::string &input, bool &period_found)
{
	
	if (*i == '.')
	{
		
		if (i == input.begin ())
		{
			
			invalid_reason = "cannot begin with a period";
			return false;
		}
		
		if (i == input.end () - 1)
		{
			
			invalid_reason = "cannot end with a period";
			return false;
		}
		
		if (period_found == true)
		{
			
			invalid_reason = "cannot contain two periods next to eachother";
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
	
	bool at_found = false;
	bool period_found = false;
	
	for (std::string::const_iterator i = input.begin (); i < input.end (); i += 1)
	{
	
		if (!check_for_white_space (i)) break;
		if (!check_at_sign (i, input, at_found)) break;
		if (!check_periods (i, input, period_found)) break;
	}
	
	if (at_found == false)
	{
		
		valid = false;
		invalid_reason = "is missing local mailbox identifier";
	}
	
	return valid;
}


void get_address (std::string &input)
{
	
	input.clear ();
	
	std::cout << "Enter an email address to be validated: ";
	if (getline (std::cin, input))
	{
		
		if (input.empty ())
		{
			
			get_address (input);
		}
	} else {
		
		std::cout << "ERROR: Failed to open stream!" << std::endl;
	}
}


int main (int argc, char const *argv[])
{
	
	std::cout << std::endl << "Project 5 from Assignment 3" << std::endl << "Email Validation" << std::endl << std::endl << "This program will validate entered email addresses." << std::endl;
	
	std::string address;
	
	do
	{
		
		get_address (address);
		std::cout << "You entered: '" << address << "'." << std::endl;
		
		if (validate_address (address) == true)
		{
			
			std::cout << "Valid - " << address << " is a valid email address." << std::endl;
		} else {
			
			std::cout << "Invalid - " << address << " is invalid because it " << invalid_reason << '.' << std::endl;
		}
		
	} while (prompt_continue ());
	
	return 0;
}