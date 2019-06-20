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

bool del_head(Node*& head) {
	if (head == nullptr) {
		return false;
	}
	else if (head -> next == nullptr) {
		delete head;
		head = nullptr;
	}
}

//not done
bool del_tail(Node** prev_next) {
	return true;
}

Node* duplicate(Node* head) {
	return new Node(head -> data, head -> next);
}

//not done
Node* reverse(Node* curr, Node* prev=nullptr) {
	return new Node(0);
}
