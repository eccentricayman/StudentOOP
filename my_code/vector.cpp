#include <iostream>
#include "vector.h"

using namespace std;

void print_vector(const MyVec& v) {
	for (int a = 0 ; a < v.size() ; a++) {
		cout << v[a] << " ";
	}
	cout << endl;
}


MyVec::MyVec(): data(new int[10]), sz(0), capacity(DEF_CAPACITY) {}

MyVec::MyVec(const MyVec& v2) {
	sz = v2.size();
	capacity = v2.capacity;
	data = new int[capacity];
	for (int a = 0 ; a < size() ; a++) {
		data[a] = v2.data[a];
	}
}

MyVec::~MyVec() {
	delete[] data;
}

MyVec& MyVec::operator=(const MyVec& v2) {
	if (this != &v2) {
		delete[] data;

		sz = v2.size();
		capacity = v2.capacity;
		data = new int[capacity];
		for (int a = 0 ; a < size() ; a++) {
			data[a] = v2.data[a];
		}
	}
	return *this;
}


/*
 * == is true when every element of the vectors are the same in
 * the same order. (Thus they must be the same size.)
 * */
bool operator==(MyVec& v1, MyVec& v2) {
	if (v1.size() == v2.size()) {
		for (int a = 0 ; a < v1.size() ; a++) {
			if (v1[a] != v2[a]) {
				return false;
			}
		}
		return true;
	}
	else {
		return false;
	}
}

/*
 * Puts an element at the back of a vector.
 * */
void MyVec::push_back(int val) {
	if (sz == capacity) {
		capacity *= 2;
		int* newData = new int[capacity];
				
		for (int a = 0 ; a < size() ; a++) {
			newData[a] = data[a];
		}
		
		delete[] data;
		data = newData;
	}
	data[sz++] = val;
}

/*
 * this [] is for reading items from the MyVec:
 * It returns the i-th element.
 * */
int MyVec::operator[](int i) const {
    return data[i];
}

/*
 * this [] allows write access to items in the MyVec:
 * It returns a reference to the i-th element.
 * */
int& MyVec::operator[](int i) {
	return data[i];
}
