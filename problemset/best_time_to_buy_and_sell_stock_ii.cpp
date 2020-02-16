#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;
        int profit = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            int diff = prices[i+1] - prices[i];
            if (diff > 0) {
                profit += diff;
            }
        }
        return profit;
    }
};

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    int res;
    Solution sol;
    res = sol.maxProfit(prices);
    cout << res << endl;
    return 0;
}