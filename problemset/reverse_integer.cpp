#include <iostream>

using namespace std;

/*
Given a 32-bit signed integer, reverse digits of an integer.
*/

class Solution {
public:
    int reverse(int x) {
        if (x < 10 && x > -10) return x;
        long res = 0;
        while (x != 0) {
            res = res * 10 + x % 10;
            x /= 10;
            if (res < -2147483648 || res > 2147483647) {
                return 0;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    int x = -123;
    int res;
    res = sol.reverse(x);
    cout << res << endl;
    return 0;
}