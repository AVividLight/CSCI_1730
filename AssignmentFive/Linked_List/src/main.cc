#include <iostream>

#if __has_include(<type_traits>) && defined __cpp_lib_concepts
#  include <type_traits>
#  define ENSURE_TYPE
#endif


template <typename T>
class LinkNode {
public:
	LinkNode () {link = NULL; value = 0.0;}
	LinkNode (LinkNode *l, T v) {link = l; value = v;}
	
	LinkNode *get_link () {return link;}
	void set_link (LinkNode *node) {link = node;}
	
	T &get_value () {return &value;}
	void set_value (T v) {value = v;}

private:
	LinkNode *link;
	T value;
};


template <typename T>
#ifdef ENSURE_TYPE
concept Arithmetic = requires (T type) {
	std::is_arithmetic<type> == true;
};

template<Arithmetic T>
#endif
	
class LinkedList {
public:
	void insert ();
#define push_back () insert ()
	
	LinkNode<T> &remove ();
#define pop_back () remove ();
private:
	LinkNode<T> *head;
};


int main (int argc, char const *argv[]) {
	std::cout << "Project 2 from Assignment 5" << std::endl << "Linked List" << std::endl << "This program implements a linked list and sorting algorithm." << std::endl << std::endl;

	LinkedList<float> linked_list;
	
	
	return 0;
}