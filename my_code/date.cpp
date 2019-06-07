#include <iostream>
#include <string>
#include "date.h"
using namespace std;

ostream& operator << (ostream& os, const Date& date) {
	os << date.month << "/" << date.day << "/" << date.year;
	return os;
}

Date::Date(int d, int m, int y) : day(d), month(m), year(y) { }
