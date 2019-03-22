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
#include <cctype>


#ifdef _WIN32
#include <direct.h>
#define getcws _getcwd
#define PATH_SEPERATOR '\\'
#elif defined (__unix__) || (defined (__APPLE__) && defined (__MACH__))
#include <unistd.h>
#define PATH_SEPERATOR '/'
#endif


const static std::size_t DYNAMIC_ARRAY_BLOCK_SIZE = 32;


class DynamicArray
{

public:
	DynamicArray ();
	~DynamicArray ();
	
	void push_back (const std::string value);
	const std::size_t get_data_size () const {return size;};
	
	void sort ();
	
	std::string &operator[](const std::size_t index);
	
private:
	std::string *data;
	std::size_t size;
	unsigned short int next_open_position;
	
	void expand ();
	
	void counting_sort ();

};


DynamicArray::DynamicArray ()
{
	
	size = DYNAMIC_ARRAY_BLOCK_SIZE;
	data = new std::string [size];
	next_open_position = 0;
}


DynamicArray::~DynamicArray ()
{

	delete [] data;
}


std::string &DynamicArray::operator[](const std::size_t index)
{
	
	if (index < size)
		return data[index];
	else
		throw;
}


void DynamicArray::push_back (const std::string value)
{
	
	if (next_open_position >= (size - 1))
	{
		
		expand ();
	}
	
	data[next_open_position] = value;
	next_open_position += 1;
}


void DynamicArray::expand ()
{
	
	std::string *new_data;
	new_data = new std::string [size + DYNAMIC_ARRAY_BLOCK_SIZE];
	
	for (int i = 0; i < size; i += 1)
	{
		
		new_data[i] = data[i];
	}
	
	size += DYNAMIC_ARRAY_BLOCK_SIZE;
	delete [] data;
	
	data = new_data;
}


void DynamicArray::sort()
{
	
	shell_sort ();
}


void DynamicArray::counting_sort ()
{
	
	//https://www.techiedelight.com/counting-sort-algorithm-implementation/
}


bool is_filename (const std::string file_path)
{
	
	for (std::string::const_iterator i = file_path.begin (); i < file_path.end (); i += 1)
	{
		
		if (*i == '/' || *i == '\\')
			return false;
	}
	
	return true;
}


void clean_path (std::string &path)
{
	
	if (path[0] == '\"')
	{
		
		path.erase (0, 1);
		path.erase (path.size () - 1 );
	}
}


const char get_input ()
{

	std::string input;
	
	do
	{
		
		std::cout << std::endl << "Examine another file? (y/n): ";
		std::getline (std::cin, input);
	} while (tolower (input[0]) != 'y' && tolower (input[0]) != 'n');
	
	return tolower (input[0]);
}


const bool repeat ()
{
	
	return (get_input () == 'y' ? true : false);
}


int populate_array (std::ifstream &file, DynamicArray &array)
{
	
	std::string temp_word;
	
	char c;
	while (file.get (c))
	{
		
		if (isspace (c))
		{
			
			if (temp_word.length () > 0)
			{
			
				//std::cout << temp_word << std::endl;
				array.push_back (temp_word);
				temp_word.clear ();
			}
		} else {
			
			temp_word.push_back (c);
		}
	}
	
	if (temp_word.length () > 0)
	{
	
		//std::cout << temp_word << std::endl;
		array.push_back (temp_word);
		//temp_word.clear ();
	}
	
	if (!file.fail ())
		return 0;
	else
		return 1;
}


int main (int argc, char const *argv[])
{
	
	std::cout << std::endl << "Project 1 from Assignment 4" << std::endl << "Text File Statistics" << std::endl << std::endl << "This program will receive a path to a text file and provide statistics about the words." << std::endl;
	
	std::string file_path;
	
	unsigned short int shortest_word_length;
	unsigned short int longest_word_length;
	float average_word_length;
	
	do
	{
	
		std::cout << "Enter a filename or absolute path: ";
		std::getline (std::cin, file_path);
		clean_path (file_path);
		/*if (is_filename (file_path))
		{
			
			std::string file_name = file_path;
			
			char buffer [1024];
			char *loc = getcwd (buffer, sizeof (buffer));
			file_path = loc;
			file_path.push_back (PATH_SEPERATOR);
			file_path.append (file_name);
			
			std::cout << "appended working dir to path, now: " << file_path << std::endl;
		}*/
		
		std::ifstream file (file_path.c_str());
		
		if (!file.good ())
		{
			
			std::cout << "Error opening file at " << file_path <<". Double check file path." << std::endl;
			return 1;
		}
		
		DynamicArray words;
		if (!populate_array (file, words))
		{
			
			std::cout << "Error reading file." << std::endl;
			return 1;
		}
		
		file.close ();
		
		shortest_word_length = 0;
		longest_word_length = 0;
		average_word_length = 0.0;
		
		std::cout << "words array size: " << words.get_data_size () << std::endl;

	} while (repeat ());
	
	return 0;
}
