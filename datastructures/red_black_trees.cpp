#include <iostream>
#include "binary_search_trees.cpp"

using namespace std;

/*
Root Property: The root is black.
External Property: Every external node is black.
Internal Property: The children of a red node are black.
Depth Property: All the external nodes have the same black depth,
    defined as the number of black ancestors minus one. (Recall
    that a node is an ancestor of itself.)
*/

// ======================================
// C++ Implementation of a Red-Black Tree

enum Color {RED, BLACK};

template <typename E>
class RBEntry : public E {
    private:
    Color col;
    protected:
    typedef typename E::Key K;
    typedef typename E::Value V;
    Color color() const { return col; }
    bool isRed() const { return col == RED; }
    bool isBlack() const { return col == BLACK; }
    void setColor(Color c) { col == c; }
    public:
    RBEntry(const K& k = K(), const V& v = V()) : E(k, v), col(BLACK) {}
    friend class RBTree<E>;
};

template <typename E>
class RBTree : public SearchTree< RBEntry<E> > {
    public:
    typedef RBEntry<E> RBEntry;
    typedef typename SearchTree<RBEntry>::Iterator Iterator;
    protected:
    typedef typename RBEntry::Key K;
    typedef typename RBEntry::Value V;
    typedef SearchTree<RBEntry> ST;
    typedef typename ST::TPos TPos;
    public:
    RBTree();
    Iterator insert(const K& k, const V& x) {
        TPos v = inserter(k, x);
        if (v == ST::root()) {
            setBlack(v);
        }
        else {
            setRed(v);
            remedyDoubleRed(v);
        }
        return Iterator(v);
    }
    void erase(const K& k) {
        TPos u = finder(k, ST::root());
        // if (Iterator(u) == ST::end()) throw Exception("Erase of nonexistent.")
        TPos r = eraser(u);
        if (r == ST::root() || r->isRed() || wasParentRed(r)) setBlack(r);
        else remedyDoubleBlack(r);
    }
    void erase(const Iterator& p);
    protected:
    void remedyDoubleRed(const TPos& z) {
        TPos v = z.parent();
        if (v == ST::root() || v->isBlack()) return;
        if (sibling(v)->isBlack()) { // Case 1: restructuring
            v = restructure(z);
            setBlack(v); // top vertex now black
            setRed(v.left());
            setRed(v.right());
        }
        else {
            setBlack(v);
            setBlack(sibling(v));
            TPos u = v.parent();
            if (u == ST::root()) return;
            setRed(u);
            remedyDoubleRed(u);
        }
    }
    void remedyDoubleBlack(const TPos& r) {
        TPos x = r.parent();
        TPos y = sibling(r);
        if (y->isBlack()) { // Case 1: restructuring
            if (y.left()->isRed() || y.right()->isRed()) {
                TPos z = (y.left()->isRed() ? y.left() : y.right());
                Color topColor = x->color();
                z = restructure(z);
                setColor(z, topColor);
                setBlack(r);
                setBlack(z.left());
                setBlack(z.right());
            }
            else { // Case 2: recoloring
                setBlack(r);
                setRed(y);
                if (x->isBlack() && !(x == ST::root())) {
                    remedyDoubleBlack(x);
                }
                setBlack(x);
            }
        }
        else { // Case 3: adjustment
            TPos z = (y == x.right() ? y.right() : y.left());
            restructure(z);
            setBlack(y);
            setRed(x);
            remedyDoubleBlack(r);
        }
    }
};

// ======================================
