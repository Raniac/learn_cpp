#include <iostream>
#include <vector>

using namespace std;

// ==================================================
// A Vector-Based Implementation of the Complete Tree

template <typename E>
class VectorCompleteTree {
public:
    VectorCompleteTree() : V(1) {};
    typedef typename vector<E>::iteration Position;
    class Position;
    int size() const {
        return V.size() - 1;
    }
    Position left(const Position& p) {
        return pos(2*idx(p));
    }
    Position right(const Position& p) {
        return pos(2*idx(p) + 1);
    }
    Position parent(const Position& p) {
        return pos(idx(p) / 2);
    }
    bool hasLeft(const Position& p) const {
        return 2 * idx(p) <= size();
    }
    bool hasRight(const Position& p) const {
        return 2* idx(p) + 1 <= size();
    }
    bool isRoot(const Position& p) const {
        return idx(p) == 1;
    }
    Position root() {
        return pos(1);
    }
    Position last() {
        return pos(size());
    }
    void addLast(const E& e) {
        V.push_back(e);
    }
    void removeLast() {
        V.pop_back();
    }
    void swap(const Position& p, const Position& q) {
        E e = *q;
        *q = *p;
        *p = e;
    }
private:
    vector<E> V;
protected:
    Position pos(int i) {
        return V.begin() + i;
    }
    int idx(const Position& p) const {
        return p - V.begin();
    }
};

// ==================================================

// ==========================
// C++ Implementation of Heap

template <typename E, typename C>
class HeapPriorityQueue {
public:
    int size() const {
        return T.size();
    }
    bool empty() const {
        return size() == 0;
    }
    void insert(const E& e) {
        T.addLast(e);
        Position v = T.last();
        while (!T.isRoot(v)) {
            Position u = T.parent(v);
            if (!isLess(*v, *u)) break;
            T.swap(v, u); // swap the value with parent
            v = u; // update pointer
        }
    }
    const E& min() {
        return *(T.root()); // return reference to root element;
    }
    void removeMin() {
        if (size() == 1) T.removeLast();
        else {
            Position u = T.root();
            T.swap(u, T.last());
            T.removeLast();
            while (T.hasLeft(u)) {
                Position v = T.left(u);
                if (T.hasRight(u) && isLess(*(T.right(u)), *v))
                    v = T.right(u); // v is u's smaller child
                if (isLess(*v, *u)) {
                    T.swap(u, v);
                    u = v;
                }
                else break; // else we're done
            }
        }
    }
private:
    VectorCompleteTree<E> T;
    C isLess;

    typedef typename VectorCompleteTree<E>::Position Position;
};

// ==========================
