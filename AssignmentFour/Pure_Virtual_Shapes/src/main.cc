#include <iostream>
#include <string>
#include <cmath>


const double pi = 3.14159265358979323846;


class Shape {
public:
	Shape (std::size_t dim);
	virtual ~Shape () {}
	
	virtual void display () = 0;
	virtual void GetDimensions () = 0;
	virtual void Area () = 0;
	virtual void Perimeter () = 0;
	virtual void Volume () = 0;
	
	void set_size (int dim) {size = dim;}
	const std::size_t get_size () const {return size;}
	
	void set_dimension_at_index (const unsigned short int pos, const float dim);
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


void Shape::set_dimension_at_index (const unsigned short int pos, const float dim) {
	if (pos > size)
		throw;
	
	dimension[pos] = dim;
}



class Rectangle : public Shape {
public:
	Rectangle (float x, float y) : Shape (SIDES) {set_dimension_at_index (0, x); set_dimension_at_index (1, y);}
	
	void display () {std::cout << "Rectangle, "; GetDimensions (); Area (); Perimeter (); Volume ();}
    void GetDimensions () {std::cout << "length " << get_dimension_at_index (0) << " and width " << get_dimension_at_index (1) << std::endl;}
    void Area () {std::cout << "Area: " << (pi * get_dimension_at_index (0) * get_dimension_at_index (0)) << std::endl;}
    void Perimeter () {std::cout << "Perimeter: " << (2 * pi * get_dimension_at_index (0)) << std::endl;}
    void Volume () {} //Do nothing for 2D shape
	
private:
	static const std::size_t SIDES = 2;
};


class Circle : public Shape {
public:
	Circle (float r) : Shape (SIDES) {set_dimension_at_index (0, r);}
	
	void display () {std::cout << "Circle, "; GetDimensions (); Area (); Perimeter (); Volume ();}
    void GetDimensions () {std::cout << "radius " << get_dimension_at_index (0) << std::endl;}
    void Area () {std::cout << "Area: " << (pi * get_dimension_at_index (0) * get_dimension_at_index (0)) << std::endl;}
    void Perimeter () {std::cout << "Perimeter: " << (2 * get_dimension_at_index (0) + 2 * get_dimension_at_index (1)) << std::endl;}
    void Volume () {} //Do nothing for 2D shape
	
private:
	static const std::size_t SIDES = 1;
};


class Triangle : public Shape {
public:
	Triangle (float x, float y, float z) : Shape (SIDES) {set_dimension_at_index (0, x); set_dimension_at_index (1, y); set_dimension_at_index (2, z);}
	
	void display () {std::cout << "Triangle, "; GetDimensions (); Area (); Perimeter (); Volume ();}
    void GetDimensions () {std::cout << "of size " << get_dimension_at_index (0) << ", " << get_dimension_at_index (1) << ", and " << get_dimension_at_index (2) << std::endl;}
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
	Box (float x, float y, float z) : Shape (SIDES) {set_dimension_at_index (0, x); set_dimension_at_index (1, y); set_dimension_at_index (2, z);}
	
	void display () {std::cout << "Box, "; GetDimensions (); Area (); Perimeter (); Volume ();}
    void GetDimensions () {std::cout << "size " << get_dimension_at_index (0) << ", " << get_dimension_at_index (1) << ", and " << get_dimension_at_index (2) << std::endl;}
    void Area () {std::cout << "Area: " << 2 * (get_dimension_at_index (0) * get_dimension_at_index (1) + get_dimension_at_index (0) * get_dimension_at_index (2) + get_dimension_at_index (1) * get_dimension_at_index (2)) << std::endl;}
    void Perimeter () {} //Do nothing for 3D shape
    void Volume () {std::cout << "Volume: " << get_dimension_at_index (0) * get_dimension_at_index (1) * get_dimension_at_index (2) << std::endl;}
	
private:
	static const std::size_t SIDES = 3;
};


class Can : public Shape {
public:
	Can (float r, float h) : Shape (SIDES) {set_dimension_at_index (0, r); set_dimension_at_index (1, h);}
	
	void display () {std::cout << "Can, "; GetDimensions (); Area (); Perimeter (); Volume ();}
    void GetDimensions () {std::cout << "radius " << get_dimension_at_index (0) << " and height " << get_dimension_at_index (1) << std::endl;}
    void Area () {std::cout << "Area: " << 2 * pi * (get_dimension_at_index (0) * get_dimension_at_index (0)) + 2 * pi * get_dimension_at_index (0) * get_dimension_at_index (1) << std::endl;}
    void Perimeter () {} //Do nothing for 3D shape
    void Volume () {std::cout << "Volume: " << pi * get_dimension_at_index (0) * get_dimension_at_index (0) * get_dimension_at_index (1) << std::endl;}
	
private:
	static const std::size_t SIDES = 2;
};


class Cone : public Shape {
public:
	Cone (float r, float h) : Shape (SIDES) {set_dimension_at_index (0, r); set_dimension_at_index (1, h);}
	
