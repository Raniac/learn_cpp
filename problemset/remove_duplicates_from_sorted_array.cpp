#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // No actual removement is required
        // As long as the first N elements are unique
        int n = nums.size();
        if (n < 2) {
            return n;
        }
        int j = 0;
        for (int i = 1; i < n; i++) {
            if (nums[j] != nums[i]) nums[++j] = nums[i];
        }
        return ++j;
    }
};

int main() {
    vector<int> nums = {1,2,3,3,4,5};
    int res;
    Solution sol;
    res = sol.removeDuplicates(nums);
    for (int &num : nums) {
        cout << num << endl;
    }
    cout << res << endl;
    return 0;
}