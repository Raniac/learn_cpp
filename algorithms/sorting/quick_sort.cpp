#include <vector>

using namespace std;

template <typename E, typename C>
void quickSort(vector<E>& S, const C& less) {
    if (S.size() == 1) return;
    quickSortStep(S, 0, S.size() - 1, less);
}

template <typename E, typename C>
void quickSortStep(vector<E>& S, int a, int b, const C& less) {
    if (a >= b) return;
    E pivot = S[b];
    int l = a;
    int r = b - 1;
    while (l <= r) { // move smaller-than-pivot to the left and vice versa
        while (l <= r && !less(pivot, S[l])) l++; // scan right till larger
        while (l <= r && !less(S[r], pivot)) r--; // scan left till smaller
        if (l < r) swap(s[l], s[r]);
    } // untill indices l and r cross
    swap(S[l], S[b]); // move pivot to the middle
    quickSortStep(S, a, l-1, less); // do quick sort for both sides
    quickSortStep(S, l+1, b, less);
}