	void display () {std::cout << "Cone, "; GetDimensions (); Area (); Perimeter (); Volume ();}
    void GetDimensions () {std::cout << "radius " << get_dimension_at_index (0) << " and height " << get_dimension_at_index (1) << std::endl;}
    void Area () {std::cout << "Area: " << pi * (get_dimension_at_index (0) * get_dimension_at_index (0)) + pi * get_dimension_at_index (0) * sqrt (get_dimension_at_index (1) * get_dimension_at_index (1) + get_dimension_at_index (0) * get_dimension_at_index (0)) << std::endl;}
    void Perimeter () {} //Do nothing for 3D shape
    void Volume () {std::cout << "Volume: " << 1.0/3.0 * pi * get_dimension_at_index (0) * get_dimension_at_index (0) * get_dimension_at_index (1) << std::endl;}
	
private:
	static const std::size_t SIDES = 2;
};


class Ball : public Shape {
public:
	Ball (float r) : Shape (SIDES) {set_dimension_at_index (0, r);}
	
	void display () {std::cout << "Ball, "; GetDimensions (); Area (); Perimeter (); Volume ();}
    void GetDimensions () {std::cout << " radius " << get_dimension_at_index (0) << std::endl;}
    void Area () {std::cout << "Area: " << 4 * pi * get_dimension_at_index (0) * get_dimension_at_index (0) << std::endl;}
    void Perimeter () {} //Do nothing for 3D shape
    void Volume () {std::cout << "Volume: " << 4.0/3.0 * pi * get_dimension_at_index (0) * get_dimension_at_index (0) * get_dimension_at_index (0) << std::endl;}
	
private:
	static const std::size_t SIDES = 1;
};


const float get_number_input (float min = 0.0, float max = 1000000.0) {
	float input;
	while (true) {
		std::cin >> input;
		
		if (input < min || input > max) {
			std::cout << "Please enter a number between " << min << " and " << max << '.' << std::endl;
			
			std::cin.clear ();
			std::cin.ignore ();
		} else
			break;
	}
	
	std::cin.clear ();
	std::cin.ignore ();
	
	return input;
}


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
	
	Shape **shapes = new Shape *[20];
	
	int menu_choice = 0;
	int index = 0;
	for (index = 0; index < 20; index += 1) {
		std::cout << "Enter the number of the shape type:" << std::endl << "\t1 - Rectangle" << std::endl << "\t2 - Circle" << std::endl << "\t3 - Triangle" << std::endl << "\t4 - Box" << std::endl << "\t5 - Can" << std::endl << "\t6 - Cone" << std::endl << "\t7 - Ball" << std::endl;
		
		switch ((int) get_number_input (1, 7)) {
			case 1: {
				std::cout << "Enter side length: ";
				const float l = get_number_input ();
				
				std::cout << "Enter side width: ";
				const float w = get_number_input ();
				shapes[index] = new Rectangle (l, w);
			} break;
			
			case 2: {
				std::cout << "Enter radius length: ";
				const float r = get_number_input ();
				shapes[index] = new Circle (r);
			} break;
			
			case 3: {
				std::cout << "Enter side x: ";
				const float x = get_number_input ();
				
				std::cout << "Enter side y: ";
				const float y = get_number_input ();
				
				std::cout << "Enter side z: ";
				const float z = get_number_input ();
				shapes[index] = new Triangle (x, y, z);
			} break;
			
			case 4: {
				std::cout << "Enter length: ";
				const float x = get_number_input ();
				
				std::cout << "Enter width: ";
				const float y = get_number_input ();
				
				std::cout << "Enter height: ";
				const float z = get_number_input ();
				shapes[index] = new Box (x, y, z);
			} break;
			
			case 5: {
				std::cout << "Enter radius: ";
				const float r = get_number_input ();
				
				std::cout << "Enter height: ";
				const float h = get_number_input ();
				shapes[index] = new Can (r, h);
			} break;
			
			case 6: {
				std::cout << "Enter radius: ";
				const float r = get_number_input ();
				
				std::cout << "Enter height: ";
				const float h = get_number_input ();
				shapes[index] = new Cone (r, h);
			} break;
			
			case 7: {
				std::cout << "Enter radius length: ";
				const float r = get_number_input ();
				shapes[index] = new Ball (r);
			} break;
			
			default:
			std::cout << "default" << std::endl;
			break;
		}
		
		if (!another_shape ())
			break;
	}
	
	for (int i = 0; i < index + 1; i += 1) {
		std::cout << std::endl;
		shapes[i]->display ();
		delete shapes[i];
	}
	
	return 0;
}