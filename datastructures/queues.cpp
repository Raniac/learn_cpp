#include <iostream>
#include <queue>
#include <deque>
#include "linked_lists.cpp"

using namespace std;

// =============
// The STL Queue

queue<float> myQueue;

// =============

// =====================
// A C++ Queue Interface

template <typename E>
class Queue {
public:
    int size() const;
    bool empty() const;
    const E& front() const;
    void enqueue(const E& e);
    void dequeue();
};

// =====================

// ==================================================
// Implementing a Queue with a Circularly Linked List

typedef string Elem;
class LinkedQueue {
public:
    LinkedQueue();
    int size() const;
    bool empty() const;
    const Elem& front() const;
    void enqueue(const Elem& e);
    void dequeue();
private:
    CircleList C;
    int n;
};

LinkedQueue::LinkedQueue() : C(), n(0) {}

int LinkedQueue::size() const {
    return n;
}

bool LinkedQueue::empty() const {
    return n == 0;
}

const Elem& LinkedQueue::front() const {
    // if (empty()) throw QueueEmpty("Front of empty queue.");
    return C.front();
}

void LinkedQueue::enqueue(const Elem& e) {
    C.add(e);
    C.advance();
    n++;
}

void LinkedQueue::dequeue() {
    // if (empty()) throw QueueEmpty("Dequeue from empty queue.");
    C.remove();
    n--;
}

// ==================================================

// =============
// The STL Deque

deque<string> myDeque;

// =============

// ==============================================
// Implementing a Deque with a Doubly Linked List

typedef string Elem;
class LinkedDeque {
public:
    LinkedDeque();
    int size() const;
    bool empty() const;
    const Elem& front() const;
    const Elem& back() const;
    void insertFront(const Elem& e);
    void insertBack(const Elem& e);
    void removeFront();
    void removeBack();
private:
    DLinkedList D;
    int n;
};

void LinkedDeque::insertFront(const Elem& e) {
    D.addFront(e);
    n++;
}

void LinkedDeque::insertBack(const Elem& e) {
    D.addBack(e);
    n++;
}

void LinkedDeque::removeFront() {
    // if (empty()) throw QueueEmpty("RemoveFront from empty deque.");
    D.removeFront();
    n--;
}

void LinkedDeque::removeBack() {
    // if (empty()) throw QueueEmpty("RemoveBack from empty deque.");
    D.removeBack();
    n--;
}

// ==============================================
