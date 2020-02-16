#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 0;
        int n = digits.size();
        int sum;
        vector<int> res;
        digits[n - 1] += 1;
        for (int i = n-1; i >= 0; i--) {
            sum = (digits[i] + c);
            digits[i] = sum % 10;
            c = sum / 10;
        }
        if (c > 0) {
            res.emplace_back(c);
        }
        for (int j = 0; j < n; j++) {
            res.emplace_back(digits[j]);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> digits = {9,9,9,9};
    vector<int> res;
    res = sol.plusOne(digits);
    for (auto &d : res) {
        cout << d << endl;
    }
    return 0;
}