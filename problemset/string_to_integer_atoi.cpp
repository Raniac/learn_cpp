#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int sign = 1;
        int cnt = 0;
        map<char, int> nums = {
            {'0', 0},
            {'1', 1},
            {'2', 2},
            {'3', 3},
            {'4', 4},
            {'5', 5},
            {'6', 6},
            {'7', 7},
            {'8', 8},
            {'9', 9}
        };
        long res = 0;
        for (auto &c : str) {
            if ((c == ' ') && cnt == 0) continue;
            else if ((c == '+' || c == '-') && cnt == 0) {
                switch(c) {
                case '+':
                    sign = 1;
                    cnt++;
                    break;
                case '-':
                    sign = -1;
                    cnt++;
                    break;
                }
            }
            else if (c >= 48 && c <= 57) {
                res = res * 10 + nums[c];
                if ((res > 2147483648 && sign == -1) || res > 2147483647) {
                    res = (sign == -1 ? -2147483648 : 2147483647);
                    break;
                }
                cnt++;
            }
            else break;
        }
        return sign * res;
    }
};

int main() {
    Solution sol;
    string str = "++42";
    int res;
    res = sol.myAtoi(str);
    cout << res << endl;
    return 0;
}