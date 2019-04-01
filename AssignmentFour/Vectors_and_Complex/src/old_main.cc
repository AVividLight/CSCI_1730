#include <iostream>


class Pairs
{

public:
	Pairs (float a = 0.0, float b = 0.0);
	
	friend Pairs operator+ (const Pairs &number_one, const Pairs &number_two);
	friend Pairs operator- (const Pairs &number_one, const Pairs &number_two);
	friend bool operator== (const Pairs &number_one, const Pairs &number_two);
	
protected:
	float leading_number;
	float trailing_number;
};


Pairs::Pairs (float a, float b)
{
	
	leading_number = a;
	trailing_number = b;
}


Pairs operator+ (const Pairs &number_one, const Pairs &number_two)
{
	
	return Pairs ((number_one.leading_number + number_two.leading_number), (number_one.trailing_number + number_two.trailing_number));
}


Pairs operator- (const Pairs &number_one, const Pairs &number_two)
{
	
	return Pairs ((number_one.leading_number - number_two.leading_number), (number_one.trailing_number - number_two.trailing_number));
}


bool operator== (const Pairs &number_one, const Pairs &number_two)
{
	
	return ((number_one.leading_number == number_two.leading_number && number_one.trailing_number == number_two.trailing_number) ? true : false);
}


class Complex_Number : public Pairs
{
	
public:
	
	Complex_Number (float a = 0.0, float b = 0.0);
	
	const float get_real () const {return leading_number;}
	const float get_imaginary () const {return trailing_number;}
	
	friend Complex_Number operator* (const Complex_Number &number_one, const Complex_Number &number_two);
	friend Complex_Number operator/ (const Complex_Number &number_one, const Complex_Number &number_two);
	
private:

};


Complex_Number::Complex_Number (float a, float b)
{
	
	leading_number = a;
	trailing_number = b;
}


Complex_Number operator* (const Complex_Number &number_one, const Complex_Number &number_two)
{

	return Complex_Number (((number_one.get_real () * number_two.get_real ()) - (number_one.get_imaginary () * number_two.get_imaginary ())), (number_one.get_imaginary () * number_two.get_real ()) + (number_two.get_imaginary () * number_one.get_real ()));
}


Complex_Number operator/ (const Complex_Number &number_one, const Complex_Number &number_two)
{
	
	float denominator = ((number_two.get_real () * number_two.get_real ()) + (number_two.get_imaginary () * number_two.get_imaginary ()));
	
	return Complex_Number (((number_one.get_real () * number_two.get_real ()) + (number_one.get_imaginary () * number_two.get_imaginary ()))/denominator, ((number_one.get_imaginary () * number_two.get_real ()) - (number_one.get_real () * number_two.get_imaginary ()))/denominator);;
}


class Vector : public Pairs
{

public:
	
	Vector (float a = 0.0, float b = 0.0);
	
	friend Vector operator* (const Vector &number_one, const Vector &number_two);
	friend Vector operator* (const Vector &number_one, const float number_two);
	
private:

};


Vector::Vector (float a, float b)
{
	
	leading_number = a;
	trailing_number = b;
}


Vector operator* (const Vector &number_one, const Vector &number_two)
{

	return Vector ((number_one.leading_number * number_two.leading_number), (number_one.trailing_number * number_two.trailing_number));
}


Vector operator* (const Vector &number_one, const float number_two)
{

	return Vector ((number_one.leading_number * number_two), (number_one.trailing_number * number_two));
}


void cActions ()
{
	
	
}


void vActions ()
{
	
	
}


/* *** FOLLOWING IS CODE PROMPT FROM PROFESSOR *** */
using namespace std;

int main()
{
   int sel;
   do {
      cout << "Select an option - (1) perform complex number actions\n";
      cout << "                   (2) perform vector actions\n";
      cout << "                   (3) exit\n";
      cin >> sel;
      if(sel == 1)
         cActions();
      else if(sel == 2)
         vActions();
      else if (sel == 3)
         cout << "Bye...\n";
      else
         cout << "Invalid input - try again\n";
   } while (sel != 3);
   char ch; cin >> ch;
   return 0;
}
/* *** END CODE PROMPT FROM PROFESSOR *** */
