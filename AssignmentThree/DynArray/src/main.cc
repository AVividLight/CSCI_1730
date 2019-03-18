#include <iostream>

using namespace std;


class DynArray
{
public:
	DynArray ();
	DynArray (int size);
	virtual ~DynArray ();
	
	void set (int position, int value);
	void show (int position);
	void expand (int additional_size);

private:
	int *data;
	unsigned int size;
};


DynArray::DynArray ()
{
	
	data = new int[0];
	size = 0;
}


DynArray::DynArray (int n_size)
{
	
	data = new int[n_size];
	size = n_size;
}

DynArray::~DynArray ()
{
	
	size = 0;
	delete data;
	
	std::cout << "hi from the DynArray destructor..." << std::endl;
}


void DynArray::set (int position, int value)
{
	
	if (position <= size)
		data[position] = value;
	else
	{
		
		if (size == 0)
			std::cout << "Cannot set - DynArray empty" << std::endl;
		else
			std::cout << "Invalid index in set" << std::endl;
	}
}


void DynArray::show (int position)
{
	
	if (position <= size)
		std::cout << data[position] << std::endl;
	else
	{
	
		if (size == 0)
			std::cout << "Cannot show - DynArray empty" << std::endl;
		else	
			std::cout << "Invalid index in show" << std::endl;
	}
}


void DynArray::expand (int additional_size)
{
	
	if (additional_size > 0)
	{
		
		int *new_data = new int [size + additional_size];
		
		for (int i = 0; i < size; i += 1)
		{
			
			new_data [i] = data[i];
		}
		
		delete [] data;
		data = new_data;
		size += additional_size;
		
	} else {
		
		std::cout << "Function expand should not shrink DynArray" << std::endl;
	}
}


/*======================================*/
/*		Following Code: from Professor	*/
/*======================================*/
void myFunc()
{
 	int i;
 	cout << "hi from myFunc...\n";
 	DynArray y(5);
 	for(i=0;i<5;i++)
 	   y.set(i,i*i);
 	for(i=0;i<5;i++)
 		y.show(i);
 	cout << "bye from myFunc...\n";
}
	
int main()
{
	
	int size,more,i;
	DynArray y;
	
	cout << "Enter dynamic array size: ";
	cin >> size;
	DynArray x(size);
	
	for(i=0;i<size;i++)
		x.set(i,3*i);
	
	for(i=0;i<size;i++)
		x.show(i);
	
	cout << "How much more dynamic array space do you want? ";
	cin >> more;
	x.expand(more);
	
	for(i=0;i<(size+more);i++)
		x.set(i,5*i);
	
	for(i=0;i<(size+more);i++)
		x.show(i);
	
	x.show(size+more+5);	//invalid index in show
	x.set(-2,9);		//invalid index in set
	y.set(3,6);			//empty DynArray set
	y.show(3);			//empty DynArray show
	myFunc();
	
	char ch; cin >> ch;
	return 0;
}