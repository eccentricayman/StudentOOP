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
		cout << "END" << endl;
	}
	else {
		cout << curr << " -> ";
		print_list(os, curr -> next);
	}
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
	if (head == nullptr) {
		return nullptr;
	}
	else {
		Node* current = head;
		while (current -> next != nullptr) {
			current = current -> next;
		}
		return current;
	}
}

bool del_head(Node*& head) {
	if (head == nullptr) {
		return false;
	}
	else if (head -> next == nullptr) {
		delete head;
		head = nullptr;
		return true;
	}
	else {
		Node* oldHead = head;
		head = head -> next;
		delete oldHead;
		return true;
	}
}

bool del_tail(Node*& head) {
	if (head == nullptr) {
		return false;
	}
	else if (head -> next == nullptr) {
		delete head;
		head = nullptr;
		return true;
	}
	else {
		Node* current = head;
		while (current -> next -> next != nullptr) {
			current = current -> next;
		}
		delete current -> next;
		current -> next = nullptr;
		return true;
	}
}

Node* duplicate(Node* head) {
	if (head == nullptr) {
		return nullptr;
	}
	else if (head -> next == nullptr) {
		return new Node(head -> data);
	}
	else {
		Node* newList = new Node(head -> data);
		Node* newListHead = newList;
		while(head -> next != nullptr) {
			newList -> next = new Node(head -> next -> data);
			newList = newList -> next;
			head = head -> next;
		}
		newList -> next = nullptr;
		return newListHead;
	}
}

Node* reverse(Node* curr, Node* new_next=nullptr) {
	Node* current = duplicate(curr);
	if (current == nullptr || current -> next == nullptr) {
		return current;
	}

	Node* remainder = current -> next;
	Node* reversed = current;
	reversed -> next = nullptr;

	while (remainder != nullptr) {
		Node* temp = remainder;
		remainder = remainder -> next;

		temp -> next = reversed;
		reversed = temp;
	}

	return reversed;
}

Node* join(Node*& list1, Node* list2) {
	Node* lastNode = last(list1);
	lastNode -> next = list2;
	return list1;
}
