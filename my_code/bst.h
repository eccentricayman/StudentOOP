#include <iostream>

void indent(int level) {
    // indent more at each level:
    for (int i = 0; i < level; i++) std::cout << "  ";
}

template <typename T>
class Bst {
    friend void print_bst(const Bst<T>& bst, int level=0) {
        indent(level);
        level++;

        std::cout << "data: " << bst.data << std::endl;
        indent(level + 1);
        std::cout << "left: ";
   
        if (!bst.left) std::cout << "nullptr\n";
        else {
            std::cout << "\n";
            indent(level);
            print_bst(*bst.left, level);
        }
        indent(level + 1);
        std::cout << "right: ";
        if (!bst.right) std::cout << "nullptr\n";
        else {
            std::cout << "\n";
            indent(level);
            print_bst(*bst.right, level);
        }
        std::cout << std::endl;
    }

public:
	Bst(T d, Bst* p=nullptr, Bst* l=nullptr, Bst* r=nullptr)
		: data(d), parent(p), left(l), right(r) {}

	Bst<T>* insert(const T d) {
		if (d == data) {
			return nullptr;
		}
		else if (d < data) {
			if (!left) {
				left = new Bst(d, this);
				return left; 
			}
			else {
				return left -> insert(d);
			}
		}
		else {
			if (!right) {
				right = new Bst(d, this);
				return right;
			}
			else {
				return right ->insert(d);
			}
		}
	}

	T get_val() const {
		return data;
	}

	T min() {
        if (!left) {
            return data;
        }
        else {
            return left -> min();
        }
    }
    
    T max() {
        if (!right) {
            return data;
        }
        else {
            return right -> max();
        }
    }

	Bst<T>* search(T node) {
        if (node == data ) {
			return this;
		}
        else if (node < data) {
            if (!left) {
                return nullptr;
            }
            else {
                return left -> search(node);
            }
        }
        else {
            if (!right) {
                return nullptr;
            }
            else {
                return right -> search(node);
            }
        }
    }

	T predecessor(T d) {
        Bst<T>* node = search(d);
        if (node -> left) {
            return node -> left -> max();
        }
        else {
            Bst<T>* parent = node -> parent;
            while (parent) {
                if (parent -> data < d) {
                    return parent -> data;
                }
                parent = parent -> parent;
            }
            return d;
        }
    }

	T successor(T d) {
        Bst<T>* node = search(d);
        if (node -> right) {
            return node -> right -> min();
        }
        else {
            Bst<T>* parent = node -> parent;
            while (parent) {
                if (parent -> data > d) {
                    break;
                }
                parent = parent -> parent;
			}
            return parent -> data;
        }
    }
	
private:
	T data;
	Bst* parent;
	Bst* left;
	Bst* right;
};

