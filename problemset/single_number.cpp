#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
交换律：a ^ b ^ c <=> a ^ c ^ b
任何数于0异或为任何数 0 ^ n => n
相同的数异或为0: n ^ n => 0
var a = [2,3,2,4,4]
2 ^ 3 ^ 2 ^ 4 ^ 4 等价于 2 ^ 2 ^ 4 ^ 4 ^ 3 => 0 ^ 0 ^3 => 3
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        for (auto &n : nums)
            a = a ^ n;
        return a;
    }
};

int main() {
    vector<int> nums = {2,2,1};
    int res;
    Solution sol;
    res = sol.singleNumber(nums);
    cout << res << endl;
    return 0;
}