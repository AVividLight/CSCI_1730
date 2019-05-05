#include <iostream>

#ifndef nullptr
#define nullptr null
#endif


class Node {
public:
	Node () {link = nullptr; value = 0.0;}
	Node (Node *l, float v) {link = l; value = v;}

	Node *get_link () {return link;}
	void set_link (Node *node) {link = node;}

	const float get_value () const {return value;}
	void set_value (float v) {value = v;}
	
	bool operator== (const Node *comp) {return (value == comp->get_value ());}
private:
	Node *link;
	float value;
};

	
class LinkedList {
public:
	LinkedList ();
	
	unsigned int search (const float match, Node *start);
	
	void insert_head (Node *node);
	void insert (Node *node, Node *after);
	
	Node remove ();
	
	void set_head (Node *h) {head = h;}
	Node *get_head () {return head;}
	
private:
	Node *head;
};


LinkedList::LinkedList () {
	head = nullptr;
}


unsigned int LinkedList::search (const float match, Node *start) {
	Node *index = start;
	
	unsigned int position = 1;
	while (index != nullptr && index->get_value () != match) {
		index = index->get_link ();
		position += 1;
	}
	
	return (index->get_link () == nullptr ? 0 : position);
}


void LinkedList::insert_head (Node *node) {
	node->set_link (head);
	head = node;
}


void LinkedList::insert (Node *node, Node *after) {
	node->set_link (after->get_link ());
	after->set_link (node);
}


const unsigned int menu_select () {
	unsigned int menu;
	
	do {
		std::cout << "Make a selection:" << std::endl << "1. Add a value (floating-point number)" << std::endl << "2. Search for a value" << std::endl << "3. Find the nth value" << std::endl << "4. Delete the nth value" << std::endl << "5. Display list statistics (count, mean, and median)" << std::endl << "6. Display the list" << std::endl << "7. Quit" << std::endl;
		std::cin >> menu;
	} while (menu > 0 && menu < 8);
	
	return menu;
}


int main (int argc, char const *argv[]) {
	std::cout << "Project 2 from Assignment 5" << std::endl << "Linked List" << std::endl << "This program implements a linked list and sorting algorithm." << std::endl << std::endl;

	LinkedList linked_list;
	
	unsigned int menu;
	do {
		menu = menu_select ();
		switch (menu) {
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
			
			default:
			break;
		}
	} while (menu != 7);
	
	return 0;
}
