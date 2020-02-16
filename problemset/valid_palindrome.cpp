#include <iostream>
#include <string>

using namespace std;

/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        string ps;
        for (auto &c : s) {
            if (c >= 48 && c <= 57) ps += c;
            if (c >= 65 && c <= 90) ps += c+32;
            if (c >= 97 && c <= 122) ps += c;
        }
        int l = 0;
        int r = ps.size() - 1;
        while (l < r) {
            if (ps[l] != ps[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};

int main() {
    Solution sol;
    string s = "race a car";
    bool res;
    res = sol.isPalindrome(s);
    cout << res << endl;
    return 0;
}
