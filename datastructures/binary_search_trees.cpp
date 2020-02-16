#include <iostream>
#include "trees.cpp"

using namespace std;

template <typename K, typename V>
class Entry {
public:
    typedef K Key;
    typedef V Value;
public:
    Entry(const K& k = K(), const V& v = V()) : _key(k), _value(v) {}
    const K& key() const { return _key; }
    const V& value() const { return _value; }
    void setKey(const K& k) { _key = k; }
    void setValue(const V& v) { _value = v; }
private:
    K _key;
    V _value;
};

template <typename E>
class SearchTree {
public:
    typedef typename E::Key K;
    typedef typename E::Value V;
    class Iterator {
    private:
        TPos v;
    public:
        Iterator(const TPos& vv) : v(vv) {}
        const E& operator*() const { return *v; }
        E& operator*() { return *v; }
        bool operator==(const Iterator& p) const {
            return v == p.v;
        }
        Iterator&  operator++() {
            TPos w = v.right();
            if (w.isInternal()) {
                do {v = w; w = w.left();}
                while (w.isInternal());
            }
            else {
                w = v.parent();
                while (v == w.right()) {
                    v = w;
                    w = w.parent();
                }
                v = w;
            }
        }
        friend class SearchTree;
    };
public:
    SearchTree() : T(), n(0) {
        T.addRoot(); // create super root
        T.expandExternal(T.root());
    }
    int size() const;
    bool empty() const;
    Iterator find(const K& k) {
        TPos v = finder(k, root());
        if (v.isInternal()) return Iterator(v);
        else return end();
    }
    Iterator insert(const K& k, const V& x) {
        TPos v = inserter(k, x);
        return Iterator(v);
    }
    void erase(const K& k) {
        TPos v = finder(k, root());
        eraser(v);
    }
    void erase(const Iterator& p) { eraser(p.v); }
    Iterator begin() {
        TPos v = root();
        while (v.isInternal()) v = v.left(); // find leftmost node
        return Iterator(v.parent());
    }
    Iterator end() { return Iterator(T.root()); } // return the super root
protected:
    typedef BinaryTree<E> BinaryTree;
    typedef typename BinaryTree::Position TPos;
    TPos root() const { return T.root().left(); } // get virtual root}
    TPos finder(const K& k, const TPos& v) {
        if (v.isExternal()) return v;
        if (k < v->key()) return finder(k, v.left());
        else if (v->key() < k) return finder(k, v.right());
        else return v;
    }
    TPos inserter(const K& k, const V& x) {
        TPos v = finder(k, root());
        while (v.isInternal()) {
            v.finder(k, v.right());
        }
        T.expandExternal(v);
        v->setKey(k);
        v->serValue(x);
        n++;
        return v;
    }
    TPos eraser(TPos& v) {
        TPos w;
        if (v.left().isExternal()) w = v.left();
        else if (v.right().isExternal()) w = v.right();
        else {
            w = v.right();
            do { w = w.left() } while (w.isInternal());
            TPos u = w.parent();
            v->setKey(u->key());
            v->setValue(u->value());
        }
        n--;
        return T.removeAboveExternal(w);
    }
    TPos restructure(const TPos& v);
private:
    BinaryTree T;
    int n;
};