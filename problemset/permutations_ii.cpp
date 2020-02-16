#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> perm;
        vector<int> used(nums.size(), 0);
        dfs(res, nums, perm, used);
        return res;
    }
    void dfs(vector<vector<int> >& res, vector<int>& nums, vector<int>& perm, vector<int>& used) {
        if (perm.size() == nums.size()) {
            res.push_back(perm);
            return;
        }
        vector<int> dups(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] != 0 || dups[i] != 0) continue;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    dups[j] = 1;
                }
            }
            used[i] = 1;
            perm.push_back(nums[i]);
            dfs(res, nums, perm, used);
            used[i] = 0;
            perm.pop_back();
        }
        return;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,1,2};
    vector<vector<int>> res;
    res = sol.permuteUnique(nums);
    cout << res.size() << endl;
    return 0;
}