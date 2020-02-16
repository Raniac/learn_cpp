#include <iostream>
 
using namespace std;

/*
Implement int sqrt(int x).
Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
*/

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) {
            return x;
        }
        // Newton's Method
        long root = x; // in case of signed integer overflow
        while (root > x / root) {
            root = (root + x / root) / 2;
        }
        return root;
    }
};

int main() {
    Solution sol;
    int x = 2147483647;
    int res;
    res = sol.mySqrt(x);
    cout << res << endl;
    return 0;
}