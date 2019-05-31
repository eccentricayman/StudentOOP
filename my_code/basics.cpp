#include <iostream>
#include <string>
#include <vector>
#include "basics.h"

using namespace std;

//prints a vector
void print_vector(std::vector<int> v) {
	for (int a = 0 ; a < v.size() ; a++) {
		cout << v[a] << " ";
	}
	cout << endl;
}

void print_coords(coord pos) {
	cout << "(" << pos.x << ", " << pos.y << ")" << endl;
}

int square(int n) {
	return n * n;
}

int my_abs(int n) {
	if (n >= 0) {
		return n;
	}
	else {
		return -n;
	}
}

int sum(int n) {
	int sum = 0;
	int ctr = 0;
	while (ctr < n) {
		sum += ctr;
		ctr++;
	}
	return sum;
}

int sum2(int n) {
	int sum = 0;
    for (int i = 0; i < n; i++){
        sum += i;
    }
    return sum;
}
 
void say(std::string s) {
	cout << s << endl;
}

