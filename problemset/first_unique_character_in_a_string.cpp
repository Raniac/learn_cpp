#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> map;
        for (auto &c : s) ++map[c]; // increase count of char
        for (auto &c : s) if (map[c] == 1) return s.find_first_of(c);
        return -1;
    }
};

int main() {
    Solution sol;
    string s = "leetcode";
    int res;
    res = sol.firstUniqChar(s);
    cout << res << endl;
    return 0;
}