#ifndef templ_ll_h
#define templ_ll_h

#include <iostream>


template <typename DATA>
/*
 So, in order to be able to control the data types that are available in the template,
 you must delcare 'template <typename DATA>' at every instance that you call data,
 including pointers, and all that wonderful stuff.
 */
class Node {
public:
    Node(DATA d, Node* n=nullptr) : data(d),next(n){}
    DATA data;
    Node* next;
};

/*
 * The various functions that can operate on our linked lists:
 * */

template <typename DATA>
std::ostream& operator<<(std::ostream& os, const Node <DATA> * nd);

template <typename DATA>
void print_list(std::ostream& os, const Node<DATA>* curr);

template <typename DATA>
Node<DATA>* last(Node<DATA>* head);

template <typename DATA>
void add_at_end(Node<DATA>*& head, DATA d);

template <typename DATA>
void add_at_front(Node<DATA>*& head, DATA d);

template <typename DATA>
bool del_head(Node<DATA>*& head);

template <typename DATA>
bool del_tail(Node<DATA>*& head);

template <typename DATA>
Node<DATA>* duplicate(Node<DATA>* head);

template <typename DATA>
Node<DATA>* reverse(Node<DATA>* curr, Node<DATA>* new_next=nullptr);

template <typename DATA>
Node<DATA>* join(Node<DATA>*& list1, Node<DATA>* list2);

#endif
