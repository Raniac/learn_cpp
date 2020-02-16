#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            char tmp;
            tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
            l++;
            r--;
        }
    }
};

int main() {
    Solution sol;
    vector<char> s = {};
    sol.reverseString(s);
    for (auto &c : s) {
        cout << c << endl;
    }
    return 0;
}