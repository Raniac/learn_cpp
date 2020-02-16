#include <iostream>
#include <string>
#include <map>

using namespace std;

// ===================
// A C++ Map Interface

template <typename K, typename V>
class Entry {
public:
    Entry(const K& k = K(), const V& v = V()) : _key(k), _value(v) {}
    const K& key() const {
        return _key;
    }
    const V& value() const {
        return _value;
    }
    void setKey(const K& k) {
        _key = k;
    }
    void setValue(const V& v) {
        _value = v;
    }
private:
    K _key;
    V _value;
};

template <typename K, typename V>
class Map {
public:
    class Entry;
    class Iterator;
    int size() const;
    bool empty() const;
    Iterator find(const K& k) const;
    Iterator put(const K& k, const V& v) const;
    void erase(const Iterator& p);
    Iterator begin();
    Iterator end();
};

// ===================

// =================
// The STL map Class

map<string, int> myMap;
map<string, int>::iterator p;

// =================

int main() {
    myMap.insert(pair<string, int>("Rob", 28));
    p = myMap.find("Rob");
    myMap.erase(p);
    return 0;
}
