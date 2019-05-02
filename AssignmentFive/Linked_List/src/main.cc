#include <iostream>

#if defined __cpp_lib_concepts && __has_include(<type_traits>)
#  include <type_traits> //-std=c++14
#  define ENSURE_TYPE
#endif

#ifndef nullptr
#define nullptr null
#endif


template <typename T>
class LinkNode {
public:
	LinkNode () {link = nullptr; value = 0.0;}
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
concept Arithmetic = requires (T type) { //-std=c++2a
	std::is_arithmetic<type> == true;
};
template<Arithmetic T>
#endif
	
class LinkedList {
public:
	LinkedList<T> ();
	
	LinkNode<T> *search (T *match, LinkNode<T> *start = head);
	
	void insert_head (LinkNode<T> *node);
	void insert (LinkNode<T> *node, LinkNode<T> *after);
	
	LinkNode<T> &remove ();
private:
	LinkNode<T> *head;
};


template <typename T>
LinkedList<T>::LinkedList () {
	head = nullptr;
}


template <typename T>
LinkNode<T> LinkedList<T>::*search (T *match, LinkNode<T> *start) {
	LinkNode<T> *index = start;
	
	while (index != nullptr && index->get_value != match->get_value ()) {
		index = index->get_link ();
	}
	
	return index;
}


template <typename T>
void LinkedList<T>::insert_head (LinkNode<T> *node) {
	node->set_link (head);
	head = node;
}


template <typename T>
void LinkedList<T>::insert (LinkNode<T> *node, LinkNode<T> *after) {
	node->set_link (after->get_link ());
	after->set_link (node);
}


int main (int argc, char const *argv[]) {
	std::cout << "Project 2 from Assignment 5" << std::endl << "Linked List" << std::endl << "This program implements a linked list and sorting algorithm." << std::endl << std::endl;

	LinkedList<float> linked_list;
	
	
	return 0;
}