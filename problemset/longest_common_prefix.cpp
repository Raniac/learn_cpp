#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].find(prefix) != 0) {
                prefix.erase(prefix.size()-1);
            }
            if (prefix.size() == 0) return "";
        }
        return prefix;
    }
};

int main() {
    Solution sol;
    string res;
    vector<string> strs = {"a","flow","flight"};
    res = sol.longestCommonPrefix(strs);
    cout << res << endl;
    return 0;
}