Complete as of 3/18/2019
===

The following C++ `main` driver, along with function `myFunc`, uses a C++ class `DynArray` that models a dynamic integer array – that is, the class uses dynamic memory allocation to create a contiguous block of memory for storing a specified number of integers. The indexing for a `DynArray` object is the same as for a regular array. But, a `DynArray` can be initialized to size zero. 

Write the C++ `DynArray` <b>class</b>. Here is a brief description of all of the class functions that your class should include:

- No-argument constructor – initializes a DynArray object to being empty.
- One-argument constructor – uses dynamic memory allocation to obtain a contiguous block of memory for storing n int values, where n is its argument.
- `show` – displays the nth element in the DynArray. If the DynArray is empty or if n is an invalid index, this function should generate an error message.
- `set` – will set the nth element in the DynArray to x, where n is the value of its first argument and x is value of its second argument. If the DynArray is empty or if n is an invalid index, this function should generate an error message.
- `expand` – will take an existing DynArray and expand its size by its argument, s.  Hint: To expand a DynArray, allocate a new, larger block of dynamic memory, copy the values from the old DynArray to the new memory, and deallocate the old memory.
- A destructor to deallocate dynamic memory when a DynArray object passes out of scope.

Requirement: When accessing the dynamic array elements in the set, show and expand member functions, you must use the <b>dereferencing operator, *</b>, along with pointer arithmetic instead of the array indexing operator, [].

Next, combine your `DynArray` class with the following `main` and `myFunc` code and run the resulting C++ program. The output generated from a run of your program should be similar to that shown in the output of a sample run given after the code.

	void myFunc();
	
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

Output from a sample run of the program (user input is in bold):
<pre>Enter dynamic array size: <b>3</b>
0
3
6
How much more dynamic array space do you want? <b>2
0
5
10
15
20
Invalid index in show
Invalid index in set
Cannot set - DynArray empty
Cannot show - DynArray empty
hi from myFunc...
0
1
4
9
16
bye from myFunc...
hi from the DynArray destructor...</pre>
