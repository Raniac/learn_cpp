#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        // preprocessing for Manacher's Algorithm
        string t = "";
        for (auto &c : s) {
            t += "#";
            t += c;
        }
        t += "#";

        // in order to avoid repeated calculation, use Manacher's Algorithm
        vector<int> radius(t.size(), 0); // radius of palindrom centered i
        int maxRight = 0; // right-most position of palindrom
        int center = 0; // and corresponing center
        int resLen = 0, resCenter = 0; // results

        for (int i = 0; i < t.size(); i++) {
            radius[i] = maxRight > i ? min(radius[2 * center - i], maxRight - i) : 1;
            while (i - radius[i] >= 0 && i + radius[i] < t.size() && t[i + radius[i]] == t[i - radius[i]])
                radius[i] += 1; // update radius of palindrom

            // update right bounder and corresponding center
            // of the longest palindromic substring
            if (maxRight < i + radius[i] -1) {
                maxRight = i + radius[i] -1;
                center = i;
            }

            // update result
            if (resLen < radius[i]) {
                resLen = radius[i];
                resCenter = i;
            }
        }
        return s.substr((resCenter - resLen + 1) / 2 , resLen - 1);
    }
};

int main() {
    string s = "babad";
    string res;
    Solution sol;
    res = sol.longestPalindrome(s);
    cout << res << endl;
    return 0;
}
