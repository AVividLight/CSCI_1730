#include <iostream>
#include <string>
#include <cmath>


const double pi = 3.14159265358979323846;


class Shape {
public:
	Shape (std::size_t dim);
	
	virtual void display () = 0;
	virtual void GetDimensions () = 0;
	virtual void Area () = 0;
	virtual void Perimeter () = 0;
	virtual void Volume () = 0;
	
	void set_size (int dim) {size = dim;}
	const std::size_t get_size () const {return size;}
	
	float get_dimension_at_index (const unsigned short int pos);
	
private:
	float *dimension;
	std::size_t size;
};


Shape::Shape (std::size_t dim) {
	dimension = new float[dim];
	size = dim;
}


float Shape::get_dimension_at_index (const unsigned short int pos) {
	if (pos > size) {
		throw;
		return 0.0;
	}
	
	return dimension[pos];
}



class Rectangle : public Shape {
public:
	Rectangle () : Shape (SIDES) {}
	
	void display () {std::cout << "Rectangle of length " << get_dimension_at_index (0) << " and width " << get_dimension_at_index (1) << std::endl;}
    void GetDimensions () {}
    void Area () {std::cout << "Area: " << (pi * get_dimension_at_index (0) * get_dimension_at_index (0)) << std::endl;}
    void Perimeter () {std::cout << "Perimeter: " << (2 * pi * get_dimension_at_index (0)) << std::endl;}
    void Volume () {} //Do nothing for 2D shape
	
private:
	static const std::size_t SIDES = 2;
};


class Circle : public Shape {
public:
	Circle () : Shape (SIDES) {}
	
	void display () {std::cout << "Circle of radius " << get_dimension_at_index (0) << std::endl;}
    void GetDimensions () {}
    void Area () {std::cout << "Area: " << (get_dimension_at_index (0) * get_dimension_at_index (1)) << std::endl;}
    void Perimeter () {std::cout << "Perimeter: " << (2 * get_dimension_at_index (0) + 2 * get_dimension_at_index (1)) << std::endl;}
    void Volume () {} //Do nothing for 2D shape
	
private:
	static const std::size_t SIDES = 1;
};


class Triangle : public Shape {
public:
	Triangle () : Shape (SIDES) {}
	
	void display () {std::cout << "Triangle of size " << get_dimension_at_index (0) << ", " << get_dimension_at_index (1) << ", and " << get_dimension_at_index (2) << std::endl;}
    void GetDimensions () {}
    void Area ();
    void Perimeter () {std::cout << "Perimeter: " << (get_dimension_at_index (0) + get_dimension_at_index (1) + get_dimension_at_index (2)) << std::endl;}
    void Volume () {} //Do nothing for 2D shape
	
private:
	static const std::size_t SIDES = 3;
};


void Triangle::Area () {
	const float half_perimeter = (get_dimension_at_index (0) + get_dimension_at_index (1) + get_dimension_at_index (2))/2;
	std::cout << "Area: " << sqrt (half_perimeter * (half_perimeter - get_dimension_at_index (0)) * (half_perimeter - get_dimension_at_index (1)) * (half_perimeter - get_dimension_at_index (2))) << std::endl;
}


class Box : public Shape {
public:
	Box () : Shape (SIDES) {}
	
	void display () {std::cout << "Box of size " << get_dimension_at_index (0) << ", " << get_dimension_at_index (1) << ", and " << get_dimension_at_index (2) << std::endl;}
    void GetDimensions () {}
    void Area () {std::cout << "Area: " << 2 * (get_dimension_at_index (0) * get_dimension_at_index (1) + get_dimension_at_index (0) * get_dimension_at_index (2) + get_dimension_at_index (1) * get_dimension_at_index (2)) << std::endl;}
    void Perimeter (); //Do nothing for 3D shape
    void Volume () {std::cout << "Volume: " << get_dimension_at_index (0) * get_dimension_at_index (1) * get_dimension_at_index (2) << std::endl;}
	
private:
	static const std::size_t SIDES = 3;
};


