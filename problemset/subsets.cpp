#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > res;
        res.push_back({});
        int n = nums.size();
        vector<int> tmp;
        // 直接遍历，遇到一个数就把所有子集加上该数组成新的子集，遍历完毕即是所有子集
        for (int i = 0; i < n; i++) {
            int m = res.size();
            for (int j = 0; j < m; j++) {
                tmp = res[j];
                tmp.push_back(nums[i]);
                res.push_back(tmp);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,3};
    vector<vector<int> > res;
    res = sol.subsets(nums);
    cout << res.size() << endl;
    return 0;
}