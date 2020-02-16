#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = 1;
        }
        res[0] = 0;
        res[1] = 0;
        // upper bound is n**0.5 + 1
        // since the starting position of k is j*j
        // because the ones less than j*j
        // is cancelled out by previous primes
        for (int j = 2; j <= (int) sqrt((float)n); j++) {
            if (res[j] == 1) {
                for (int k = j*j; k < n; k += j) {
                    res[k] = 0;
                }
            }
        }
        int s = 0;
        for (int l = 0; l < n; l++) {
            s += res[l];
        }
        return s;
    }
};

int main() {
    Solution sol;
    int n = 3;
    int res;
    res = sol.countPrimes(n);
    cout << res << endl;
    return 0;
}