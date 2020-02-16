#include <iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while (n >= 5) {
            count += n / 5;
            n /= 5;
        }
        return count;
    }
};

int main() {
    Solution sol;
    int n = 20;
    int res;
    res = sol.trailingZeroes(n);
    cout << res << endl;
    return 0;
}