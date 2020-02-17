#include <list>
#include <vector>

using namespace std;

// =========================
// List-Based Implementation

template <typename E, typename C>
void mergeSort(list<E>& S, const C& less) {
    typedef typename list<E>::iterator Itor;
    int n = S.size();
    if (n <= 1) return;
    list<E> S1, S2;
    Itor p = S.begin();
    for (int i = 0; i < n / 2; i++) S1.push_back(*p++);
    for (int i = n / 2; i < n; i++) S2.push_back(*p++);
    S.clear();
    mergeSort(S1, less);
    mergeSort(S2, less);
    merge(S1, S2, S, less);
}

template <typename E, typename C>
void merge(list<E>& S1, list<E>& S2, list<E>& S, const C& less) {
    typedef typename list<E>::iterator Itor;
    Itor p1 = S1.begin();
    Itor p2 = S2.begin();
    while (p1 != S1.end() && p2 != S2.end()) {
        if (less(*p1, *p2)) S.push_back(*p1++);
        else S.push_back(*p2++);
    }
    while (p1 != S1.end()) {
        S.push(*p1++);
    }
    while (p2 != S2.end()) {
        S.push(*p2++);
    }
}

// =========================

// ===========================
// Vector-Based Implementation

/*
Recurrence Relation
*/

template <typename E, typename C>
void mergeSort(vector<E>& S, const C& less) {
    typedef vector<E> vect;
    int n = S.size();
    vect v1(S);
    vect* in = &v1;
    vect v2(n);
    vect* out = &v2;
    for (int m = 1; m < n; m *= 2) {
        for (int b = 0; b < n; b += 2*m) {
            merge(*in, *out, less, b, m);
        }
        swap(in, out);
    }
    S = *in;
}

template <typename E, typename C>
void merge(vector<E>& in, vector<E>& out, const C& less, int b, int m) {
    int i = b;
    int j = b + m;
    int n = in.size();
    int e1 = min(b + m, n);
    int e2 = min(b + m * 2, n);
    int k = b;
    while ((i < e1) && (j < e2)) {
        if (!less(in[j], in[i])) out[k++] = in[i++];
        else out[k++] = in[j++];
    }
    while (i < e1) out[k++] = in[i++];
    while (j < e2) out[k++] = in[j++];
}

// ===========================
