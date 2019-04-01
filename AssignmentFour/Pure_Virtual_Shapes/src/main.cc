#include <iostream>
#include <string>


class Shape
{

public:
	
	virtual void display () = 0;
	virtual void GetDimensions () = 0;
	virtual void Area () = 0;
	virtual void Perimeter () = 0;
	virtual void Volume () = 0;
	
private:

};


class Rectangle : public Shape
{

	void display ();
    void GetDimensions ();
    void Area ();
    void Perimeter ();
    void Volume ();
};

class Circle : public Shape
{

	void display ();
    void GetDimensions ();
    void Area ();
    void Perimeter ();
    void Volume ();
};

class Triangle : public Shape
{

	void display ();
    void GetDimensions ();
    void Area ();
    void Perimeter ();
    void Volume ();
};

class Box : public Shape
{

	void display ();
    void GetDimensions ();
    void Area ();
    void Perimeter ();
    void Volume ();
};

class Can : public Shape
{

	void display ();
    void GetDimensions ();
    void Area ();
    void Perimeter ();
    void Volume ();
};

class Cone : public Shape
{
	
	void display ();
    void GetDimensions ();
    void Area ();
    void Perimeter ();
    void Volume ();
};

class Ball : public Shape
{

	void display ();
    void GetDimensions ();
    void Area ();
    void Perimeter ();
    void Volume ();
};


const char get_input ()
{

	std::string input;
	
	do
	{
		
		std::getline (std::cin, input);
	} while (tolower (input[0]) != 'y' && tolower (input[0]) != 'n');
	
	return tolower (input[0]);
}


bool another_shape ()
{
	
	std::cout << std::endl << "Examine another file? (y/n): ";
	return (get_input () == 'y' ? true : false);
}


int main (int argc, char const *argv[])
{
	
	
	std::cout << "Project 3 from Assignment 4" << std::endl << "Pure Virtual Shapes" << std::endl << "This program uses pure virtual functions to model primitive shapes." << std::endl << std::endl;
	
	Shape *shapes;
	
	do
	{
		
		
	} while (another_shape ());
	
	
	return 0;
}