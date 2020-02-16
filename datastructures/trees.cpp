#include <iostream>
#include <list>

using namespace std;

// ====================
// A C++ Tree Interface

template <typename E>
class Position {
public:
    E& operator*();
    Position parent() const;
    Position children() const;
    bool isRoot() const;
    bool isExternal() const;
};

template <typename E>
class Tree {
public:
    class Position;
    class PositionList;
public:
    int size() const;
    bool empty() const;
    Position root() const;
    PositionList positions() const;
};

// ====================

// ==================
// Preorder Traversal

template <typename E>
void preorderPrint(const Tree<E>& T, const Position& p) {
    cout << *p;
    PositionList ch = p.children();
    for (Iterator q = ch.begin(); q != ch.end(); ++q) {
        cout << " ";
        preorderPrint(T, *q);
    }
}

// ==================

// ===================
// Postorder Traversal

template <typename E>
void postorderPrint(const Tree<E>& T, const Position& p) {
    PositionList ch = p.children;
    for (Iterator q = ch.begin(); q != ch.end(); ++q) {
        preorderPrint(T, *q);
        cout << " ";
    }
    cout << *p;
}

// ===================

// ===========================
// A C++ Binary Tree Interface

template <typename E>
class Position {
public:
    E& operator*();
    Position left() const;
    Position right() const;
    Position parent() const;
    bool isRoot() const;
    bool isExternal() const;
};

template <typename E>
class BinaryTree {
public:
    class Position();
    class PositionList();
public:
    int size() const;
    bool empty() const;
    Position root() const;
    PositionList positions() const;
};

// ===========================

// ===================================
// A Linked Structure for Binary Trees

typedef string Elem;
struct Node {
    Elem elt;
    Node* par;
    Node* left;
    Node* right;
    Node() : elt(), par(NULL), left(NULL), right(NULL) {} // constructor
};

class Position {
private:
    Node* v;
public:
    Position(Node* _v = NULL) : v(_v) {};
    Elem& operator*() {
        return v->elt;
    }
    Position left() const {
        return Position(v->left);
    }
    Position right() const {
        return Position(v->right);
    }
    Position parent() const {
        return Position(v->par);
    }
    bool isRoot() const {
        return v->par == NULL;
    }
    bool isExternal() const {
        return v->left == NULL && v->right == NULL;
    }
    friend class LinkedBinaryTree;
};

typedef list<Position> PositionList;

typedef int Elem;
class LinkedBinaryTree {
protected:
    void preorder(Node* v, PositionList& pl) const;
    void inorder(Node* v, PositionList& pl) const;
    void postorder(Node* v, PositionList& pl) const;
public:
    LinkedBinaryTree();
    int size() const;
    bool empty() const;
    Position root() const;
    PositionList positions() const;
    void addRoot();
    void expandExternal(const Position& p);
    Position removeAboveExternal(const Position& p);
private:
    Node* _root;
    int n;
};

LinkedBinaryTree::LinkedBinaryTree() : _root(NULL), n(0) {};

int LinkedBinaryTree::size() const {
    return n;
}

bool LinkedBinaryTree::empty() const {
    return size() == 0;
}

Position LinkedBinaryTree::root() const {
    return Position(_root);
}

void LinkedBinaryTree::addRoot() {
    _root = new Node;
    n = 1;
}

void LinkedBinaryTree::expandExternal(const Position& p) {
    Node* v = p.v;
    v->left = new Node;
    v->left->par = v;
    v->right = new Node;
    v->right->par = v;
    n += 2;
}

Position LinkedBinaryTree::removeAboveExternal(const Position& p) {
    Node* w = p.v;
    Node* v = w->par;
    Node* sib = (w == v->left ? v->right : v->left);
    if (v == _root) {
        _root = sib;
        sib->par = NULL;
    } else {
        Node* gpar = v->par;
        if (v == gpar->left) gpar->left = sib;
        else gpar->right = sib;
        sib->par = gpar;
    }
    delete w;
    delete v;
    n -= 2;
    return Position(sib);
}

PositionList LinkedBinaryTree::positions() const {
    PositionList pl;
    preorder(_root, pl);
    return PositionList(pl);
}

void LinkedBinaryTree::preorder(Node* v, PositionList& pl) const {
    pl.push_back(Position(v));
    if (v->left != NULL) {
        preorder(v->left, pl);
    }
    if (v->right != NULL) {
        preorder(v->right, pl);
    }
}

void LinkedBinaryTree::inorder(Node* v, PositionList& pl) const {
    if (v->left != NULL) {
        preorder(v->left, pl);
    }
    pl.push_back(Position(v));
    if (v->right != NULL) {
        preorder(v->right, pl);
    }
}

void LinkedBinaryTree::postorder(Node* v, PositionList& pl) const {
    if (v->left != NULL) {
        preorder(v->left, pl);
    }
    if (v->right != NULL) {
        preorder(v->right, pl);
    }
    pl.push_back(Position(v));
}

// ===================================
