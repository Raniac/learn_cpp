#include <iostream>

using namespace std;

/*
Given an integer, write a function to determine if it is a power of three.
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467%n == 0;
    }
};

int main() {
    Solution sol;
    int n = 57;
    bool res;
    res = sol.isPowerOfThree(n);
    cout << res << endl;
    return 0;
}