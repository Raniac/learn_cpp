#include <iostream>
#include "binary_search_trees.cpp"

using namespace std;

// ===================================
// A C++ Implementation of an AVL Tree

template <typename E>
class AVLEntry : Public E {
private:
    int ht; // node height
protected:
    typedef typename E::Key K;
    typedef typename E::Value V;
    int height() const { return ht; }
    void setHeight(int h) { ht = h; }
public:
    AVLEntry(const K& k = K(), const V& v = V()) : E(k, v), ht(0) {}
    friend class AVLTree<E>;
};

template <typename E>
class AVLTree : public SearchTree< AVLEntry<E> > {
    public:
    typedef AVLEntry<E> AVLEntry;
    typedef typename SearchTree<AVLEntry>::Iterator Iterator;
    protected:
    typedef typename AVLEntry::Key K;
    typedef typename AVLEntry::Value V;
    typedef SearchTree<AVLEntry> ST;
    typedef typename ST::TPos TPos;
    public:
    AVLTree() : ST() {}
    Iterator insert(const K& k, const V& x) {
        TPos v = inserter(k, x);
        setHeight(v);
        rebalance(v);
        return Iterator(v);
    }
    void erase(const K& k) {
        TPos v = finder(k, ST::root());
        // if (Iterator(v) == ST::end()) throw Exception()
        TPos w = eraser(v);
        rebalance(w);
    }
    void erase(const Iterator& p);
    protected:
    int height(const TPos& v) const {
        return (v.isExternal() ? 0 : v->height());
    }
    void setHeight(TPos v) {
        int hl = height(v.left());
        int hr = height(v.right());
        v->setHeight(1 + max(hl, hr));
    }
    bool isBalanced(const TPos& v) const {
        int bal = height(v.left()) - height(v.right);
        return ((-1 <= bal) && (bal <= 1));
    }
    TPos tallGrandchild(const TPos& z) const {
        TPos zl = z.left();
        TPos zr = z.right();
        if (height(zl) >= height(zr)) {
            if (height(zl.left()) >= height(zl.right())) return zl.left();
            else return zl.right();
        }
        else {
            if (height(zr.left()) <= height(zr.right())) return zr.right();
            else return zr.left();
        }
    }
    void rebalance(const TPos& v) {
        TPos z = v;
        while (!(z == ST::root())) {
            z = z.parent();
            setHeight(z);
            if (!isBalanced(z)) {
                TPos x = tallGrandchild(z);
                z = restructure(x);
                setHeight(z.left());
                setHeight(z.right());
                setHeight(z);
            }
        }
    }
};

// ===================================