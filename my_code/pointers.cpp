#include <iostream>
#include "pointers.h"

using namespace std;

void inc_by_value(int n) {
	n += 1;
}


void inc_with_pointer(int* iptr) {
	(*iptr)++;
}


void inc_with_reference(int& n) {
	n++;
}


Thing** create_array_of_things(int n) {
	Thing** tarr = new Thing*[n];
	for (int a = 0 ; a < n ; a++) {
		tarr[a] = new Thing(a);
	}
    return tarr;
}

void print_all_things(Thing** things, int n) {
	for (int a = 0 ; a < n ; a++) {
		cout << things[a] -> val << " ";
	}
	cout << endl;
}

void double_all_things(Thing** things, int n) {
	for (int a = 0 ; a < n ; a++) {
		things[a] -> val *= 2;
	}
}

void delete_all_things(Thing** things, int n) {
	for (int a = 0 ; a < n ; a++) {
		things[a] = nullptr;
	}
	//things = nullptr;
}


void assignTA(Student* s, Student* ta) {
	s -> ta = ta;
}

void printTAs(vector<Student*>& students) {
	for (size_t a = 0 ; a < students.size() ; a++) {
		cout << students[a] -> name << " -> ";
		if (students[a] -> ta != nullptr) {
			cout << students[a] -> ta -> name << endl;
		}
		else {
			cout << "no ta" << endl;
		}
	}
}
