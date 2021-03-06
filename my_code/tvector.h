#ifndef tvector_h
#define tvector_h
#include <iostream>

const int DEF_CAPACITY = 10;

template <typename T>
class MyVec {
public:
    MyVec() {
        sz = 0;
        capacity = DEF_CAPACITY;
        data = new T[DEF_CAPACITY];
    }
    
    MyVec(int sz, const T val=T()) : sz{sz} {
        data = new T[sz * 2];
        for(int i = 0; i < sz ; i++) {
            data[i] = val;
        }
    }
    
    void push_back(T val) {
        sz++;
        if (sz > capacity) {
            T* old_data = data;
            data = new T[capacity * 2];
            for (int i = 0; i < sz; i++) {
                data[i] = old_data[i];
            }
            capacity *= 2;
            delete [] old_data;
        }
        data[sz - 1] = val;
    }
    int size() const { return sz; }
    
    T operator[](int i) const {
        return data[i];
    }
    T& operator[](int i){
        return data[i];
    }
    
    MyVec(const MyVec& v2) {
        copy(v2);
    }

	~MyVec() {
		delete [] data;
	}

	MyVec& operator = (const MyVec& v2) {
        if (this != &v2) {
            delete [] data;
            copy(v2);
        }
        return *this;
    }

private:
    void copy(const MyVec& v2) {
        sz = v2.sz;
        capacity = v2.capacity;
        data = new T[capacity];
        for (int i = 0; i < sz; i++) {
            data[i] = v2.data[i];
        }
    }
    
    T* data;
    int sz;
    int capacity;
};


template <typename T>
void print_vector(const MyVec<T>& v){
    for(int i = 0; i < v.size() ; i++) {
		std::cout << v[i] << ' ';
    }
	std::cout << std::endl;
}

template <typename T>
bool operator==(MyVec<T>& v1, MyVec<T>& v2) {
    if (v1.size() != v2.size()) {
        return false;
    }
	else {
        for (int i = 0; i < v1.size() ; i++ ) {
            if (v1[i] != v2[i]) {
                return false;
            }
        }
    }
    return true;
}

#endif
