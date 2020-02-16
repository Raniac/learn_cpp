#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") return 0;
        int len_haystack = haystack.size();
        int len_needle = needle.size();
        int res = -1;
        for (int i = 0; i < len_haystack - len_needle + 1; i++) {
            if (haystack[i] == needle[0]) {
                res = i;
                for (int j = 1; j < len_needle; j++){
                    if (haystack[i+j] != needle[j]) {
                        res = -1;
                        break;
                    }
                }
                if (res != -1) return res;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    string haystack = "hellaooad";
    string needle = "ad";
    int res;
    res = sol.strStr(haystack, needle);
    cout << res << endl;
    return 0;
}