Incomplete as of 4/25/2019
===

Write a class template List for modeling a list of five elements which will have values from one of four different data types (`int`, `float`, `char`, `Distance`). This class should support these list manipulation tasks:

- Initialize a list to “zero” values. 
- Initialize a list to the values stored in a list of the same type.
- Allow for user input of a list.
- Display a list.
- Sort a list into ascending order.

Then, write a template function demo, that will accept a flag of the type data you would like and then create a list of that type to demonstrate the list class – it will do these tasks:

- Create a list of the selected type and display it, showing the initialized “zero” values it contains.
- Have the user enter values into the list and then display the values.
- Create a second list of the selected type, initializing it to the values stored in the first list, and then display the second list.
- Sort the values in the first list.
- Display the sorted list.

Program Requirements:

To perform the sorting, use either a `selection` or `bubble sort` algorithm. See the document posted with the assignments “sort and search.doc” for details on these algorithms.

The Distance class is given below:
<pre>class Distance                           //English Distance class
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
   s << d.feet << "\'-" << d.inches << '\"';    //using
   return s;                                    //overloaded
}                                               //<< operator</pre>

Note:  A `char` value can be initialized to zero – when displayed, no output appears.

To test your templates, try using the following main driver: 
<pre>int main()
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
}</pre>

Note: To see how this program works, copy  S:\Coursework\Liu\a6-1.exe to your own folder to run the program.

Here is a sample run of the program (user input is bold):

<pre>TEMPLATE DEMO PROGRAM
Enter list type (1=int 2=float 3=char 4=Distance 5=exit): <b>1</b>
New blank list created
List values  -> 0       0       0       0       0
Enter values into the list
Enter element 1: <b>5</b>
Enter element 2: <b4</b>
Enter element 3: <b>3</b>
Enter element 4: <b>2</b>
Enter element 5: <b>1</b>
List entered -> 5       4       3       2       1
Create a second list initialized to the first
List created -> 5       4       3       2       1
Sort the first list
Sorted list --> 1       2       3       4       5

Enter list type (1=int 2=float 3=char 4=Distance 5=exit): <b>2</b>
New blank list created
List values  -> 0       0       0       0       0
Enter values into the list
Enter element 1: <b>5.6</b>
Enter element 2: <b>-3.4</b>
Enter element 3: <b>-6.8</b>
Enter element 4: <b>10.6</b>
Enter element 5: <b>3.9</b>
List entered -> 5.6     -3.4    -6.8    10.6    3.9
Create a second list initialized to the first
List created -> 5.6     -3.4    -6.8    10.6    3.9
Sort the first list
Sorted list --> -6.8    -3.4    3.9     5.6     10.6

Enter list type (1=int 2=float 3=char 4=Distance 5=exit): <b>3</b>
New blank list created
List values  ->
Enter values into the list
Enter element 1: <b>p</b>
Enter element 2: <b>z</b>
Enter element 3: <b>o</b>
Enter element 4: <b>b</b>
Enter element 5: <b>w</b>
List entered -> p       z       o       b       w
Create a second list initialized to the first
List created -> p       z       o       b       w
Sort the first list
Sorted list --> b       o       p       w       z

Enter list type (1=int 2=float 3=char 4=Distance 5=exit): <b>4</b>
New blank list created
List values  -> 0'-0"   0'-0"   0'-0"   0'-0"   0'-0"
Enter values into the list
Enter element 1:
Enter feet: <b>7</b>
Enter inches: <b>5</b>
Enter element 2:
Enter feet: <b>2</b>
Enter inches: <b>11</b>
Enter element 3:
Enter feet: <b>10</b>
Enter inches: <b>4</b>
Enter element 4:
Enter feet: <b>3</b>
Enter inches: <b>10</b>
Enter element 5:
Enter feet: <b>8</b>
Enter inches: <b>9</b>
List entered -> 7'-5"   2'-11"  10'-4"  3'-10"  8'-9"
Create a second list initialized to the first
List created -> 7'-5"   2'-11"  10'-4"  3'-10"  8'-9"
Sort the first list
Sorted list --> 2'-11"  3'-10"  7'-5"   8'-9"   10'-4"

Enter list type (1=int 2=float 3=char 4=Distance 5=exit): <b>5</b></pre>
