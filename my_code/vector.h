#include <iostream>
const int DEF_CAPACITY = 10;

class MyVec{
public:
	MyVec();
	MyVec(int sz, int val=0);
	
	MyVec(const MyVec& v2);
	~MyVec();
	MyVec& operator = (const MyVec& v2);
	
	void push_back(int val);
	int size() const {
		return sz;
	}
	
	int operator[] (int i) const {
		return data[i];
	}
	int& operator[] (int i) {
		return data[i];
	}
	
	class Iterator {
		friend bool operator !=(Iterator& rhs, Iterator& lhs){
			return rhs.iptr != lhs.iptr;
		}
		friend bool operator ==(Iterator& rhs, Iterator& lhs){
			return rhs.iptr == lhs.iptr;
		}
	public:
		Iterator(int* ip) : iptr(ip) {}
		Iterator& operator++() {
			iptr++;
			return *this;
		}
		int operator*() {
			return *iptr;
		}
	private:
		int* iptr;
	};
	
	Iterator begin() const;
    Iterator end() const;
	
private:
	
	int sz;
	int capacity;
	int* data;
};

void print_vector(const MyVec& v);
bool operator==(MyVec& v1, MyVec& v2);
