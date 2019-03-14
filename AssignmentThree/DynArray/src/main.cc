#include <iostream>


/*	======================================	*/
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