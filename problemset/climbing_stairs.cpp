#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n < 2) return 1;
        vector<int> dp(n+1, 1);
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

int main() {
    int n = 5;
    int res;
    Solution sol;
    res = sol.climbStairs(n);
    cout << res << endl;
    return 0;
}