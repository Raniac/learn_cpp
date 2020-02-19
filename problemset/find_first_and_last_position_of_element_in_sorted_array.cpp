#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res = {-1, -1};
        if (n == 0) return res;
        helper(nums, target, 0, n-1, res);
        return res;
    }
    void helper(vector<int>& nums, int target, int l, int r, vector<int>& res) {
        if (target > nums[r] || target < nums[l]) return;
        if (target == nums[l] || target == nums[r]) {
            if (target == nums[l]) res[0] = (res[0] == -1 ? l : min(l, res[0]));
            if (target == nums[r]) res[1] = (res[1] == -1 ? r : max(r, res[1]));
        }
        if (l == r) return;
        helper(nums, target, l, l + (r - l) / 2, res);
        helper(nums, target, l + (r - l) / 2 + 1, r, res);
    }
};

int main() {
    vector<int> nums = {5,7,7,8,8,8,8,8,8,8,10};
    int target = 7;
    vector<int> res;
    Solution sol;
    res = sol.searchRange(nums, target);
    for (auto c : res) {
        cout << c << ' ';
    }
    cout << endl;
    return 0;
}