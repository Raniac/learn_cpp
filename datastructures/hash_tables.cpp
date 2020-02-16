#include <iostream>
#include <vector>
#include <list>
#include "maps.cpp"

using namespace std;

template <typename K, typename V, typename H>
class HashMap {
public:
    typedef Entry<const K, V> Entry;
    class Iterator {
        private:
        EItor ent;
        BItor bkt;
        const BktArray* ba;
        public:
        Iterator(const BktArray& a, const BItor& b, const EItor& q = EItor()) : ent(q), bkt(b), ba(&a) {}
        Entry& operator*() const { return *ent; }
        bool operator==(const Iterator& p) const {
            if (ba != p.ba || bkt != p.bkt) return false;
            else if (bkt == ba->end()) return true;
            else return (ent == p.ent);
        }
        Iterator& operator++() {
            ++ent;
            if (endOfBkt(*this)) {
                ++bkt;
                while (bkt != ba.end() && bkt->empty()) ++bkt;
                if (bkt == ba.end()) return *this;
                ent = bkt->begin();
            }
            return *this;
        }
        friend class HashMap;
    };
    HashMap(int capacity = 100) : n(0), B(capacity) {}
    int size() const { return n; }
    bool empty() const { return size() == 0; }
    Iterator find(const K& k) {
        Iterator p = finder(k);
        if (endOfBkt(p)) return end();
        else return p;
    }
    Iterator put(const K& k, const V& v) {
        Iterator p = finder(k);
        if (endOfBkt(p)) {
            return inserter(p, Entry(k, v));
        }
        else {
            p.ent->setValue(v);
            return p;
        }
    }
    void erase(const K& k) {
        Iterator p = finder(k);
        // if (endOfBkt) throw Exception();
        eraser(p);
    }
    void erase(const Iterator& p) {
        eraser(p);
    }
    Iterator begin() {
        if (empty()) return end();
        BItor bkt = B.begin();
        while (bkt->empty()) ++bkt;
        return Iterator(B, bkt, bkt->begin());
    }
    Iterator end() { return Iterator(B, B.end()); }
    Iterator finder(const K& k) {
        int i = hash(k) % B.size();
        BItor bkt = B.begin() + i;
        Iterator p(B, bkt, bkt->begin());
        while (!endOfBkt(p) && (*p).key() != k) nextEntry(p);
        return p; 
    }
    Iterator inserter(const Iterator& p, const Entry& e) {
        EItor ins = p.bkt->insert(p.ent, e);
        n++;
        return Iterator(B, p.bkt, ins);
    }
    void eraser(const Iterator& p) {
        p.bkt->erase(p.ent);
        n--;
    }
    typedef typename BktArray::iterator BItor;
    typedef typename Bucket::iterator EItor;
    static void nextEntry(Iterator& p) { ++p.ent; }
    static bool endOfBkt(const Iterator& p) { return p.ent == p.bkt->end(); }
protected:
    typedef list<Entry> Bucket;
    typedef vector<Bucket> BktArray;
private:
    int n;
    H hash; // the hash comparator
    BktArray B;
};
