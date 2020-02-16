#include <iostream>
#include <list>
#include <cstdlib> // provides EXIT_SUCCESS
#include <vector>
#include <algorithm> // for sort, random_shuffle
// #include "linked_lists.cpp"

using namespace std;

// =================================
// Doubly Linked List Implementation

// typedef string Elem;
// struct Node {
//     Elem elem;
//     Node* prev;
//     Node* next;
// };

// class Iterator: public DLinkedList {
// public:
//     Elem& operator*();
//     bool operator==(const Iterator& p) const;
//     bool operator!=(const Iterator& p) const;
//     Iterator& operator++();
//     Iterator& operator--();
//     friend class NodeList;
// private:
//     DNode* v;
//     Iterator(DNode* u);
// };

// DLinkedList::Iterator::Iterator(DNode* u) {
//     v = u;
// }

// Elem& DLinkedList::Iterator::operator*() {
//     return v->elem;
// }

// bool DLinkedList::Iterator::operator==(const Iterator& p) const {
//     return v == p.v;
// }

// bool DLinkedList::Iterator::operator!=(const Iterator& p) const {
//     return v != p.v;
// }

// DLinkedList::Iterator& DLinkedList::Iterator::operator++() {
//     v = v->next;
//     return *this;
// }

// DLinkedList::Iterator& DLinkedList::Iterator::operator--() {
//     v = v->prev;
//     return *this;
// }

// =================================

// =========
// STL Lists

list<float> myList;

// =========

// =================================================
// Implementing a Sequence with a Doubly Linked List

class NodeSequence : public NodeList {
public:
    Iterator atIndex(int i) const;
    int indexOf(const Iterator& p) const;
};

NodeSequence::Iterator NodeSequence::atIndex(int i) const {
    Iterator p = begin();
    for (int j = 0; j < i; j++) {
        ++p;
    }
    return p;
}

int NodeSequence::indexOf(const Iterator& p) const {
    Iterator q = begin();
    int j = 0;
    while (q != p) {
        ++q;
        ++j;
    }
    return j;
}

// =================================================

int main() {
    int a[] = {17, 12, 33, 15, 62, 45};
    vector<int> v(a, a+6); // equivalent as v = a[:6] in python
    cout << v.size() << endl;
    v.pop_back(); // 17 12 33 15 62
    cout << v.size() << endl;
    v.push_back(19); // 17 12 33 15 62 19
    cout << v.front() << " " << v.back() << endl;
    sort(v.begin(), v.begin() + 4); // (12 15 17 33) 62 19
    v.erase(v.end() - 4, v.end() - 2); // v = v[:-4] + v[-2:], 12 15 62 19
    cout << v.size() << endl;

    char b[] = {'b', 'r', 'a', 'v', 'o'};
    vector<char> w(b, b + 5); // b r a v o
    random_shuffle(w.begin(), w.end()); // o v r a b
    w.insert(w.begin(), 's'); // s o v r a b

    for (vector<char>::iterator p = w.begin(); p != w.end(); p++) {
        cout << *p << " ";
    } // s o v r a b
    cout << endl;
    return EXIT_SUCCESS;
}