class Can : public Shape {
public:
	Can () : Shape (SIDES) {}
	
	void display () {std::cout << "Can of radius " << get_dimension_at_index (0) << " and height" << get_dimension_at_index (1) << std::endl;}
    void GetDimensions () {}
    void Area () {std::cout << "Area: " << 2 * pi * (get_dimension_at_index (0) * get_dimension_at_index (0)) + 2 * pi * get_dimension_at_index (0) * get_dimension_at_index (1) << std::endl;}
    void Perimeter (); //Do nothing for 3D shape
    void Volume () {std::cout << "Volume: " << pi * get_dimension_at_index (0) * get_dimension_at_index (0) * get_dimension_at_index (1) << std::endl;}
	
private:
	static const std::size_t SIDES = 2;
};


class Cone : public Shape {
public:
	Cone () : Shape (SIDES) {}
	
	void display () {std::cout << "Cone of radius " << get_dimension_at_index (0) << " and height" << get_dimension_at_index (1) << std::endl;}
    void GetDimensions () {}
    void Area () {std::cout << "Area: " << pi * (get_dimension_at_index (0) * get_dimension_at_index (0)) + pi * get_dimension_at_index (0) * sqrt (get_dimension_at_index (1) * get_dimension_at_index (1) + get_dimension_at_index (0) * get_dimension_at_index (0)) << std::endl;}
    void Perimeter (); //Do nothing for 3D shape
    void Volume () {std::cout << "Volume: " << 1.0/3.0 * pi * get_dimension_at_index (0) * get_dimension_at_index (0) * get_dimension_at_index (1) << std::endl;}
	
private:
	static const std::size_t SIDES = 2;
};


class Ball : public Shape {
public:
	Ball () : Shape (SIDES) {}
	
	void display () {std::cout << "Ball of radius " << get_dimension_at_index (0) << std::endl;}
    void GetDimensions () {}
    void Area () {std::cout << "Area: " << 4 * pi * get_dimension_at_index (0) * get_dimension_at_index (0) << std::endl;}
    void Perimeter (); //Do nothing for 3D shape
    void Volume () {std::cout << "Volume: " << 4.0/3.0 * pi * get_dimension_at_index (0) * get_dimension_at_index (0) * get_dimension_at_index (0) << std::endl;}
	
private:
	static const std::size_t SIDES = 1;
};


const char get_bool_input () {
	std::string input;
	do {	
		std::getline (std::cin, input);
	} while (tolower (input[0]) != 'y' && tolower (input[0]) != 'n');
	return tolower (input[0]);
}


bool another_shape () {
	std::cout << std::endl << "Enter another shape? (y/n) ";
	return (get_bool_input () == 'y' ? true : false);
}


int main (int argc, char const *argv[]) {
	std::cout << "Project 3 from Assignment 4" << std::endl << "Pure Virtual Shapes" << std::endl << "This program uses pure virtual functions to model primitive shapes." << std::endl << std::endl;
	
	Shape *shapes[20];
	
	int menu_choice = 0;
	int index = 0;
	for (index = 0; index < 20; index += 1) {
		std::cout << "Enter the number of the shape type:" << std::endl << "\t1 - Rectangle" << std::endl << "\t2 - Circle" << std::endl << "\t3 - Triangle" << std::endl << "\t4 - Box" << std::endl << "\t5 - Can" << std::endl << "\t6 - Cone" << std::endl << "\t7 - Ball" << std::endl;
		
		/*//###	###	###
		
			GET INPUT
			=========
		
		*///###	###	###
		
		switch (menu_choice) {
			case 1:
			break;
			
			case 2:
			break;
			
			case 3:
			break;
			
			case 4:
			break;
			
			case 5:
			break;
			
			case 6:
			break;
			
			case 7:
			break;
			
			default:
			break;
		}
		
		if (!another_shape ())
			break;
	}
	
	for (int i = 0; i < index; i += 1) {
		shapes[i]->display ();
	}
	
	return 0;
}