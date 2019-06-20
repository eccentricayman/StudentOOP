#include <iostream>
#include "llist.h"

using namespace std;



/*
 * Output a Node pointer.
 * */
ostream& operator<<(ostream& os, const Node* nd) {
	os << nd -> data;
    return os;
}


/*
 * Add a node to the end of a list.
 * */
void add_at_end(Node*& head, int d) {
	if (head == nullptr) {
		head = new Node(d);
	}
	else {
		Node* current = head;
		while (current -> next != nullptr) {
			current = current -> next;
		}
		current -> next = new Node(d);
	}
}


/*
 * Given the head of a list, print the whole thing.
 * Let's do this recursively!
 * */
void print_list(ostream& os, const Node* curr) {
	if (curr == nullptr) {
		cout << "END";
	}
	else {
		cout << curr << " -> ";
		print_list(os, curr -> next);
	}
	cout << endl;
}

/*
 * Add a node at the front of a linked list.
 * */
void add_at_front(Node*& head, int d) {
	Node* newHead = new Node(d, head);
	head = newHead;
}


/*
 * Get the last node of a list.
 * */
Node* last(Node* head) {
	Node* current = head;
	while (current -> next != nullptr) {
		current = current -> next;
	}
    return current;
}
