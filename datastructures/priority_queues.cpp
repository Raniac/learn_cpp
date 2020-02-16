#include <iostream>
#include <queue>
#include <list>

using namespace std;

template <typename E, typename C>

// ==============================
// A C++ Priority Queue Interface

class PriorityQueue {
public:
    int size() const;
    bool isEmpty() const;
    void insert(const E& e);
    const E& min() const;
    void removeMin();
};

// ==============================

// ============================
// The STL priority_queue Class

priority_queue<int, vector<int>, greater<int> > p1;

// ============================

// ================================================
// A C++ Priority Queue Implementation using a List

template <typename E, typename C>
class ListPriorityQueue {
public:
    int size() const;
    bool empty() const;
    void insert(const E& e);
    const E& min() const;
    void removeMin();
private:
    list<E> L;
    C isLess; // less-than comparator
};

template <typename E, typename C>
int ListPriorityQueue<E, C>::size() const {
    return L.size();
}

template <typename E, typename C>
bool ListPriorityQueue<E, C>::empty() const {
    return L.empty();
}

template <typename E, typename C>
void ListPriorityQueue<E, C>::insert(const E& e) {
    list<E>::iterator p;
    p = L.begin();
    while (p != L.end() && !isLess(e, *p)) ++p;
    L.insert(p, e);
}

template <typename E, typename C>
const E& ListPriorityQueue<E, C>::min() const {
    return L.front();
}

template <typename E, typename C>
void ListPriorityQueue<E, C>::removeMin() {
    L.pop_front();
}

// ================================================

int main() {
    for (int i = 0; i < 10; i++) {
        p1.push(i);
    }
    cout << p1.top() << endl;
}
