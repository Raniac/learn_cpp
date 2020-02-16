#include <iostream>
#include <map>
#include <math.h>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        map<char, int> dict;
        string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int d = 1;
        for (auto &c : alphabet) {
            dict[c] = d;
            d++;
        }
        int res = 0;
        int n = s.size();
        for (auto &c : s) {
            res += dict[c] * pow(26, n - 1);
            n--;
        }
        return res;
    }
};

class BestSolution {
public:
    int titleToNumber(string s) {
        long long res = 0;
        for(auto c : s) {
            res = res * 26 + c - 'A' + 1;
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s = "ZY";
    int res;
    res = sol.titleToNumber(s);
    cout << res << endl;
    return 0;
}