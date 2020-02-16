#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> perm;
        vector<int> used(nums.size(), 0);
        dfs(res, perm, used, nums);
        return res;
    }

    void dfs(vector<vector<int>>& res, vector<int>& perm, vector<int>& used, vector<int>& nums)
    {
        if (perm.size() == nums.size()) {
            res.push_back(perm);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] != 0) continue;
            else {
                perm.push_back(nums[i]);
                used[i] = 1;

                dfs(res, perm, used, nums);

                perm.pop_back();
                used[i] = 0;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {};
    vector<vector<int> > res;
    res = sol.permute(nums);
    cout << res.size() << endl;
    return 0;
}