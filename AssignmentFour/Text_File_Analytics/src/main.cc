/*
Bryant Yaurincela
Logan Kreun
Michael Bethke
CSCI 1730-01
Group 7
*/


#include <string>
#include <iostream>
#include <fstream>


#ifdef _WIN32
const static char PATH_SEPERATOR = '\\';
#elif defined (__unix__) || (defined (__APPLE__) && defined (__MACH__))
const static char PATH_SEPERATOR = '/';
#endif


bool is_filename (const std::string file_path)
{
	
	for (std::string::const_iterator i = file_path.begin (); i < file_path.end (); i += 1)
	{
		
		if (*i == '/' || *i == '\\')
			return false;
	}
	
	return true;
}


int main (int argc, char const *argv[])
{
	
	std::string file_path;
	
	std::cout << "Enter a filename or path: ";
	std::getline (std::cin, file_path);
	
	std::ifstream file (file_path);
	
	if (!file.good ())
	{
		
		std::cout << "Error opening file. Double check file path." << std::endl;
		return 1;
	}
	
	
	
	return 0;
}