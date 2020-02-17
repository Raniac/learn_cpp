#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int res;
        vector<int> stack;
        for (auto t : tokens) {
            if (t == "+") {
                int opr1 = stack.back();
                stack.pop_back();
                int opr2 = stack.back();
                stack.pop_back();
                res = opr2 + opr1;
                stack.push_back(res);
            }
            else if (t == "-") {
                int opr1 = stack.back();
                stack.pop_back();
                int opr2 = stack.back();
                stack.pop_back();
                res = opr2 - opr1;
                stack.push_back(res);
            }
            else if (t == "*") {
                int opr1 = stack.back();
                stack.pop_back();
                int opr2 = stack.back();
                stack.pop_back();
                res = opr2 * opr1;
                stack.push_back(res);
            }
            else if (t == "/") {
                int opr1 = stack.back();
                stack.pop_back();
                int opr2 = stack.back();
                stack.pop_back();
                res = opr2 / opr1;
                stack.push_back(res);
            }
            else stack.push_back(stoi(t));
        }
        return stack.back();
    }
};

int main() {
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    int res;
    Solution sol;
    res = sol.evalRPN(tokens);
    cout << res << endl;
    return 0;
}