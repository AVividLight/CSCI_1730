#include <iostream>

#if defined __cpp_lib_concepts && __has_include(<type_traits>)
	#include <type_traits> //-std=c++14
	#define ENSURE_TYPE
#endif


/* *** ** * Code from professor * ** *** */
using namespace std;
class Distance                           //English Distance class
{
   private:
      int feet;
      float inches;
   public:
      Distance() : feet(0), inches(0.0)  //constructor (no args)
      {  }
                                         //constructor (two args)
      Distance(int ft, float in) : feet(ft), inches(in)

      {  }
      Distance( float fltfeet )          //constructor (one arg)
      {                                  //convert float to Distance
         feet = int(fltfeet);            //feet is integer part
         inches = 12*(fltfeet-feet);     //inches is what's left
      }
      bool operator < (Distance) const;  //compare distances
      friend istream& operator >> (istream& s, Distance& d);

      friend ostream& operator << (ostream& s, Distance& d);
};
bool Distance::operator < (Distance d2) const 
      {
   float bf1 = feet + inches/12;
   float bf2 = d2.feet + d2.inches/12;
   return (bf1 < bf2) ? true : false;
}


//--------------------------------------------------------------
istream& operator >> (istream& s, Distance& d)  //get Distance
{                                               //from user
   cout << "\nEnter feet: ";  s >> d.feet;      //using
   cout << "Enter inches: ";  s >> d.inches;    //overloaded
   return s;                                    //>> operator
}
//--------------------------------------------------------------
ostream& operator << (ostream& s, Distance& d)  //display
{                                               //Distance
   s << d.feet << "\'-" << d.inches << '"';    //using
   return s;                                    //overloaded
}                                               //<< operator
/* *** ** * End code from professor * ** *** */


template <typename T>
#ifdef ENSURE_TYPE
concept Arithmetic = requires (T type) { //-std=c++2a
	std::is_integer<type> || std::is_float<type> || std::is_char<type>; //-std=c++11
};
template<RequireType T>
#endif

class Element {
public:
	Element<T> () {}
	Element<T> (const T d) {data = d;}
	
	T get_data () {return data;}
	void set_data (const T d) {data = d;}
private:
	T data;
};


template <typename T>
void display (Element<T> *list[5]) {
	for (int i = 0; i < 5; i += 1) {
		T obj = list[i]->get_data ();
		std::cout << '\t' << obj;
	}
	std::cout << std::endl;
}


template <typename T>
void demo (T flag) {
	std::cin.clear ();
	std::cin.ignore ();
	
	Element<T> *list[5];
	for (int i = 0; i < 5; i += 1) {
		Element<T> *new_element = new Element<T>;
		new_element->set_data (flag);
		list[i] = new_element;
	}
	std::cout << "New blank list created" << std::endl;
	
	display (list);
}


int _PREEMPT () {std::cout << "Project 1 from Assignment 5" << std::endl << "Class Template" << std::endl << "This program uses templates to model four different data types." << std::endl << std::endl; return 0;}
static int _STARTUP = (_PREEMPT(), 0);


/* *** ** * Code from professor * ** *** */
int main()
{
    int sel;
    bool end=false;
    int iFlag=0;
    float fFlag=0;
    char cFlag=0;
    Distance dFlag;
    cout << "TEMPLATE DEMO PROGRAM\n";
    do{
        cout << "Enter list type (1=int 2=float 3=char 4=Distance 5=exit): ";
        cin >> sel;
        switch (sel)
        {
        case 1:
            demo(iFlag);
            break;
        case 2:
            demo(fFlag);
            break;
        case 3:
            demo(cFlag);
            break;
        case 4:
			demo(dFlag);
            break;
        default:
            end=true;
            cout << "Bye...\n";
            break;
        }
    }while(!end);
    return 0;
}
/* *** ** * End code from professor * ** *** */