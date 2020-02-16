#include <iostream>

using namespace std;

// =================================
// Implementing a Singly Linked List

class StringNode {
private:
    string elem;
    StringNode* next;

    friend class StringLinkedList;
};

class StringLinkedList {
public:
    StringLinkedList(); // constructor
    ~StringLinkedList(); // destructor
    // const: member objects are immutable
    // https://www.cnblogs.com/flyinggod/p/7853082.html
    bool empty() const;
    const string& front() const;
    void addFront(const string& e);
    void removeFront();
private:
    StringNode* head;
};

StringLinkedList::StringLinkedList()
    // : is used for Member Initialization List
    // https://blog.csdn.net/lws123253/article/details/80368047
    : head(NULL) {}

StringLinkedList::~StringLinkedList() {
    while (!empty()) removeFront();
}

bool StringLinkedList::empty() const {
    return head == NULL;
}

const string& StringLinkedList::front() const {
    return head->elem;
}

void StringLinkedList::addFront(const string& e) {
    StringNode* v = new StringNode;
    // new is used to allocate memory for object
    // https://www.cnblogs.com/chris-cp/p/3578976.html
    v->elem = e;
    v->next = head;
    head = v;
}

void StringLinkedList::removeFront() {
    StringNode* old = head;
    head = old->next;
    delete old;
}

//=================================

// =========================================
// Implementing a Generic Singly Linked List

template <typename E>
class SNode {
private:
    E elem;
    SNode<E>* next;

    friend class SLinkedList<E>;
};

template <typename E>
class SLinkedList {
public:
    SLinkedList(); // constructor
    ~SLinkedList(); // destructor
    // const: member objects are immutable
    // https://www.cnblogs.com/flyinggod/p/7853082.html
    bool empty() const;
    const E& front() const;
    void addFront(const E& e);
    void removeFront();
private:
    SNode<E>* head;
};

template <typename E>
SLinkedList<E>::SLinkedList()
    // : is used for Member Initialization List
    // https://blog.csdn.net/lws123253/article/details/80368047
    : head(NULL) {}

template <typename E>
SLinkedList<E>::~SLinkedList() {
    while (!empty()) removeFront();
}

template <typename E>
bool SLinkedList<E>::empty() const {
    return head == NULL;
}

template <typename E>
const E& SLinkedList<E>::front() const {
    return head->elem;
}

template <typename E>
void SLinkedList<E>::addFront(const E& e) {
    SNode<E>* v = new SNode<E>;
    // new is used to allocate memory for object
    // https://www.cnblogs.com/chris-cp/p/3578976.html
    v->elem = e;
    v->next = head;
    head = v;
}

template <typename E>
void SLinkedList<E>::removeFront() {
    SNode<E>* old = head;
    head = old->next;
    delete old;
}

// =========================================

// =================================
// Implementing a Doubly Linked List

typedef string Elem;
// defines the element type
class DNode {
private:
    Elem elem;
    DNode* prev;
    DNode* next;
    friend class DLinkedList;
};

class DLinkedList {
public:
    DLinkedList();
    ~DLinkedList();
    bool empty() const;
    const Elem& front() const;
    const Elem& back() const;
    void addFront(const Elem& e);
    void addBack(const Elem& e);
    void removeFront();
    void removeBack();
private:
    DNode* header;
    DNode* trailer;
protected: // local utilities
    // can be internally used by the class & its subclasses
    void add(DNode* v, const Elem& e);
    void remove(DNode* v);
};

DLinkedList::DLinkedList() {
    header = new DNode;
    trailer = new DNode;
    header->next = trailer;
    trailer->prev = header;
}

DLinkedList::~DLinkedList() {
    while (!empty()) removeFront();
    delete header;
    delete trailer;
}

bool DLinkedList::empty() const {
    return (header->next == trailer);
}

const Elem& DLinkedList::front() const {
    return header->next->elem;
}

const Elem& DLinkedList::back() const {
    return trailer->prev->elem;
}

void DLinkedList::add(DNode* v, const Elem& e) {
    DNode* u = new DNode;
    u->elem = e;
    u->next = v;
    u->prev = v->prev;
    v->prev->next = v->prev = u;
}

void DLinkedList::addFront(const Elem& e) {
    add(header->next, e);
}

void DLinkedList::addBack(const Elem& e) {
    add(trailer, e);
}

void DLinkedList::remove(DNode* v) {
    DNode* u = v->prev;
    DNode* w = v->next;
    u->next = w;
    w->prev = u;
    delete v;
}

void DLinkedList::removeFront() {
    remove(header->next);
}

void DLinkedList::removeBack() {
    remove(trailer->prev);
}

// =================================

// =====================================
// Implementing a Circularly Linked List

typedef string Elem;
class CNode {
private:
    Elem elem;
    CNode* next;

    friend class CircleList;
};

class CircleList {
public:
    CircleList();
    ~CircleList();
    bool empty() const;
    const Elem& front() const;
    const Elem& back() const;
    void advance(); // advance cursor
    void add(const Elem& e);
    void remove();
private:
    CNode* cursor;
};

CircleList::CircleList()
    : cursor(NULL) {}

CircleList::~CircleList() {
    while (!empty()) remove();
}

bool CircleList::empty() const {
    return cursor == NULL;
}

const Elem& CircleList::front() const {
    return cursor->next->elem;
}

const Elem& CircleList::back() const {
    return cursor->elem;
}

void CircleList::advance() {
    cursor = cursor->next;
}

void CircleList::add(const Elem& e) {
    CNode* v = new CNode;
    v->elem = e;
    if (cursor == NULL) {
        v->next = v;
        cursor = v;
    }
    else {
        v->next = cursor->next;
        cursor->next = v;
    }
}

void CircleList::remove() {
    CNode* old = cursor->next;
    if (old == cursor) {
        cursor = NULL;
    }
    else {
        cursor->next = old->next;
    }
    delete old;
}

// =====================================

// =======================
// Reversing a Linked List

void listReverse(DLinkedList& L) {
    DLinkedList T;
    while(!L.empty()) {
        string s = L.front();
        L.removeFront();
        T.addFront(s);
    }
    while(!T.empty()) {
        string s = T.front();
        T.removeFront();
        L.addBack(s);
    }
}

// =======================
