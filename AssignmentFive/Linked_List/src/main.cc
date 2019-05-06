#include <iostream>

#ifndef nullptr
#define nullptr null
#endif


class Node {
public:
	Node () {value = 0.0; link = nullptr;}
	Node (float v, Node *l = nullptr) {value = v; link = l;}

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
	
	Node *traverse (const unsigned int index);
	
	void insert (Node *node, Node *after);
	float remove_index (const unsigned int index);
	//Node *remove_fist_value (const float match);
	
	Node *get_last ();
	
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
	
	return (index == nullptr ? 0 : position);
}


Node *LinkedList::traverse (const unsigned int index) {
	Node *target = get_head ();
	for (int i = 1; i < index; i += 1) {
		if (target == nullptr)
			break;
		
		target = target->get_link ();
	}
	
	return target;
}


void LinkedList::insert (Node *node, Node *after) {
		node->set_link (after->get_link ());
		after->set_link (node);
}


float LinkedList::remove_index (const unsigned int index) {
	Node *previous_node = traverse (index - 1);
	Node *remove = traverse (index);
	float remove_val = remove->get_value ();
	
	if ((index - 1) < 1)
		head = remove->get_link ();
	else
		previous_node->set_link (remove->get_link ());
	
	delete remove;
	return remove_val;
}


Node *LinkedList::get_last () {
	Node *n = head;
	
	while (n->get_link () != nullptr) {
		n = n->get_link ();
	}
	
	return n;
}


const unsigned int menu_select () {
	unsigned int menu;
	
	do {
		std::cout << "Make a selection:" << std::endl << "1. Add a value (floating-point number)" << std::endl << "2. Search for a value" << std::endl << "3. Find the nth value" << std::endl << "4. Delete the nth value" << std::endl << "5. Display list statistics (count, mean, and median)" << std::endl << "6. Display the list" << std::endl << "7. Quit" << std::endl;
		std::cin >> menu;
	} while (menu < 1 || menu > 7);
	
	std::cin.clear ();
	std::cin.ignore ();
	
	return menu;
}


template <typename T>
const T get_input () {
	T input;
	
	std::cout << "Enter number: ";
	std::cin >> input;
	std::cout << std::endl;
	
	std::cin.clear ();
	std::cin.ignore ();
	
	return input;
}


void menu_add (LinkedList &linked_list) {
	if (linked_list.get_head () == nullptr)
		linked_list.set_head (new Node (get_input<float> ()));
	else {
		linked_list.insert (new Node (get_input<float> ()), linked_list.get_last ());
		
		//sort
	}
}


void menu_search_value (LinkedList &linked_list) {
	const float target = get_input<float> ();
	const int pos = linked_list.search (target, linked_list.get_head ());
	if (pos == 0)
		std::cout << target << " is not in the list";
	else
		std::cout << target << " is in position " << pos;
}


void menu_search_index (LinkedList &linked_list) {
	const unsigned int pos = get_input<unsigned int> ();
	Node *target = linked_list.traverse (pos);
	
	if (target != nullptr)
		std::cout << "The value at node " << pos << " is " << target->get_value ();
	else
		std::cout << "The list does not contain " << pos << " elements";
}


void menu_delete_index (LinkedList &linked_list) {
	const unsigned int pos = get_input<unsigned int> ();
	Node *target = linked_list.traverse (pos);
	
	if (target != nullptr)
		std::cout << "Deleted " << \
		linked_list.remove_index (pos);
	else
		std::cout << "The list does not contain " << pos << " elements";		
}


void menu_stats (LinkedList &linked_list) {
	unsigned int count = 0;
	float mean = 0.0;
	float median = 0.0;
	
	Node *iter = linked_list.get_head ();
	while (true) {
		if (iter == nullptr)
			break;
		
		count += 1;
		mean += iter->get_value ();
		
		iter = iter->get_link ();
	}
	
	mean /= count;
	
	if (count % 2 != 0)
		median = linked_list.traverse(count / 2 + 1)->get_value ();
	else {
		median = linked_list.traverse(count / 2)->get_value ();
		median += linked_list.traverse(count / 2 + 1)->get_value ();
		median /= 2;
	}
	
	std::cout << "There are " << count << " elements in the linked list, the average of their values is " << mean << ", and the median value is " << median;
}


void menu_display (LinkedList &linked_list) {
	Node *node = linked_list.get_head ();
	while (node != nullptr) {
		std::cout << node->get_value () << ' ';
		node = node->get_link ();
	}
}


int main (int argc, char const *argv[]) {
	std::cout << "Project 2 from Assignment 5" << std::endl << "Linked List" << std::endl << "This program implements a linked list and sorting algorithm." << std::endl << std::endl;

	LinkedList linked_list;
	
	unsigned int menu;
	do {
		std::cout << std::endl << std::endl;
		menu = menu_select ();
		switch (menu) {
			case 1:
			menu_add (linked_list);
			break;
			
			case 2:
			menu_search_value (linked_list);
			break;
			
			case 3:
			menu_search_index (linked_list);
			break;
			
			case 4:
			menu_delete_index (linked_list);
			break;
			
			case 5:
			menu_stats (linked_list);
			break;
			
			case 6:
			menu_display (linked_list);
			break;
			
			default:
			break;
		}
	} while (menu != 7);
	
	return 0;
}
