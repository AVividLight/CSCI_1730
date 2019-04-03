#include <iostream>
#include <string>


class Shape
{

public:
	//Shape (std::size_t dim) {set_size (dim);}
	Shape (std::size_t dim);
	
	virtual void display () = 0;
	virtual void GetDimensions () = 0;
	virtual void Area () = 0;
	virtual void Perimeter () = 0;
	virtual void Volume () = 0;
	
	void set_size (int dim) {size = dim;}
	const std::size_t get_size () const {return size;}
	
private:
	float *dimension;
	std::size_t size;
};


Shape::Shape (std::size_t dim)
{
	
	dimension = new float[dim];
	size = dim;
}



class Rectangle : public Shape
{

public:
	Rectangle ();
	
	void display ();
    void GetDimensions ();
    void Area ();
    void Perimeter ();
    void Volume ();
	
private:
};


Rectangle::Rectangle () : Shape (2)
{
	
	
}

/*class Circle : public Shape
{

public:
	
	void display ();
    void GetDimensions ();
    void Area ();
    void Perimeter ();
    void Volume ();
	
private:
};

class Triangle : public Shape
{
	
public:

	void display ();
    void GetDimensions ();
    void Area ();
    void Perimeter ();
    void Volume ();
	
private:
};

class Box : public Shape
{
	
public:

	void display ();
    void GetDimensions ();
    void Area ();
    void Perimeter ();
    void Volume ();
	
private:
};

class Can : public Shape
{
	
public:

	void display ();
    void GetDimensions ();
    void Area ();
    void Perimeter ();
    void Volume ();
	
private:
};

class Cone : public Shape
{
	
public:
	
	void display ();
    void GetDimensions ();
    void Area ();
    void Perimeter ();
    void Volume ();
	
private:
};

class Ball : public Shape
{
	
public:

	void display ();
    void GetDimensions ();
    void Area ();
    void Perimeter ();
    void Volume ();
	
private:
};
*/


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
	
	//Shapes *shapes;
	//Shape shape;
	
	Rectangle rect;
	
	do
	{
		
		
	} while (another_shape ());
	
	
	return 0;
}