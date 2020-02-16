#include <iostream>
#include <stack>
#include "linked_lists.cpp"

using namespace std;

// =============
// The STL Stack

stack<int> myStack;

// =============

// ===============================
// A C++ Implementation of a Stack

template <typename E>
class ArrayStack {
    enum { DEF_CAPACITY = 100 };
public:
    ArrayStack(int cap = DEF_CAPACITY);
    int size() const;
    bool empty() const;
    const E& top() const;
    void push(const E& e);
    void pop();
private:
    E* S;         // array of stack elements
    int capacity; // stack capacity
    int t;        // index of the top of the stack
};

template <typename E>
ArrayStack<E>::ArrayStack(int cap) : S(new E[cap]), capacity(cap), t(-1) {}

template <typename E>
int ArrayStack<E>::size() const {
    return (t + 1);
}

template <typename E>
bool ArrayStack<E>::empty() const {
    return (t < 0);
}

template <typename E>
const E& ArrayStack<E>::top() const {
    // if (empty()) throw StackEmpty("Top of empty stack.");
    return S[t];
}

template <typename E>
void ArrayStack<E>::push(const E& e) {
    // if (size() == capacity) throw StackFull("Push to full stack.");
    S[++t] = e;
}

template <typename E>
void ArrayStack<E>::pop() {
    // if (empty()) throw StackEmpty("Pop from empty stack.");
    --t;
}

// ===============================

// ===============================================
// Implementing a Stack with a Generic Linked List

typedef string Elem;
class LinkedStack {
public:
    LinkedStack();
    int size() const;
    bool empty() const;
    const Elem& top() const;
    void push(const Elem& e);
    void pop();
private:
    SLinkedList<Elem> S;
    int n;
};

LinkedStack::LinkedStack() : S(), n(0) {}

int LinkedStack::size() const {
    return n;
}

bool LinkedStack::empty() const {
    return n == 0;
}

const Elem& LinkedStack::top() const {
    // if (empty()) throw StackEmpty("Top of empty stack.")
    return S.front();
}

void LinkedStack::push(const Elem& e) {
    ++n;
    S.addFront(e);
}

void LinkedStack::pop() {
    // if (empty()) throw StackEmpty("Pop from empty stack.")
    --n;
    S.removeFront();
}

// ===============================================

// ================================
// Reversing a Vector Using a Stack

template <typename E>
void reverse(vector<E>& V) {
    ArrayStack<E> S(V.size());
    for (int i = 0; i < V.size(); i++) {
        S.push(V[i]);
    }
    for (int i = 0; i < V.size(); i++) {
        V[i] = S.top();
        S.pop();
    }
}

// ================================

int main() {
    // stack<int> myStack;
    // cout << myStack.size() << endl;
    ArrayStack<int> A;
    A.push(7);
    A.push(13);
    cout << A.top() << endl;
    A.pop();
    cout << A.top() << endl;
    return 0;
}