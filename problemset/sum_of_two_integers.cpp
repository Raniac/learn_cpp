#include <iostream>

using namespace std;

/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
*/

class Solution {
public:
    int getSum(int a, int b) {
        // a ^ b 是无进位的相加
        // a & b 得到每一位的进位
        // 让无进位相加的结果与进位不断的异或
        // 直到进位为0
        while (b) {
            auto c = ((unsigned int)a & b) << 1;
            a = a ^ b;
            b = c;
        }
        return a;
    }
};

int main() {
    Solution sol;
    int a = 1;
    int b = 5;
    int res;
    res = sol.getSum(a, b);
    cout << res << endl;
    return 0; 
}